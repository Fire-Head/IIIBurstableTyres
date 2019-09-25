/*
The MIT License

Copyright (C) 2016 Enrico Huang enrico@scenecast.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
#include "String.h"
#include <string.h>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iterator>
#include <stdlib.h>

namespace cppext
{
	//workaround c++11 auto
	typedef std::string::const_iterator cstriter;
	typedef std::string::iterator striter;
	typedef std::string::const_reverse_iterator cstrriter;
	typedef std::string::reverse_iterator strriter;
	//workaround c++11 lambda/find_if_not/any_of
	class isalpha: public std::unary_function<bool, int>
	{
		public:
			bool operator()(int c) const
			{
				return std::isalpha(c);
			}
	};
	class isspace: public std::unary_function<bool, int>
	{
		public:
			bool operator()(int c) const
			{
				return std::isspace(c);
			}
	};
	class isanyof: public std::unary_function<bool, int>
	{
			std::string pattern;
		public:
			isanyof(const char* anyOf): pattern(anyOf)
			{
			}
			bool operator()(int c) const 
			{
				return std::find(pattern.begin(), pattern.end(), c) != pattern.end();					
			}	
	};
	//workaround end
	
	String::String()
	{
	}
	String::String(const char* s):
		s(s)
	{
	}
	String::String(const std::vector<char>& value):
		s(value.begin(), value.end())
	{
	}
	String::String(const std::string &s):
		s(s)
	{
	}
	String::String(const char *value, size_t startIndex, size_t length):
		s(value, startIndex, length)
	{
	}
	String::String(const std::vector<char>& value, size_t startIndex, size_t length):
		s(value.begin() + startIndex, value.begin() + length)
	{
	}
	String::String(char c, size_t count):
		s(count, c)
	{
	}
	size_t String::Length() const
	{
		return s.length();
	}
	const char* String::c_str() const
	{
		return s.c_str();
	}
	std::string& String::str()
	{
		return s;
	}
	const std::string& String::const_str() const
	{
		return s;
	}
	
	int String::ToInt()
	{
		return atoi(c_str());
	}
		
	float String::ToFloat()
	{
		return atof(c_str());
	}
		
	char String::operator[] (size_t index) const
	{
		return s.at(index);
	}
	String::operator std::string () const
	{
		return s;
	}
	String String::operator+(const String& rhs) const
	{																													
		return s + rhs.s;
	}
	bool String::operator<(const String &rhs) const
	{
		return s < rhs.s;
	}
	bool String::operator>(const String &rhs) const
	{
		return s > rhs.s;
	}
	String& String::operator=(const char *rhs)
	{
		s = rhs ? rhs : "";
		return *this;
	}
	String& String::operator=(const std::string &rhs)
	{
		s = rhs;
		return *this;
	}
	String& String::operator=(const String &rhs)
	{
		s = rhs.s;
		return *this;
	}
	String& String::operator+=(const String &rhs)
	{
		s.append(rhs.s);
		return *this;
	}
	bool String::operator==(const String &rhs) const
	{
		return s == rhs.s;
	}
	bool String::operator!=(const String &rhs) const
	{
		return s != rhs.s;
	}
	void String::Clear()
	{
		std::string().swap(s);//reclaim the memory
	}
	int String::Compare(const String &strA,const String &strB)
	{
		return Compare(strA, 0, strB, 0, (size_t)-1);
	}
	int String::Compare(const String &strA, size_t indexA, const String &strB, size_t indexB, size_t length)
	{
		if(length == 0) return 0; 
		const char *a = strA.c_str();
		const char *b = strB.c_str();
		if(indexA > strA.Length()) return 0;//no comparison
		if(indexB > strB.Length()) return 0;
		a += indexA;
		b += indexB;
		int count = 0;
		while(true)
		{
			if(a == NULL && b == NULL) break;
			if(length == 0) break;
			if(*a > *b) return count;
			if(*a < *b) return -count;
			count++;
			a++;
			b++;
			length--;
		}
		return 0;
	}
	String String::Concat(const String &str0, const String &str1)
	{		
		return str0 + str1;
	}
	String String::Concat(const String &str0, const String &str1, const String &str2)
	{		
		return str0 + str1 + str2;
	}
	String String::Concat(const String &str0, const String &str1, const String &str2, const String &str3)
	{		
		return str0 + str1 + str2 + str3;
	}
	String String::Concat(const std::vector<String> value)
	{
		return std::accumulate(value.begin(), value.end(), String());
	}
	bool String::Contains(const String &value) const
	{
		return s.find(value) != std::string::npos;
	}
	bool String::ContainsOnly(const char* value) const
	{
		return !*(s.c_str()+strspn(s.c_str(), value));
	}
	bool String::EndsWith(const String& value) const
	{
		if(this->Length() < value.Length()) return false;
		return std::equal(value.s.begin(), value.s.end(), s.end() - value.Length());
	}
	size_t String::IndexOf(char value) const
	{
		return s.find(value);//npos
	}
	size_t String::IndexOf(char value, size_t startIndex) const
	{
		return s.find(value, startIndex);//npos
	}
	size_t String::IndexOf(char value, size_t startIndex, size_t count) const
	{
		cstriter it1 = s.begin();
		cstriter it2 = it1 + count;
		if(it2 > s.end()) it2 = s.end();
		cstriter it = std::find(it1, it2, value);
		if(it == it2) return std::string::npos;
		return it - it1;
	}
	size_t String::IndexOf(const String &value) const
	{
		return s.find(value.s);//npos
	}
	size_t String::IndexOf(const String &value, size_t startIndex) const
	{
		return s.find(value.s, startIndex);
	}
	size_t String::IndexOf(const String &value, size_t startIndex, size_t count) const
	{
		size_t pos = s.find(value.s, startIndex);
		if(pos > startIndex + count) return std::string::npos;
		return pos;
	}
	size_t String::IndexOfAny(const char* anyOf) const
	{
		cstriter it = std::find_if(s.begin(), s.end(), isanyof(anyOf));
		if(it == s.end()) return std::string::npos;
		return it - s.begin();
	}
	size_t String::IndexOfAny(const char* anyOf, size_t startIndex) const
	{
		if(startIndex >= s.size()) return std::string::npos;
		cstriter it = std::find_if(s.begin() + startIndex, s.end(), isanyof(anyOf));
		if(it == s.end()) return std::string::npos;
		return it - s.begin();
	}
	size_t String::IndexOfAny(const char* anyOf, size_t startIndex, size_t count) const
	{
		if(startIndex + count >= s.size()) return std::string::npos;
		cstriter it = std::find_if(s.begin() + startIndex, s.begin() + startIndex + count, isanyof(anyOf));
		if(it == s.end()) return std::string::npos;
		return it - s.begin();
	}
	bool String::IsAlpha() const
	{
		return std::find_if_not(s.begin(), s.end(), isalpha()) == s.end();
	}
	bool String::IsEmpty(const String &value)
	{
		return value.s.empty();
	}
	String String::Insert(int startIndex,const String &value) const
	{
		std::string s(s);
		return s.insert(startIndex, value);
	}
	bool String::IsEmpty() const
	{
		return s.empty();
	}
	bool String::IsWhiteSpace(const String &value)
	{
		return std::find_if_not(value.s.begin(), value.s.end(), isspace()) == value.s.end();
	}
	bool String::IsWhiteSpace() const
	{
		return std::find_if_not(s.begin(), s.end(), isspace()) == s.end();
	}
	String String::Join(const String& separator, const std::vector<String>& value)
	{
		std::ostringstream ss;
		size_t len = value.size();
		if(len == 0) return String();
		for(size_t i = 0; i < len - 1; i++)
		{
			ss << value[i] << separator;
		}
		ss << value[len-1];		
		return ss.str();
	}
	size_t String::LastIndexOf(char value) const
	{
		return s.rfind(value);
	}
	size_t String::LastIndexOf(char value, size_t startIndex) const
	{
		return s.rfind(value, startIndex);
	}
	size_t String::LastIndexOf(char value, size_t startIndex, size_t count) const
	{
		cstrriter it1 = s.rbegin();
		cstrriter it2 = it1 + count;
		if(it2 > s.rend()) it2 = s.rend();
		cstrriter it = std::find(it1, it2, value);
		if(it == it2) return std::string::npos;
		return it - it1;
	}
	size_t String::LastIndexOf(const String &value) const
	{
		return s.rfind(value.s);
	}
	size_t String::LastIndexOf(const String &value, size_t startIndex) const
	{
		return s.rfind(value.s, startIndex);
	}
	size_t String::LastIndexOf(const String &value, size_t startIndex, size_t count) const
	{
		size_t pos = s.rfind(value.s, startIndex);
		if(pos == std::string::npos) return std::string::npos;
		if(pos <= startIndex - count) return std::string::npos;
		return pos;
	}
	size_t String::LastIndexOfAny(const char* anyOf) const
	{
		cstrriter it = std::find_if(s.rbegin(), s.rend(), isanyof(anyOf));
		if(it == s.rend()) return std::string::npos;
		return it - s.rbegin();
	}
	String String::PadLeft(size_t totalWidth) const
	{
		size_t pad = totalWidth - Length();
		return (pad > 0) ? std::string(pad, ' ') + s : s;
	}
	String String::PadLeft(size_t totalWidth, char paddingChar) const
	{
		size_t pad = totalWidth - Length();
		return (pad > 0) ? std::string(pad, paddingChar) + s : s;
	}
	String String::PadRight(size_t totalWidth) const
	{
		size_t pad = totalWidth - Length();
		return (pad > 0) ? s + std::string(pad, ' ') : s;
	}
	String String::PadRight(size_t totalWidth, char paddingChar) const
	{
		size_t pad = totalWidth - Length();
		return (pad > 0) ? s + std::string(pad, paddingChar) : s;
	}
	String String::Remove(size_t startIndex) const
	{
		std::string s(s);
		s.erase(startIndex);
		return s;
	}
	String String::Remove(size_t startIndex, size_t count) const
	{
		std::string s(s);
		s.erase(startIndex, count);
		return s;
	}
	String String::Replace(char oldChar, char newChar) const
	{
		std::string s(s);
		std::replace(s.begin(), s.end(), oldChar, newChar);
		return s;
	}
	String String::Replace(const String& oldValue, const String& newValue) const
	{
		if(oldValue.Length() == 0) return s;
		std::string s(s);
		size_t len = oldValue.Length();
		size_t len2 = newValue.Length();
		size_t pos=0;
		while((pos=s.find(oldValue,pos))!=std::string::npos)
		{
			s.replace(pos, len, newValue);
			pos+=len2;
		}
		return s;
	}
	std::vector<String> String::Split(const char* separator) const
	{
		return Split(separator, (size_t) -1);
	}
	std::vector<String> String::Split(const char* separator, size_t count) const
	{
		std::vector<String> ss;
		size_t last_pos = 0;
		size_t next_pos = 0;
		while((next_pos = s.find_first_of(separator, last_pos)) != std::string::npos)
		{
			if(count == 0) break;
			if(next_pos-last_pos)
			{
				ss.push_back(s.substr(last_pos, next_pos - last_pos));
				count--;
			}
			last_pos = next_pos + 1;
		}
		if(count)
		{
			if(last_pos != s.length())
			{
				ss.push_back(s.substr(last_pos));
			}
		}
		return ss;
	}
	bool String::StartsWith(const String& value) const
	{
		if(this->Length() < value.Length()) return false;
		return std::equal(value.s.begin(), value.s.end(), s.begin());
	}
	String String::Substring(size_t startIndex) const
	{
		return s.substr(startIndex);
	}
	String String::Substring(size_t startIndex, size_t length) const
	{
		return s.substr(startIndex, length);
	}
	std::vector<char> String::ToCharArray() const
	{
		return std::vector<char>(s.begin(), s.end());
	}
	std::vector<char> String::ToCharArray(size_t startIndex, size_t length) const
	{
		cstriter iterStart = s.begin() + startIndex;
		cstriter iterEnd = iterStart + length;
		if(iterStart > s.end()) iterStart = s.end();
		if(iterEnd > s.end()) iterEnd = s.end();
		return std::vector<char>(iterStart, iterEnd);		
	}
	String String::ToLower() const
	{
		std::string s(s);
		std::transform(s.begin(), s.end(), s.begin(), ::tolower);
		return s;
	}
	String String::ToUpper() const
	{
		std::string s(s);
		std::transform(s.begin(), s.end(), s.begin(), ::toupper);
		return s;
	}
	String String::Trim() const
	{
		cstriter it1 = std::find_if_not(s.begin(), s.end(), isspace());
		cstriter it2 = std::find_if_not(s.rbegin(), s.rend(), isspace()).base();
	
		return (it1 >= it2) ? String() : String(std::string(it1, it2));
	}
	String String::Trim(const char* trimChars) const
	{
		cstriter it1 = std::find_if_not(s.begin(), s.end(), isanyof(trimChars));
		cstriter it2 = std::find_if_not(s.rbegin(), s.rend(), isanyof(trimChars)).base();
		return (it1 >= it2) ? String() : String(std::string(it1, it2));
	}
	String String::TrimStart(const char* trimChars) const
	{
		cstriter it1 = std::find_if_not(s.begin(), s.end(), isanyof(trimChars));
		cstriter it2 = s.end();
		return (it1 >= it2) ? String() : String(std::string(it1, it2));
	}
	String String::TrimEnd(const char* trimChars) const
	{
		cstriter it1 = s.begin();
		cstriter it2 = std::find_if_not(s.rbegin(), s.rend(), isanyof(trimChars)).base();
		return (it1 >= it2) ? String() : String(std::string(it1, it2));
	}
	
	String String::TrimStart() const
	{
		cstriter it1 = std::find_if_not(s.begin(), s.end(), isspace());
		cstriter it2 = s.end();
		return (it1 >= it2) ? String() : String(std::string(it1, it2));
	}
	
	String String::TrimEnd() const
	{
		cstriter it1 = s.begin();
		cstriter it2 = std::find_if_not(s.rbegin(), s.rend(), isspace()).base();
		return (it1 >= it2) ? String() : String(std::string(it1, it2));
	}
	
	size_t String::Count(const char value) const
	{
		return std::count(s.begin(), s.end(), value);
	}
	
	/*
	https://github.com/petrekm/xtsystem/blob/b6a7af0f0ca91004a5c5cbfd319c10fd2dc77ddd/XTSystem_02string.h
	*/
	std::vector<String> String::SplitStr(const String &separator, StringSplitOptions options) const
	{
		std::vector<String> result;
		int separatorLength = separator.Length();
		int start = 0;
		int end = IndexOf(separator);
		while (end != -1)
		{
			if (end-start >0 || options == StringSplitOptions::None)
			{
				result.push_back(Substring(start, end - start));
			}
			start = end + separatorLength;
			end = IndexOf(separator,start);
		}
		if (end == -1)
		{
			if (start < Length() || options == StringSplitOptions::None) result.push_back(Substring(start));
		}
		return result;
	}
	
	std::ostream& operator<<(std::ostream& lhs, const String& rhs)
	{
		return lhs << rhs.s;
	}
	
}