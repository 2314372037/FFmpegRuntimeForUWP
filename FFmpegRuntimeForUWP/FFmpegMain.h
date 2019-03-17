#pragma once

#include "FFmpegMain.g.h"



namespace winrt::FFmpegRuntimeForUWP::implementation
{
	struct FFmpegMain : FFmpegMainT<FFmpegMain>
	{
		FFmpegMain();
		~FFmpegMain();

		static std::string getConfiguration();
		static winrt::hstring getVersionInfo();
		static FFmpegMain getFMInstance();

		void init();

	private :
		unsigned char* fileStreamBuffer;
		IStream *fileStreamData;
		AVIOContext *avIOCtx;
	};
}

namespace winrt::FFmpegRuntimeForUWP::factory_implementation
{
	struct FFmpegMain : FFmpegMainT<FFmpegMain,implementation::FFmpegMain>
	{
	};
}
