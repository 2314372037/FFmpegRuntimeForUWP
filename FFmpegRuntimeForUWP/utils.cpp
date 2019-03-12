#include "pch.h"
#include "utils.h"


//winrt::hstringת��std::string
std::string utils::hstrToStr(const winrt::hstring hstr)
{
	std::wstring ws{ hstr.begin() };
	return std::string(ws.begin(), ws.end());
}

//std::stringת��winrt::hstring
winrt::hstring utils::strToHstr(const std::string str)
{
	std::wstring wStr = std::wstring(str.begin(), str.end());
	const wchar_t *w_chars = wStr.c_str();
	return winrt::hstring(w_chars);
}
