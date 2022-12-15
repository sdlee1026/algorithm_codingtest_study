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
