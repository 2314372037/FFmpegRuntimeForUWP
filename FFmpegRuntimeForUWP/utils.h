#pragma once

//winrt::hstringת��std::string
static std::string hstrToStr(const winrt::hstring hstr);

//std::stringת��winrt::hstring
static winrt::hstring strToHstr(const std::string str);
