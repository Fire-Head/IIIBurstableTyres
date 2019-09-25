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
/*
	C++ String class similar to C# String, but in C++ semantics.
	For example, C++ char is different from C# Unicode Char.
*/
#pragma once
#include <string>
#include <vector>


namespace cppext
{
	class StringSplitOptions
	{
	public:
		StringSplitOptions(): value(None) {}
		StringSplitOptions(int val): value(val) {}
		static const int None = 0;
		static const int RemoveEmptyEntries = 1;
		operator int() { return value;}
	private:
		int value;
	};

	class String
	{
	private:
		std::string s;
	public:
		//default ctor
		String();
		//Initializes a new instance of the String class to the value indicated by a specified char pointer 
		String(const char* s);
		//Initializes a new instance of the String class to the value indicated by a specified char vector array 
		String(const std::vector<char>& value);
		//Initializes a new instance of the String class to the value indicated by a specified std::string
		String(const std::string &s);
		//Initializes a new instance of the String class to the value indicated by a specified pointer to char, a starting position, and a length.
		String(const char *value, size_t startIndex, size_t length);
		//Initializes a new instance of the String class to the value indicated by a specified char vector array, a starting position, and a length.
		String(const std::vector<char>& value, size_t startIndex, size_t length);
		//Initializes a new instance of the String class to the value indicated by a specified character repeated a specified number of times.
		String(char c, size_t count);
		//Gets the number of characters in the current String object.
		size_t Length() const;
		//Gets the raw c string
		const char* c_str() const;
		//Gets the string reference
		std::string& str();
		//Gets the string reference but const
		const std::string& const_str() const;
		
		int ToInt();
		float ToFloat();
		
		//Gets the char at a specified position in the current String object.
		char operator[] (size_t index) const;
		//type conversion operator
		operator std::string () const;

		//+ operator
		String operator+(const String& rhs) const;

		//comparison operator
		bool operator<(const String &rhs) const;
		bool operator>(const String &rhs) const;
		bool operator==(const String &rhs) const;
		bool operator!=(const String &rhs) const;

		//assignment operator
		String& operator=(const char *rhs);
		String& operator=(const std::string &rhs);
		String& operator=(const String &rhs);
		String& operator+=(const String &rhs);

