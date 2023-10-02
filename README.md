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

- <code>subStrOrruanceIndex(std::string/char* mainStr, std::string/char* targetSubStr, int thOccurance)</code>
  
  - Get the <code>index</code> of <code>targetSubStr</code> on the <code>thOccurance</code> in the <code>mainStr.</code>




