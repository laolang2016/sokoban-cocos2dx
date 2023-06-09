#ifndef _COMMON_UTIL_H_
#define _COMMON_UTIL_H_

#include <string>

class CommonUtil
{
private:
	CommonUtil() noexcept;
public:
	/// <summary>
	/// 解决
	/// </summary>
	/// <param name="strGBK"></param>
	/// <returns></returns>
	static std::string GBKToUTF8(const std::string& strGBK);
	static std::string GetDefaultFontPath();
};

#endif // !_COMMON_UTIL_H_
