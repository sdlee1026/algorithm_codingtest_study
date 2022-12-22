#include "../../codeHeader.h"
#include "codesignal_arcade_EruptionOfLight.h"



/*

	A string is said to be beautiful if each letter in the string appears at most as many times as the previous letter in the alphabet within the string;
	
	ie: b occurs no more times than a; c occurs no more times than b; etc. Note that letter a has no previous letter.

	Given a string, check whether it is beautiful.

*/
// https://app.codesignal.com/arcade/intro/level-10/PHSQhLEw3K2CmhhXE
bool solution_isBeautifulString(string inputString)
{
	map<char, int> mapC;

	for (int i = int('a'); i <= int('z'); i++)
		mapC[i] = 0;
	for (auto c : inputString)
	{
		if (mapC.find(c) != mapC.end())
			mapC[c]++;
	}
	int max = 1e9;
	for (auto iter = mapC.begin(); iter != mapC.end(); ++iter)
	{
		if (iter->second > max)
			return false;
		else
			max = iter->second;
	}
	return true;
}

/*

	An email address such as "John.Smith@example.com" is made up of a local part ("John.Smith"), an "@" symbol, then a domain part ("example.com").

	The domain name part of an email address may only consist of letters, digits, hyphens and dots.
	The local part, however, also allows a lot of different special characters. Here you can look at several examples of correct and incorrect email addresses.

	Given a valid email address, find its domain part.

*/
// https://app.codesignal.com/arcade/intro/level-10/TXFLopNcCNbJLQivP

string solution_FindEmailDomain(string address)
{
	return address.substr(address.rfind("@"), address.size());
}

/*
	Given a string, find the shortest possible string which can be achieved by adding characters to the end of initial string to make it a palindrome.

	Example

	For st = "abcdc", the output should be
	solution(st) = "abcdcba".
	
	eyy yye
	qaba abaq
*/
// https://app.codesignal.com/arcade/intro/level-10/ppZ9zSufpjyzAsSEx
string solution_buildPalindrome(string st)
{
	string str = st;
	reverse(begin(str), end(str));
	if (st == str)
		return st;
	for (int i = 0; i < st.size(); ++i)
	{
		string subStr1 = st.substr(i, st.size());
		string subStr2 = str.substr(0, str.size() - i);
		if (subStr1 == subStr2)
			return st + str.substr(str.size() - i, str.size());
	}
}