#include "pch.h"
#include "FFmpegMain.h"
#include "utils.h"

#include <shcore.h>
#include <combaseapi.h>


extern "C"
{
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"

}


using namespace winrt::FFmpegRuntimeForUWP::implementation;

//读取文件流时缓冲区的大小
const int FILESTREAMBUFFERSZ = 16384;


//我需要更多cppwinrt教程(╯‵□′)╯︵┻━┻

FFmpegMain::FFmpegMain()
{
	wprintf_s(L"Hello World!\n");
}

FFmpegMain::~FFmpegMain()
{
	wprintf_s(L"FFmpegMain销毁!\n");
}

// Static function to read file stream and pass data to FFmpeg. Credit to Philipp Sch http://www.codeproject.com/Tips/489450/Creating-Custom-FFmpeg-IO-Context
static int FileStreamRead(void* ptr, uint8_t* buf, int bufSize)
{
	IStream* pStream = reinterpret_cast<IStream*>(ptr);
	ULONG bytesRead = 0;
	HRESULT hr = pStream->Read(buf, bufSize, &bytesRead);

	if (FAILED(hr))
	{
		return -1;
	}

	// If we succeed but don't have any bytes, assume end of file
	if (bytesRead == 0)
	{
		return AVERROR_EOF;  // Let FFmpeg know that we have reached eof
	}

	return bytesRead;
}

// Static function to seek in file stream. Credit to Philipp Sch http://www.codeproject.com/Tips/489450/Creating-Custom-FFmpeg-IO-Context
static int64_t FileStreamSeek(void* ptr, int64_t pos, int whence)
{
	IStream* pStream = reinterpret_cast<IStream*>(ptr);
	LARGE_INTEGER in;
	in.QuadPart = pos;
	ULARGE_INTEGER out = { 0 };

	if (FAILED(pStream->Seek(in, whence, &out)))
	{
		return -1;
	}

	return out.QuadPart; // Return the new position:
}

void FFmpegMain::init()
{
	//注册编解码器有关组件
	av_register_all();

	//将异步IRandomAccessStream转换到IStream同步流
	//CreateStreamOverRandomAccessStream(reinterpret_cast<IUnknown*>(stream), IID_PPV_ARGS(&fileStreamData));

	//为fileStreamBuffer分配内存空间 
	fileStreamBuffer = (unsigned char*)av_malloc(FILESTREAMBUFFERSZ);

	//参数4无限循环待验证, 为缓冲I/O分配并初始化AVIOContext,avio_context_free（）释放。
	avIOCtx = avio_alloc_context(fileStreamBuffer,FILESTREAMBUFFERSZ,0,fileStreamData,FileStreamRead,0,FileStreamSeek);
}

//获取配置
std::string FFmpegMain::getConfiguration()
{
	const char* conf = avcodec_configuration();
	return conf;
}

//获取版本信息
winrt::hstring FFmpegMain::getVersionInfo()
{
	std::string versionInfo = "RuntimeComponentVersion 2019.3.12";
	return utils::strToHstr(versionInfo);
}

FFmpegMain FFmpegMain::getFMInstance()
{
	return FFmpegMain();
}

