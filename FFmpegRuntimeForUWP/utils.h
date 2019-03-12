#pragma once

//winrt::hstring转到std::string
static std::string hstrToStr(const winrt::hstring hstr);

//std::string转到winrt::hstring
static winrt::hstring strToHstr(const std::string str);
