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

		/* String Splitor */

		std::vector<std::string> splitString(std::string inputString, char splitor)
		{
			std::istringstream inputStream(inputString);
			std::string token;
			std::vector<std::string> splitResult;
			while (std::getline(inputStream, token, splitor))
			{
				splitResult.push_back(token);
			}
			return splitResult;
		}

		std::vector<std::string> splitString(const std::string* inputString, char splitor)
		{
			return splitString(const_cast<std::string*>(inputString), splitor);
		}

		std::vector<std::string> splitString(std::string* inputString, char splitor)
		{
			return splitString(*inputString, splitor);
		}

		std::vector<std::string> splitString(const char* inputString, char splitor)
		{
			return splitString(const_cast<char*>(inputString), splitor);
		}

		std::vector<std::string> splitString(char* inputString, char splitor)
		{
			std::string strInputString(inputString);
			return splitString(strInputString, splitor);
		}

		std::vector<char*> splitCString(std::string inputString, char splitor)
		{
			std::istringstream inputStream(inputString);
			std::string token;
			std::vector<char*> splitResult;
			while (std::getline(inputStream, token, splitor))
			{
				//splitResult.push_back(token);
				char* tokenChars = new char[token.length()];
				strncpy(tokenChars, token.c_str(), token.length());
				splitResult.push_back(tokenChars);
			}
			return splitResult;
		}

		std::vector<char*> splitCString(const std::string* inputString, char splitor)
		{
			return splitCString(const_cast<std::string*>(inputString), splitor);
		}

		std::vector<char*> splitCString(std::string* inputString, char splitor)
		{
			return splitCString(*inputString, splitor);
		}

		std::vector<char*> splitCString(const char* inputString, char splitor)
		{
			return splitCString(const_cast<char*>(inputString), splitor);
		}

		std::vector<char*> splitCString(char* inputString, char splitor)
		{
			std::string strInputString(inputString);
			return splitCString(strInputString, splitor);
		}

		std::string* splitStringStatic(std::string inputString, char splitor)
		{
			std::vector<std::string> returnedSplit = splitString(inputString, splitor);
			std::string* splitResult = new std::string[(int)returnedSplit.size()];
			for (ssize_t i = 0; i < returnedSplit.size(); i++)
			{
				splitResult[i] = returnedSplit[i];
			}
			return splitResult;
		}

		std::string* splitStringStatic(const std::string* inputString, char splitor)
		{
			return splitStringStatic(const_cast<std::string*>(inputString), splitor);
		}

		std::string* splitStringStatic(std::string* inputString, char splitor)
		{
			return splitStringStatic(*inputString, splitor);
		}

		std::string* splitStringStatic(const char* inputString, char splitor)
		{
			return splitStringStatic(const_cast<char*>(inputString), splitor);
		}

		std::string* splitStringStatic(char* inputString, char splitor)
		{
			std::string strInputString(inputString);
			return splitStringStatic(strInputString, splitor);
		}

		char** splitCStringStatic(std::string inputString, char splitor)
		{
			std::vector<std::string> returnedSplit = splitString(inputString, splitor);
			char** splitResult = new char*[returnedSplit.size()];
			for (ssize_t i = 0; i < returnedSplit.size(); i++)
			{
				splitResult[i] = new char[(returnedSplit[i]).length()];
				std::strncpy(splitResult[i], (returnedSplit[i]).c_str(), (returnedSplit[i]).length());
			}
			return splitResult;
		}

		char** splitCStringStatic(const std::string* inputString, char splitor)
		{
			return splitCStringStatic(const_cast<std::string*>(inputString), splitor);
		}

		char** splitCStringStatic(std::string* inputString, char splitor)
		{
			return splitCStringStatic(*inputString, splitor);
		}

		char** splitCStringStatic(const char* inputString, char splitor)
		{
			return splitCStringStatic(const_cast<char*>(inputString), splitor);
		}

		char** splitCStringStatic(char* inputString, char splitor)
		{
			std::string strInputString(inputString);
			return splitCStringStatic(strInputString, splitor);
		}


	}
}
