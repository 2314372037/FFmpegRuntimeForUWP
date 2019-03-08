#include "pch.h"
#include "ffmpegMain.h"

extern "C"
{

#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavfilter/avfilter.h>

}

using namespace FFmpegRuntimeForUWP;
using namespace Platform;

ffmpegMain::ffmpegMain()
{

}

ffmpegMain::~ffmpegMain()
{

}

//std::string转Platform::String
String^ stringToString(const std::string input)
{
	std::wstring w_str = std::wstring(input.begin(), input.end());
	const wchar_t* w_chars = w_str.c_str();
	return (ref new Platform::String(w_chars));
}

String ^ ffmpegMain::getConfiguration()
{
	const char *s=avcodec_configuration();
	return stringToString(s);
}

String^ ffmpegMain::getVersionInfo()
{
	String^ version = "RuntimeComponent Version 2019.3.7";
	return version;
}
