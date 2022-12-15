#include "../../codeHeader.h"
#include "codesignal_arcade_ThroughTheFog.h"


/*

	Consider integer numbers from 0 to n - 1 written down along the circle in such a way that the distance between any two neighboring numbers is equal (note that 0 and n - 1 are neighboring, too).

	Given n and firstNumber, find the number which is written in the radially opposite position to firstNumber.

	Example

	For n = 10 and firstNumber = 2, the output should be
	solution(n, firstNumber) = 7.
	원을 그려 n만큼의 숫자들을 나열 시켰을 때 firstNumber와 마주보는 반대편의 숫자를 찾아라

	integer n
	A positive even integer.

	4 ≤ n ≤ 20.
*/
// https://app.codesignal.com/arcade/intro/level-7/vExYvcGnFsEYSt8nQ
int solution_CircleOfNumbers(int n, int firstNumber)
{
	return (firstNumber + n / 2) % n;
}

/*

	You have deposited a specific amount of money into your bank account. Each year your balance increases at the same growth rate.
	With the assumption that you don't make any additional deposits, find out how long it would take for your balance to pass a specific threshold.

	Example

	For deposit = 100, rate = 20, and threshold = 170, the output should be
	solution(deposit, rate, threshold) = 3.

	Each year the amount of money in your account increases by 20%. So throughout the years, your balance would be:

	year 0: 100;
	year 1: 120;
	year 2: 144;
	year 3: 172.8.
	Thus, it will take 3 years for your balance to pass the threshold, so the answer is 3.
	// 단순 원금의 복리 계산
*/
// https://app.codesignal.com/arcade/intro/level-7/8PxjMSncp9ApA4DAb
int solution_depositProfit(int deposit, int rate, int threshold)
{
	double bank = deposit;
	int count = 0;
	while (bank < threshold)
	{
		bank *= 1 + ((double)rate / 100.f);
		count++;
	}
	return count;
}

/*

	Given a sorted array of integers a, your task is to determine which element of a is closest to all other values of a.
	In other words, find the element x in a, which minimizes the following sum:

	abs(a[0] - x) + abs(a[1] - x) + ... + abs(a[a.length - 1] - x)
	(where abs denotes the absolute value)

	If there are several possible answers, output the smallest one.

	Example

	For a = [2, 4, 7], the output should be solution(a) = 4.

	for x = 2, the value will be abs(2 - 2) + abs(4 - 2) + abs(7 - 2) = 7.
	for x = 4, the value will be abs(2 - 4) + abs(4 - 4) + abs(7 - 4) = 5.
	for x = 7, the value will be abs(2 - 7) + abs(4 - 7) + abs(7 - 7) = 8.
	The lowest possible value is when x = 4, so the answer is 4.

	For a = [2, 3], the output should be solution(a) = 2.

	for x = 2, the value will be abs(2 - 2) + abs(3 - 2) = 1.
	for x = 3, the value will be abs(2 - 3) + abs(3 - 3) = 1.
	Because there is a tie, the smallest x between x = 2 and x = 3 is the answer.

	Input/Output

	[execution time limit] 0.5 seconds (cpp)

	[input] array.integer a

	A non-empty array of integers, sorted in ascending order.

	Guaranteed constraints:
	1 ≤ a.length ≤ 1000,
	-10^6 ≤ a[i] ≤ 10^6.

*/
// https://app.codesignal.com/arcade/intro/level-7/ZFnQkq9RmMiyE6qtq
int solution_absoluteValuesSumMinimization(vector<int> a)
{
	int answer = 0, check = 0;
	int returnA = 0;

	int index = a[0];
	for (auto n : a)
	{
		check += abs(n - index);
	}
	answer = check;
	returnA = index;

	for (int i = 1; i < a.size(); i++)
	{
		index = a[i];
		check = 0;

		for (auto n : a)
		{
			check += abs(n - index);
		}
		if (answer > check)
		{
			answer = check;
			returnA = index;
		}
	}
	return returnA;
}
// 위의 문제 : return a[(a.size() - 1) / 2]; << 정렬된 ary 라서 가능

/*

	Given an array of equal-length strings,
	you'd like to know if it's possible to rearrange the order of the elements in such a way that each consecutive pair of strings differ by exactly one character.
	Return true if it's possible, and false if not.

	Note: You're only rearranging the order of the strings, not the order of the letters within the strings!

	Example

	For inputArray = ["aba", "bbb", "bab"], the output should be
	solution(inputArray) = false.

	There are 6 possible arrangements for these strings:

	["aba", "bbb", "bab"]
	["aba", "bab", "bbb"]
	["bbb", "aba", "bab"]
	["bbb", "bab", "aba"]
	["bab", "bbb", "aba"]
	["bab", "aba", "bbb"]
	None of these satisfy the condition of consecutive strings differing by 1 character, so the answer is false.

	For inputArray = ["ab", "bb", "aa"], the output should be
	solution(inputArray) = true.

	It's possible to arrange these strings in a way that each consecutive pair of strings differ by 1 character (eg: "aa", "ab", "bb" or "bb", "ab", "aa"), so return true.

	Input/Output

	[execution time limit] 0.5 seconds (cpp)

	[input] array.string inputArray

	A non-empty array of strings of lowercase letters.

	Guaranteed constraints:
	2 ≤ inputArray.length ≤ 10,
	1 ≤ inputArray[i].length ≤ 15.

	[output] boolean

	Return true if the strings can be reordered in such a way that each neighbouring pair of strings differ by exactly one character (false otherwise).

*/
// https://app.codesignal.com/arcade/intro/level-7/PTWhv2oWqd6p4AHB9
bool solution_stringsRearrangement(vector<string> inputArray)
{
	if (inputArray.size() == 1)
		return false;
	sort(inputArray.begin(), inputArray.end());

	vector<vector<string>> vvStr;
	vector<bool> boolVec;
	int vecIndex = 0;
	do
	{
		vvStr.push_back(inputArray);
		boolVec.push_back(true);
	} while (next_permutation(inputArray.begin(), inputArray.end()));

	for (auto vStr : vvStr)
	{
		for (int i = 1; i < vStr.size(); i++)
		{
			if (boolVec[vecIndex] == false)
				continue;

			if (vStr[i - 1] == vStr[i])
				boolVec[vecIndex] = false;
			else
			{
				int count = 0;
				for (int j = 0; j < vStr[i].size(); j++)
				{
					if (vStr[i - 1][j] != vStr[i][j])
						count++;
				}
				if (count > 1)
					boolVec[vecIndex] = false;
			}
		}
		vecIndex++;
	}
	for (auto b : boolVec)
		if (b == true)
			return true;
	return false;
}