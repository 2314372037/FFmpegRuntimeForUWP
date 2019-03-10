#include "pch.h"
#include "FFmpegMain.h"

extern "C"
{
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
}

namespace winrt::FFmpegRuntimeForUWP::implementation
{
    int32_t Class::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void Class::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }
}
