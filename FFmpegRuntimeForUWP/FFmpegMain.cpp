#include "pch.h"
#include "FFmpegMain.h"
#include "utils.h"

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
std::string FFmpegMain::getConfiguration()
{
	const char* conf = avcodec_configuration();
	return conf;
}

//获取版本信息
winrt::hstring FFmpegMain::getVersionInfo()
{
	std::string versionInfo = "RuntimeComponentVersion 2019.3.12";
	return strToHstr(versionInfo);
}

FFmpegMain FFmpegMain::getFMInstance()
{
	return FFmpegMain();
}
