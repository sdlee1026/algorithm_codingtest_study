#include "../../codeHeader.h"
#include "codesignal_arcade_DarkWilderness.h"


/*

	Caring for a plant can be hard work, but since you tend to it regularly, you have a plant that grows consistently. Each day, its height increases by a fixed amount represented by the integer upSpeed. But due to lack of sunlight, the plant decreases in height every night, by an amount represented by downSpeed.

	Since you grew the plant from a seed, it started at height 0 initially. Given an integer desiredHeight, your task is to find how many days it'll take for the plant to reach this height.

	Example

	For upSpeed = 100, downSpeed = 10, and desiredHeight = 910, the output should be
	solution(upSpeed, downSpeed, desiredHeight) = 10.

	#	Day	Night
	1	100	90
	2	190	180
	3	280	270
	4	370	360
	5	460	450
	6	550	540
	7	640	630
	8	730	720
	9	820	810
	10	910	900
	The plant first reaches a height of 910 on day 1

	A positive integer representing the daily growth of the plant.

	Guaranteed constraints:
	3 ≤ upSpeed ≤ 100.
	2 ≤ downSpeed < upSpeed.

*/

// https://app.codesignal.com/arcade/intro/level-9/xHvruDnQCx7mYom3T
int solution_growingPlant(int upSpeed, int downSpeed, int desiredHeight)
{
	int height = 0;
	int day = 0;
	while (1)
	{
		height += upSpeed;
		day++;
		if (height >= desiredHeight)
			return day;
		height -= downSpeed;
	}	
}

/*

	You found two items in a treasure chest! The first item weighs weight1 and is worth value1, and the second item weighs weight2 and is worth value2.
	What is the total maximum value of the items you can take with you, assuming that your max weight capacity is maxW and you can't come back for the items later?

	Note that there are only two items and you can't bring more than one item of each type,
	
	i.e. you can't take two first items or two second items.

	For value1 = 10, weight1 = 5, value2 = 6, weight2 = 4, and maxW = 8
 
	solution(value1, weight1, value2, weight2, maxW) = 10.

	value1 = 10, weight1 = 5, value2 = 6, weight2 = 4, and maxW = 9

	solution(value1, weight1, value2, weight2, maxW) = 16.

	For value1 = 5, weight1 = 3, value2 = 7, weight2 = 4, and maxW = 6
	
	solution(value1, weight1, value2, weight2, maxW) = 7.

	가방문제 (단순히 하나씩만 집어갈 수 있는 쓰레기 문제 같음 고민했던 내가 바보)
*/
// https://app.codesignal.com/arcade/intro/level-9/r9azLYp2BDZPyzaG2

int solution_KnapsackLight(int value1, int weight1, int value2, int weight2, int maxW)
{
	if (weight1 + weight2 <= maxW)
		return value1 + value2;
	else
	{
		if (weight1 <= maxW && weight2 <= maxW)
			return max(value1, value2);
		else if (weight1 <= maxW)
			return value1;
		else if (weight2 <= maxW)
			return value2;
		return 0;
	}
}

/*

	Given a string, output its longest prefix which contains only digits.
	
	A prefix is a non-empty string constructed from the first few characters of the string.

	For example, string s = "abaca" has five prefixes:

	"a"
	"ab"
	"aba"
	"abac"
	"abaca"

*/
// https://app.codesignal.com/arcade/intro/level-9/AACpNbZANCkhHWNs3
string solution_longestDigitsPrefix(string inputString)
{
	string answer = "";
	for (auto c : inputString)
	{
		if (isdigit(c))
			answer += c;
		else
			return answer;
	}
}
/*
	Let's define digit degree of some positive integer as the number of times we need to replace this number with the sum of its digits until we get to a one digit number.

	Given an integer, find its digit degree.

	For n = 5, the output should be
	solution(n) = 0;
	For n = 100, the output should be
	solution(n) = 1.
	1 + 0 + 0 = 1.
	For n = 91, the output should be
	solution(n) = 2.
	9 + 1 = 10 -> 1 + 0 = 1.
*/
// https://app.codesignal.com/arcade/intro/level-9/hoLtYWbjdrD2PF6yo
int solution_digitDegree(int n)
{
	int result = 0;
	while (n >= 10)
	{
		vector<int> tempV;
		while (n / 10 > 0)
		{
			tempV.push_back(n % 10);
			n /= 10;
		}
		n += accumulate(tempV.begin(), tempV.end(), 0);
		result++;
	}
	return result;
}


/*

	Given the positions of a white bishop and a black pawn on the standard chess board, determine whether the bishop can capture the pawn in one move.

	The bishop has no restrictions in distance for each move, but is limited to diagonal movement. Check out the example below to see how it can move:

	For bishop = "a1" and pawn = "c3", the output should be
	solution(bishop, pawn) = true.

	For bishop = "h1" and pawn = "h3", the output should be
	solution(bishop, pawn) = false.

*/

// https://app.codesignal.com/arcade/intro/level-9/6M57rMTFB9MeDeSWo
bool solution_BishopandPawn(string bishop, string pawn)
{
	return abs(bishop[0] - pawn[0]) == abs(bishop[1] - pawn[1]);
}