#include "wayneStrUtil.hpp"

namespace wayne
{
	namespace strUtil
	{
		std::string subStrReplaceAll(const std::string mainStr, const std::string targetSubStr, const std::string replaceToSubStr)
		{
			return std::regex_replace(mainStr, std::regex(targetSubStr), replaceToSubStr);
		}

		void subStrReplaceAllDirect(std::string* const mainStr, const std::string targetSubStr, const std::string replaceToSubStr)
		{
			*mainStr = std::regex_replace(*mainStr, std::regex(targetSubStr), replaceToSubStr);
		}

		char* subStrReplaceAll(const char* mainStr, const char* targetSubStr, const char* replaceToSubStr)
		{
			char* toReturn = new char[std::strlen(std::regex_replace(mainStr, std::regex(targetSubStr), (const_cast<char*>(replaceToSubStr))).c_str())];
			strncpy(toReturn, std::regex_replace(mainStr, std::regex(targetSubStr), (const_cast<char*>(replaceToSubStr))).c_str(), std::strlen(std::regex_replace(mainStr, std::regex(targetSubStr), (const_cast<char*>(replaceToSubStr))).c_str()));
			return toReturn;
		}

		void subStrReplaceAllDirect(char* &mainStr, const char* targetSubStr, const char* replaceToSubStr)
		{
			char *toReturn = new char[strlen(std::regex_replace(mainStr, std::regex(targetSubStr), (const_cast<char*>(replaceToSubStr))).c_str())];
			strncpy(toReturn, std::regex_replace(mainStr, std::regex(targetSubStr), (const_cast<char*>(replaceToSubStr))).c_str(), std::strlen(std::regex_replace(mainStr, std::regex(targetSubStr), (const_cast<char*>(replaceToSubStr))).c_str()));
			mainStr = new char[strlen(std::regex_replace(mainStr, std::regex(targetSubStr), (const_cast<char*>(replaceToSubStr))).c_str())];
			strncpy(mainStr, toReturn, strlen(toReturn));
			delete[] toReturn;
		}

		int subStrOccuranceCount(const std::string mainStr, const std::string targetSubStr)
		{
			int occurance = 0;
			for (int i = 0; i < mainStr.length() - targetSubStr.length(); i++)
			{
				if (mainStr.substr(i, targetSubStr.length()) == targetSubStr)
				{
					occurance++;
				}
			}
			return occurance;
		}

		int subStrOccuranceCount(const std::string* mainStr, const std::string targetSubStr)
		{
			int occurance = 0;
			for (int i = 0; i < mainStr->length() - targetSubStr.length(); i++)
			{
				if (mainStr->substr(i, targetSubStr.length()) == targetSubStr)
				{
					occurance++;
				}
			}
			return occurance;
		}

		int subStrOccuranceCount(const char* mainStr, const char* targetSubStr)
		{
			std::string strMainStr(mainStr);
			std::string strTargetSubStr(targetSubStr);
			return subStrOccuranceCount(strMainStr, strTargetSubStr);
		}

		int subStrOccuranceIndex(const std::string mainStr, const std::string targetSubStr, const int thOccurance)
		{
			if (thOccurance > subStrOccuranceCount(mainStr, targetSubStr))
			{
				return -1;
				/* This means that the *th Occurance cannot be reached */
			} else {
				int occurance = 0;
				for (int i = 0; i < mainStr.length() - targetSubStr.length(); i++)
				{
					if (mainStr.substr(i, targetSubStr.length()) == targetSubStr)
					{
						occurance++;
						if (occurance == thOccurance)
						{
							return i;
						}
					}
				}
			}
			return -1; /*Something went wrong if any of them really reached here.*/
		}

		int subStrOccuranceIndex(const std::string* mainStr, const std::string targetSubStr, const int thOccurance)
		{
			if (thOccurance > subStrOccuranceCount(mainStr, targetSubStr))
			{
				return -1;
			} else {
				int occurance = 0;
				for (int i = 0; i < mainStr->length() - targetSubStr.length(); i++)
				{
					if (mainStr->substr(i, targetSubStr.length()) == targetSubStr)
					{
						occurance++;
						if (occurance == thOccurance)
						{
							return i;
						}
					}
				}
			}
			return -1; /*Something went wrong if any of them really reached here.*/
		}

		int subStrOccuranceIndex(const char* mainStr, const char* targetSubStr, const int thOccurance)
		{
			std::string strMainStr(mainStr);
			std::string strTargetSubStr(targetSubStr);
			return subStrOccuranceIndex(strMainStr, strTargetSubStr, thOccurance);
		}
	}
}
