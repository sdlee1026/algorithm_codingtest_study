#include "../../codeHeader.h"
#include "codesignal_arcade_DivingDeeper.h"


/*

	Given array of integers, remove each kth element from it.

	Example

	For inputArray = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] and k = 3, the output should be
	solution(inputArray, k) = [1, 2, 4, 5, 7, 8, 10].

*/

// https://app.codesignal.com/arcade/intro/level-8/3AgqcKrxbwFhd3Z3R
vector<int> solution_extractEachKth(vector<int> inputArray, int k)
{
	vector<int>::iterator iter = inputArray.begin();
	int index = 1;
	while (iter != inputArray.end())
	{
		if (index % k == 0)
			iter = inputArray.erase(iter);
		else
			++iter;
			++index;
	}
	return inputArray;
}

/*

	Find the leftmost digit that occurs in a given string.

	Example

	For inputString = "var_1__Int", the output should be
	solution(inputString) = '1';

	For inputString = "q2q-q", the output should be
	solution(inputString) = '2';

	For inputString = "0ss", the output should be
	solution(inputString) = '0'.
*/

//https://app.codesignal.com/arcade/intro/level-8/rRGGbTtwZe2mA8Wov
char solution_firstDigit(string inputString)
{
	for (auto c : inputString)
		if (c <= '9' && c >= '0')
			return c;
}

/*

	Given a string, find the number of different characters in it.
	For s = "cabca", the output should be
	solution(s) = 3.

	There are 3 different characters a, b and c

	[input] string s

	A string of lowercase English letters.
*/
// https://app.codesignal.com/arcade/intro/level-8/8N7p3MqzGQg5vFJfZ
int solution_differentSymbolsNaive(string s)
{
	int intAry[123] = { 0, };
	int answer = 0;
	for (auto c : s)
		intAry[int(c)]++;
	for (int i = 97; i < 123; i++)
		if (intAry[i] > 0)
			answer++;
	return answer;
}

/*

	Given array of integers, find the maximal possible sum of some of its k consecutive elements.

	Example

	For inputArray = [2, 3, 5, 1, 6] and k = 2, the output should be
	solution(inputArray, k) = 8.
	All possible sums of 2 consecutive elements are:

	2 + 3 = 5;
	3 + 5 = 8;
	5 + 1 = 6;
	1 + 6 = 7.
	Thus, the answer is 8.

*/
// https://app.codesignal.com/arcade/intro/level-8/Rqvw3daffNE7sT7d5
int solution_arrayMaxConsecutiveSum(vector<int> inputArray, int k)
{
	int accInt = accumulate(inputArray.begin(), inputArray.begin() + k, 0);
	vector<int> result;
	result.push_back(accInt);
	for (int i = 0; i < inputArray.size() - (k); i++)
	{
		accInt += inputArray[i + k] - inputArray[i];
		result.push_back(accInt);
	}
	
	return *max_element(result.begin(), result.end());
}