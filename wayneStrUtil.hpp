/*
 * wayneStrUtil.hpp
 *
 *  Created on: 2023年9月26日
 *      Author: weich
 */

#ifndef LIB_WAYNESTRUTIL_HPP_
#define LIB_WAYNESTRUTIL_HPP_

#include <string>
#include <cstring>
#include <algorithm>
#include <regex>

namespace wayne
{
	namespace strUtil
	{
		std::string subStrReplaceAll(const std::string mainStr, const std::string targetSubStr, const std::string replaceToSubStr);
		void subStrReplaceAllDirect(std::string* const mainStr, const std::string targetSubStr, const std::string replaceToSubStr);
		char* subStrReplaceAll(const char* mainStr, const char* targetSubStr, const char* replaceToSubStr);
		void subStrReplaceAllDirect(char* &mainStr, const char* targetSubStr, const char* replaceToSubStr);
		int subStrOccuranceCount(const char* mainStr, const char* targetSubStr);
		int subStrOccuranceCount(const std::string mainStr, const std::string targetSubStr);
		int subStrOccuranceCount(const std::string* mainStr, const std::string targetSubStr);
		int subStrOccuranceIndex(const std::string mainStr, const std::string targetSubStr, const int thOccurance);
		int subStrOccuranceIndex(const std::string* mainStr, const std::string targetSubStr, const int thOccurance);
		int subStrOccuranceIndex(const char* mainStr, const char* targetSubStr, const int thOccurance);
	}
}



#endif /* LIB_WAYNESTRUTIL_HPP_ */
