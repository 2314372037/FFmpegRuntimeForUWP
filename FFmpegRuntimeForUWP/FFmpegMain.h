#pragma once

#include "FFmpegMain.g.h"

namespace winrt::FFmpegRuntimeForUWP::implementation
{
	class FFmpegMain
	{
	public:
		FFmpegMain();
		~FFmpegMain();

		static void getConfiguration();
		static void getVersionInfo();

	private:
		
	};
}
