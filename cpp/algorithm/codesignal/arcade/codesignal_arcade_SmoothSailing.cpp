#include "../../codeHeader.h"
#include "codesignal_arcade_SmoothSailing.h"

/*
	Given an array of strings, return another array containing all of its longest strings.

	Example

	For inputArray = ["aba", "aa", "ad", "vcd", "aba"], the output should be
	solution(inputArray) = ["aba", "vcd", "aba"]

	[input] array.string inputArray

	A non-empty array.

	Guaranteed constraints:
	1 ≤ inputArray.length ≤ 10,
	1 ≤ inputArray[i].length ≤ 10.

	[output] array.string
*/
//https://app.codesignal.com/arcade/intro/level-3/fzsCQGYbxaEcTr2bL

vector<string> solution_AllLongestStrings(vector<string> inputArray)
{
	vector<string> answer;
	int maxLen = -1;
	for (auto& str : inputArray)
	{
		int len = str.length();
		if (len > maxLen)
		{
			answer.clear();
			maxLen = str.length();
			answer.push_back(str);
		}
		else if (len == maxLen)
		{
			answer.push_back(str);
		}
	}
	return answer;
}

/*
	Given two strings, find the number of common characters between them.

	For s1 = "aabcc" and s2 = "adcaa", the output should be
	solution(s1, s2) = 3
*/

// https://app.codesignal.com/arcade/intro/level-3/JKKuHJknZNj4YGL32
// 
// https://ssocoit.tistory.com/25
// Map 사용설명
int solution_commonCharacterCount(string s1, string s2)
{
	map<char, int> m1, m2;
	int answer = 0;
	for (auto& str_1 : s1)
	{
		if (m1.find(str_1) != m1.end())
			m1[str_1]++;
		else
			m1.insert({ str_1, 1 });
	}
	for (auto& str_2 : s2)
	{
		if (m2.find(str_2) != m2.end())
			m2[str_2]++;
		else
			m2.insert({ str_2, 1 });
	}

	map<char, int>::iterator iter;
	for (iter = m1.begin(); iter != m1.end(); iter++)
	{
		int nTemp = iter->second;
		auto it = m2.find(iter->first);
		if (it != m2.end())
			answer += min(nTemp, it->second);
	}
	return answer;
}

/*
	Ticket numbers usually consist of an even number of digits.

	A ticket number is considered lucky if the sum of the first half of the digits is equal to the sum of the second half.

	Given a ticket number n, determine if it's lucky or not.

	Example

	For n = 1230, the output should be
	solution(n) = true;
	For n = 239017, the output should be
	solution(n) = false.

	[input] integer n

	A ticket number represented as a positive integer with an even number of digits.

	Guaranteed constraints:
	10 ≤ n < 10^6.

	[output] boolean

	true if n is a lucky ticket number, false otherwise.

*/
// https://app.codesignal.com/arcade/intro/level-3/3AdBC97QNuhF6RwsQ
// 숫자의 전반부 합이 후반부 합과 같을 경우 행운
bool solution_isLucky(int n)
{
	vector<int> temp;
	int half = 0;
	bool answer;

	while (1)
	{
		temp.push_back(n % 10);
		half++;
		if (n / 10 == 0)
		{
			half /= 2;
			if (accumulate(temp.begin(), temp.begin() + half, 0) == accumulate(temp.begin() + half, temp.end(), 0))
				answer = true;
			else 
				answer = false;
			break;
		}
		n /= 10;
	}
	return answer;
}
/*
	Some people are standing in a row in a park.
	There are trees between them which cannot be moved.
	Your task is to rearrange the people by their heights in a non-descending order without moving the trees.
	People can be very tall!

	Example

	For a = [-1, 150, 190, 170, -1, -1, 160, 180], the output should be
	solution(a) = [-1, 150, 160, 170, -1, -1, 180, 190]

	[input] array.integer a

	If a[i] = -1, then the ith position is occupied by a tree. Otherwise a[i] is the height of a person standing in the ith position.

	Guaranteed constraints:
	1 ≤ a.length ≤ 1000,
	-1 ≤ a[i] ≤ 1000.

	[output] array.integer

	Sorted array a with all the trees untouched.

	-1 == tree
*/
//https://app.codesignal.com/arcade/intro/level-3/D6qmdBL2NYz49XHwM

vector<int> solution_SortByHeight(vector<int> a)
{
	vector<int> people;
	for (auto& num : a)
	{
		if (num == -1)
			continue;
		people.push_back(num);
	}
	sort(people.rbegin(), people.rend());
	for (auto& num : a)
	{
		if (num == -1)
			continue;
		num = people.back();
		people.pop_back();
	}
	return a;
}


/*
	Write a function that reverses characters in (possibly nested) parentheses in the input string.

	Input strings will always be well-formed with matching ()s.

	Example

	For inputString = "(bar)", the output should be
	solution(inputString) = "rab";

	For inputString = "foo(bar)baz", the output should be
	solution(inputString) = "foorabbaz";

	For inputString = "foo(bar)baz(blim)", the output should be
	solution(inputString) = "foorabbazmilb";

	For inputString = "foo(bar(baz))blim", the output should be
	solution(inputString) = "foobazrabblim".

	Because "foo(bar(baz))blim" becomes "foo(barzab)blim" and then "foobazrabblim".

	[input] string inputString

	A string consisting of lowercase English letters and the characters ( and ). It is guaranteed that all parentheses in inputString form a regular bracket sequence.

	Guaranteed constraints:
	0 ≤ inputString.length ≤ 50.

	[output] string

	Return inputString, with all the characters that were in parentheses reversed.

*/
// https://app.codesignal.com/arcade/intro/level-3/9DgaPsE2a7M6M2Hu6

string solution_reverseInParentheses(string inputString)
{
	stack<int> st;

	for (int i = 0; i < inputString.size(); i++)
	{
		if (inputString[i] == '(')
			st.push(i);

		else if (inputString[i] == ')')
		{
			reverse(inputString.begin() + st.top() + 1, inputString.begin() + i);
			st.pop();
		}
	}

	string res = "";
	for (int i = 0; i < inputString.size(); i++)
	{
		if (inputString[i] != ')' && inputString[i] != '(')
			res += (inputString[i]);
	}
	return res;
}
