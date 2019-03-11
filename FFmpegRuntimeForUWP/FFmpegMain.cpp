#include "pch.h"
#include "FFmpegMain.h"

extern "C"
{
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
}

using namespace winrt::FFmpegRuntimeForUWP::implementation;

//我需要更多cppwinrt教程(╯‵□′)╯︵┻━┻

FFmpegMain::FFmpegMain()
{
	wprintf_s(L"Hello World!\n");
}

FFmpegMain::~FFmpegMain()
{

}

//获取配置
void FFmpegMain::getConfiguration()
{
	const char* conf = avcodec_configuration();

}

//获取版本信息
void FFmpegMain::getVersionInfo()
{

}