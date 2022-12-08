#include "../../codeHeader.h"
#include "codesignal_arcade_ExploringTheWaters.h"


/*
	Several people are standing in a row and need to be divided into two teams.
	The first person goes into team 1, the second goes into team 2, the third goes into team 1 again, the fourth into team 2, and so on.

	You are given an array of positive integers - the weights of the people.
	Return an array of two integers,
	where the first element is the total weight of team 1, and the second element is the total weight of team 2 after the division is complete.

	Example

	For a = [50, 60, 60, 45, 70], the output should be
	solution(a) = [180, 105].


	[input] array.integer a

	Guaranteed constraints:
	1 ≤ a.length ≤ 105,
	45 ≤ a[i] ≤ 100.

*/

// https://app.codesignal.com/arcade/intro/level-4/cC5QuL9fqvZjXJsW9
vector<int> solution_alternatingSums(vector<int> a)
{
	int answer1 = 0, answer2 = 0;
	int check = 1;
	for (auto& n : a)
	{
		if (check >= 1)
			answer1 += n;
		else
			answer2 += n;
		check *= -1;
	}
	return { answer1, answer2 };
		
	/*
	vector<int> answer(2);
    for(int i=0; i<a.size(); ++i)
        answer[i%2] += a[i];
    
    return answer;
	*/
}
/*
	Given a rectangular matrix of characters, add a border of asterisks(*) to it.

	picture = 
	["abc",
     "ded"]
	solution(picture) =	 ["*****",
						  "*abc*",
						  "*ded*",
						  "*****"]

	1 ≤ picture.length ≤ 100,
	1 ≤ picture[i].length ≤ 100.
*/

//https://app.codesignal.com/arcade/intro/level-4/ZCD7NQnED724bJtjN
vector<string> solution_AddBorder(vector<string> picture)
{
	vector<string> answer;
	string upDown;
	int size = picture[0].size();
	for (int i = 0; i < size + 2; i++)
		upDown += "*";
	answer.push_back(upDown);
	for (auto& str : picture)
	{
		answer.push_back("*" + str + "*");
	}
	answer.push_back(upDown);
	return answer;
}

/*

	Two arrays are called similar if one can be obtained from another by swapping at most one pair of elements in one of the arrays.

	Given two arrays a and b, check whether they are similar.

	Example

	For a = [1, 2, 3] and b = [1, 2, 3], the output should be
	solution(a, b) = true.

	The arrays are equal, no need to swap any elements.

	For a = [1, 2, 3] and b = [2, 1, 3], the output should be
	solution(a, b) = true.

	We can obtain b from a by swapping 2 and 1 in b.

	For a = [1, 2, 2] and b = [2, 1, 1], the output should be
	solution(a, b) = false.

	Any swap of any two elements either in a or in b won't make a and b equal.

	Input/Output

	[execution time limit] 0.5 seconds (cpp)

	[input] array.integer a

	Array of integers.

	Guaranteed constraints:
	3 ≤ a.length ≤ 105,
	1 ≤ a[i] ≤ 1000.

	[input] array.integer b

	Array of integers of the same length as a.

	Guaranteed constraints:
	b.length = a.length,
	1 ≤ b[i] ≤ 1000.

	[output] boolean

	true if a and b are similar, false otherwise.

*/
//https://app.codesignal.com/arcade/intro/level-4/xYXfzQmnhBvEKJwXP
bool solution_AreSimilar(vector<int> a, vector<int> b)
{
	int diff = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			diff++;
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (int i = 0; i < a.size(); i++)
		if (a[i] != b[i])
			return false;

	if (diff > 2)
		return false;
	else
		return true;
}

/*

	You are given an array of integers.
	On each move you are allowed to increase exactly one of its element by one.
	Find the minimal number of moves required to obtain a strictly increasing sequence from the input.
	오름차순이 되는 행동 순서
	Example

	For inputArray = [1, 1, 1], the output should be
	solution(inputArray) = 3.

	Input/Output

	[execution time limit] 0.5 seconds (cpp)

	[input] array.integer inputArray

	Guaranteed constraints:
	3 ≤ inputArray.length ≤ 105,
	-105 ≤ inputArray[i] ≤ 105.

*/
// https://app.codesignal.com/arcade/intro/level-4/xvkRbxYkdHdHNCKjg

int solution_arrayChange(vector<int> inputArray)
{
	int answer = 0;
	for (int i = 0; i < inputArray.size()-1; i++)
	{
		int q = inputArray[i];
		int j = i + 1;
		while (inputArray[i]>=inputArray[j])
		{
			answer++;
			inputArray[j]++;
		}
	}
	return answer;
}
/*
	Given a string, find out if its characters can be rearranged to form a palindrome.

	Example

	For inputString = "aabb", the output should be
	solution(inputString) = true.

	We can rearrange "aabb" to make "abba", which is a palindrome.

	Input/Output

	[execution time limit] 0.5 seconds (cpp)

	[input] string inputString

	A string consisting of lowercase English letters.

	Guaranteed constraints:
	1 ≤ inputString.length ≤ 50.
*/
// https://app.codesignal.com/arcade/intro/level-4/Xfeo7r9SBSpo3Wico
// zyyzzzzz -> true
bool solution_palindromeRearranging(string inputString)
{
	int asciiAry[123] = {0,};

	for (char c : inputString)
	{
		asciiAry[int(c)]++;
	}
	int answerCheck = 0;

	for (auto& i : asciiAry)
	{
		if (answerCheck > 1)
			return false;
		if (i % 2 != 0)
			answerCheck++;
	}
	return true;
}
