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


/*

	Elections are in progress!

	Given an array of the numbers of votes given to each of the candidates so far, and an integer k equal to the number of voters who haven't cast their vote yet,
	find the number of candidates who still have a chance to win the election.

	The winner of the election must secure strictly more votes than any other candidate.
	If two or more candidates receive the same (maximum) number of votes, assume there is no winner at all.
	
	Example

	For votes = [2, 3, 5, 2] and k = 3, the output should be
	solution(votes, k) = 2.

	The first candidate got 2 votes. Even if all of the remaining 3 candidates vote for him, he will still have only 5 votes, i.e. the same number as the third candidate, so there will be no winner.
	The second candidate can win if all the remaining candidates vote for him (3 + 3 = 6 > 5).
	The third candidate can win even if none of the remaining candidates vote for him. For example, if each of the remaining voters cast their votes for each of his opponents, he will still be the winner (the votes array will thus be [3, 4, 5, 3]).
	The last candidate can't win no matter what (for the same reason as the first candidate).
	Thus, only 2 candidates can win (the second and the third), which is the answer.
*/
// https://app.codesignal.com/arcade/intro/level-10/8RiRRM3yvbuAd3MNg
int solution_ElectionsWinners(vector<int> votes, int k)
{
	int answer = 0;
	int maxInt = *max_element(votes.begin(), votes.end());
	if (k == 0)
	{
		int intCount = count(votes.begin(), votes.end(), maxInt);
		if (intCount != 1)
			return 0;
		else
			return 1;
	}
	else
	{
		for (auto& n : votes)
			if (n > maxInt - k)
				answer++;
	}
	return answer;
}

/*
	A media access control address (MAC address) is a unique identifier assigned to network interfaces for communications on the physical network segment.

	The standard (IEEE 802) format for printing MAC-48 addresses in human-friendly form is six groups of two hexadecimal digits (0 to 9 or A to F), separated by hyphens (e.g. 01-23-45-67-89-AB).

	Your task is to check by given string inputString whether it corresponds to MAC-48 address or not.

	Example

	For inputString = "00-1B-63-84-45-E6", the output should be
	solution(inputString) = true;
	For inputString = "Z1-1B-63-84-45-E6", the output should be
	solution(inputString) = false;
	For inputString = "not a MAC-48 address", the output should be
	solution(inputString) = false.
*/
// https://app.codesignal.com/arcade/intro/level-10/HJ2thsvjL25iCvvdm
bool solution_IsMAC48Address(string inputString)
{
	regex re("[A-F0-9]{2}(-[A-F0-9]{2}){5}");
	return regex_match(inputString, re);
}
