# String Uility (StrUtil) for C++

wayne::strUtil is a buntch of tools related to string / cstring operation.

Access these functions by adding namespace: 

<code>wayne::strUtil::</code>

## Usage

- <code>subStrReplaceAll(std::string/char* mainStr, std::string/char* targetSubStr,  std::string/char* replaceToSubStr)</code>
  
  - Replace all occurance of <code>targetSubStr</code> to <code>replaceToSubStr</code>
  
  - Return <code>std::string</code> or <code>char*</code>

- <code>subStrReplaceAllDirect(std::string*/char* mainStr, std::string/char* targetSubStr, std::string/char* replaceToSubStr</code>
  
  - The same as above, but it will alter the string directly that the pointer <code>mainStr</code> is pointed to.
  
  - Return <code>void</code>

- <code>subStrOccuranceCount(std::string/char* mainStr, std::string/char* targetSubStr)</code>
  
  - Get the amount of occurance that <code>targetSubStr</code> occurred in <code>mainStr</code>
  
  - Return <code>int</code>

- <code>subStrOccuranceIndex(std::string/char* mainStr, std::string/char* targetSubStr, int thOccurance)</code>
  
  - Get the <code>index</code> of <code>targetSubStr</code> on the <code>thOccurance</code> in the <code>mainStr.</code>
  - Return <code>int</code>

- <code>splitString(std::string/char* inputString, char splitor)</code>
  
  - Split the <code>inputString</code> with <code>splitor</code>, return split result with a dynamic vector.
  
  - Return <code>vector\<std::string\></code>

- <code>splitCString(char* inputString, char splitor)</code>
  
  - Split the <code>inputString</code> with <code>splitor</code>, return split result with a dynamic vector.
  
  - Return <code>vector\<char*\></code>

- <code>splitStringStatic(std::string/char* inputString, char splitor)</code>
  
  - Same functionality as <code>splitString()</code>, but return the split result with a fixed array.
  
  - Return <code>string*</code>

- <code>splitCStringStatic()</code>
  
  - Same functionality as <code>splitCString()</code>, but return the split result with a fixed array.
  
  - Return <code>char\*\*</code>

- <code>isAsciiString(std::string/char* toCheckString)</code>
  
  - Check whether given String/Cstring is ASCII compatibility
  
  - Return <code>bool</code>

- <code>isNumberString(std::string/char* toCheckString, bool isFloat(Optional))</code>
  
  - Check whether given String/Cstring is an Integer, or float.
  
  - Return <code>bool</code>
