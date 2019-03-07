#pragma once

using namespace Platform;

namespace FFmpegRuntimeForUWP
{
    public ref class ffmpegMain sealed
    {
	private:
		ffmpegMain();

    public:
		static String^ getVersionInfo();
		virtual ~ffmpegMain();
	};
}