		//clear the String object
		void Clear();
		//Compares substrings of two specified String objects and returns an integer that indicates their relative position in the sort order
		//0 equal, + A>B, - A<B
		static int Compare(const String &strA, const String &strB);
		//Compares substrings of two specified String objects and returns an integer that indicates their relative position in the sort order
		static int Compare(const String &strA, size_t indexA, const String &strB, size_t indexB, size_t length);
		//Concatenates two specified instances of String.
		static String Concat(const String &str0, const String &str1);
		//Concatenates three specified instances of String.
		static String Concat(const String &str0, const String &str1, const String &str2);
		//Concatenates the elements of a specified String array.
		static String Concat(const std::vector<String> value);
		//Concatenates four specified instances of String.
		static String Concat(const String &str0, const String &str1, const String &str2, const String &str3);
		//Returns a value indicating whether a specified substring occurs within this string.
		bool Contains(const String &value) const;
		//Determines whether the string contains only the specified characters
		bool ContainsOnly(const char* value) const;
		//Determines whether the end of this string instance matches the specified string.
		bool EndsWith(const String& value) const;
		//Reports the zero-based index of the first occurrence of the specified character in this string.
		size_t IndexOf(char value) const;
		//Reports the zero-based index of the first occurrence of the specified character in this string. The search starts at a specified character position.
		size_t IndexOf(char value, size_t startIndex) const;
		//Reports the zero-based index of the first occurrence of the specified character in this instance. The search starts at a specified character position and examines a specified number of character positions.
		size_t IndexOf(char value, size_t startIndex, size_t count) const;
		//Reports the zero-based index of the first occurrence of the specified string in this instance.
		size_t IndexOf(const String &value) const;
		//Reports the zero-based index of the first occurrence of the specified string in this instance. The search starts at a specified character position.
		size_t IndexOf(const String &value, size_t startIndex) const;
		//Reports the zero-based index of the first occurrence of the specified string in this instance. The search starts at a specified character position and examines a specified number of character positions.
		size_t IndexOf(const String &value, size_t startIndex, size_t count) const;
		//Reports the zero-based index of the first occurrence in this instance of any character in a specified array of characters.
		size_t IndexOfAny(const char* anyOf) const;
		//Reports the zero-based index of the first occurrence in this instance of any character in a specified array of characters. The search starts at a specified character position.
		size_t IndexOfAny(const char* anyOf, size_t startIndex) const;
		//Reports the zero-based index of the first occurrence in this instance of any character in a specified array of characters. The search starts at a specified character position and examines a specified number of character positions.
		size_t IndexOfAny(const char* anyOf, size_t startIndex, size_t count) const;
		//Returns a new string in which a specified string is inserted at a specified index position in this instance.
		String Insert(int startIndex,const String &value) const;
		//Indicates whether the specified string contains only alpha
		bool IsAlpha() const;
		//Indicates whether the specified string is empty string
		static bool IsEmpty(const String &value);
		//Indicates whether this string is empty string
		bool IsEmpty() const;
		//Indicates whether the specified string consists only of white-space characters.
		static bool IsWhiteSpace(const String &value);
		//Indicates whether this string consists only of white-space characters.
		bool IsWhiteSpace() const;
		//Concatenates all the elements of a string array, using the specified separator between each element.
		static String Join(const String& separator, const std::vector<String>& value);
		//Reports the zero-based index position of the last occurrence of a specified character within this instance.
		size_t LastIndexOf(char value) const;
		//Reports the zero-based index position of the last occurrence of a specified character within this instance. The search starts at a specified character position and proceeds backward toward the beginning of the string.
		size_t LastIndexOf(char value, size_t startIndex) const;
		//Reports the zero-based index position of the last occurrence of the specified character in a substring within this instance. The search starts at a specified character position and proceeds backward toward the beginning of the string for a specified number of character positions.
		size_t LastIndexOf(char value, size_t startIndex, size_t count) const;
		//Reports the zero-based index position of the last occurrence of a specified string within this instance.
		size_t LastIndexOf(const String &value) const;
		//Reports the zero-based index position of the last occurrence of a specified string within this instance. The search starts at a specified character position and proceeds backward toward the beginning of the string.
		size_t LastIndexOf(const String &value, size_t startIndex) const;
		//Reports the zero-based index position of the last occurrence of a specified string within this instance. The search starts at a specified character position and proceeds backward toward the beginning of the string for a specified number of character positions.
		size_t LastIndexOf(const String &value, size_t startIndex, size_t count) const;
		//Reports the zero-based index position of the last occurrence in this instance of one or more characters specified in character array
		size_t LastIndexOfAny(const char* anyOf) const;
		//Returns a new string that right-aligns the characters in this instance by padding them with spaces on the left, for a specified total length.
		String PadLeft(size_t totalWidth) const;
		//Returns a new string that right-aligns the characters in this instance by padding them on the left with a specified character, for a specified total length.
		String PadLeft(size_t totalWidth, char paddingChar) const;
		//Returns a new string that left-aligns the characters in this string by padding them with spaces on the right, for a specified total length.
		String PadRight(size_t totalWidth) const;
		//Returns a new string that left-aligns the characters in this string by padding them on the right with a specified character, for a specified total length.
		String PadRight(size_t totalWidth, char paddingChar) const;
		//Returns a new string in which all the characters in the current instance, beginning at a specified position and continuing through the last position, have been deleted.
		String Remove(size_t startIndex) const;
		//Returns a new string in which a specified number of characters in the current instance beginning at a specified position have been deleted.
		String Remove(size_t startIndex, size_t count) const;
		//Returns a new string in which all occurrences of a specified character in this instance are replaced with another specified character.
		String Replace(char oldChar, char newChar) const;
		//Returns a new string in which all occurrences of a specified string in the current instance are replaced with another specified string.
		String Replace(const String& oldValue,const String& newValue) const;
		//Splits a string into substrings that are based on the characters in an array.
		std::vector<String> Split(const char* separator) const;
		//Splits a string into a maximum number of substrings based on the characters in an array. You also specify the maximum number of substrings to return.
		std::vector<String> Split(const char* separator, size_t count) const;
		//Determines whether the beginning of this string instance matches the specified string
		bool StartsWith(const String &value) const;
		//Returns a copy of the substring starts at a specified character position and continues to the end of the string.
		String Substring(size_t startIndex) const;
		//Returns a copy of the substring starts at a specified character position and has a specified length.
		String Substring(size_t startIndex, size_t length) const;
		//Copies the characters in this instance to a character array.
		std::vector<char> ToCharArray() const;
		//Copies the characters in a specified substring in this instance to a character array.
		std::vector<char> ToCharArray(size_t startIndex, size_t length) const;
		//Returns a copy of this string converted to lowercase.
		String ToLower() const;
		//Returns a copy of this string converted to uppercase.
		String ToUpper() const;
		//Removes all leading and trailing white-space characters from the current String object.
		String Trim() const;
		//Removes all leading and trailing occurrences of a set of characters specified in char pointer from the current String object.
		String Trim(const char* trimChars) const;
		//Removes all leading occurrences of a set of characters specified in char pointer from the current String object.
		String TrimStart(const char* trimChars) const;
		//Removes all trailing occurrences of a set of characters specified in char pointer from the current String object.
		String TrimEnd(const char* trimChars) const;
		
		String TrimStart() const;
		String TrimEnd() const;
		size_t Count(const char value) const;
		std::vector<String> SplitStr(const String &separator, StringSplitOptions options) const;
		
		//ostream output
		friend std::ostream& operator<<(std::ostream& lhs, const String& rhs);			
	};
};