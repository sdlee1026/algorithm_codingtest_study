#include "../../codeHeader.h"
#include "codesignal_arcade_EdgeOfTheOcean.h"
/*
	Given an array of integers, find the pair of adjacent elements that has the largest product and return that product.

	Example

	For inputArray = [3, 6, -2, -5, 7, 3], the output should be
	solution(inputArray) = 21.

	7 and 3 produce the largest product.

	Input/Output

	[execution time limit] 0.5 seconds (cpp)

	[input] array.integer inputArray

	An array of integers containing at least two elements.

	Guaranteed constraints:
	2 ≤ inputArray.length ≤ 10,
	-1000 ≤ inputArray[i] ≤ 1000.

	[output] integer

	The largest product of adjacent elements.
*/
//https://app.codesignal.com/arcade/intro/level-2/xzKiBHjhoinnpdh6m
int solution_adjacentElementsProduct(vector<int> inputArray)
{
	int max = inputArray[0] * inputArray[1];
	for (int i = 0; i < inputArray.size() - 1; i++)
	{
		if (max < inputArray[i] * inputArray[i+1])
			max = inputArray[i] * inputArray[i+1];
	}
	return max;
}

/*
	Below we will define an n-interesting polygon. Your task is to find the area of a polygon for a given n.
	A 1-interesting polygon is just a square with a side of length 1.
	An n-interesting polygon is obtained by taking the n - 1-interesting polygon and appending 1-interesting polygons to its rim, side by side.
	You can see the 1-, 2-, 3- and 4-interesting polygons in the picture below.

	For n = 2, the output should be
	solution(n) = 5;
	For n = 3, the output should be
	solution(n) = 13.

	[input] integer n

	Guaranteed constraints:
	1 ≤ n < 104.

	[output] integer
*/
// https://app.codesignal.com/arcade/intro/level-2/yuGuHvcCaFCKk56rJ
int ary_shapeArea[10000] = { 0, };
int solve_shapeArea(int n)
{
	if (n == 1)
		return 1;
	else
	{
		if (ary_shapeArea[n] != 0)
			return ary_shapeArea[n];
		else
		{
			ary_shapeArea[n] = (4 * (n - 1)) + solve_shapeArea(n - 1);
			return ary_shapeArea[n];
		}
	}
}
int solution_shapeArea(int n)
{
	return solve_shapeArea(n);
}


/*
	Ratiorg got statues of different sizes as a present from CodeMaster for his birthday, each statue having an non-negative integer size.
	Since he likes to make things perfect, he wants to arrange them from smallest to largest so that each statue will be bigger than the previous one exactly by 1.
	He may need some additional statues to be able to accomplish that.
	Help him figure out the minimum number of additional statues needed.

	Example

	For statues = [6, 2, 3, 8], the output should be
	solution(statues) = 3.

	Ratiorg needs statues of sizes 4, 5 and 7.

	[input] array.integer statues

	An array of distinct non-negative integers.

	Guaranteed constraints:
	1 ≤ statues.length ≤ 10,
	0 ≤ statues[i] ≤ 20.

	[output] integer

	The minimal number of statues that need to be added to existing statues such that it contains every integer size from an interval [L, R] (for some L, R) and no other sizes.
*/
//https://app.codesignal.com/arcade/intro/level-2/bq2XnSr5kbHqpHGJC

int solution_MakeArrayConsecutive2(vector<int> statues)
{
	auto minmax = minmax_element(statues.begin(), statues.end());
	return (*minmax.second - *minmax.first + 1) - statues.size();
}
/*
	Given a sequence of integers as an array, determine whether it is possible to obtain a strictly increasing sequence by removing no more than one element from the array.

	Note: 
	sequence a0, a1, ..., an is considered to be a strictly increasing if a0 < a1 < ... < an.
	
	Sequence containing only one element is also considered to be strictly increasing.

	Example

	For sequence = [1, 3, 2, 1], the output should be
	solution(sequence) = false.

	There is no one element in this array that can be removed in order to get a strictly increasing sequence.

	For sequence = [1, 3, 2], the output should be
	solution(sequence) = true.

	You can remove 3 from the array to get the strictly increasing sequence [1, 2]. Alternately, you can remove 2 to get the strictly increasing sequence [1, 3].

	[input] array.integer sequence

	Guaranteed constraints:
	2 ≤ sequence.length ≤ 105,
	-105 ≤ sequence[i] ≤ 105.

	[output] boolean

	Return true if it is possible to remove one element from the array in order to get a strictly increasing sequence, otherwise return false.
*/
//https://app.codesignal.com/arcade/intro/level-2/2mxbGwLzvkTCKAJMG

bool solution_almostIncreasingSequence(vector<int> sequence)
{
	bool answer = true;
	int breakingIndex = -1;
	for (int i = 0; i < sequence.size() - 1; i++)
	{
		if (sequence[i] >= sequence[i + 1])
		{
			breakingIndex = i;
			break;
		}
	}
	if (breakingIndex == -1) return true;
	auto tempSeq = sequence;
	sequence.erase(sequence.begin() + breakingIndex);
	tempSeq.erase(tempSeq.begin() + breakingIndex + 1);
	bool answer_0 = true, answer_1 = true;
	for (int i = 0; i < sequence.size() - 1; i++)
	{
		if (sequence[i] >= sequence[i + 1])
			answer_0 = false;
		if (tempSeq[i] >= tempSeq[i + 1])
			answer_1 = false;
		if (answer_0 == false && answer_1 == false)
			return false;
	}
	return true;
}

/*
	After becoming famous, the CodeBots decided to move into a new building together.
	Each of the rooms has a different cost, and some of them are free, but there's a rumour that all the free rooms are haunted! Since the CodeBots are quite superstitious,
	they refuse to stay in any of the free rooms, or any of the rooms below any of the free rooms.

	Given matrix, a rectangular matrix of integers, where each value represents the cost of the room,
	your task is to return the total sum of all rooms that are suitable for the CodeBots (ie: add up all the values that don't appear below a 0).

	유령이 있는 공간은 0, 그 아래 칸은 구하지 않는다

	matrix = [[0, 1, 1, 2],
		  [0, 5, 0, 0],
		  [2, 0, 3, 3]]
	
	solution(matrix) = 9.

	matrix = [[1, 1, 1, 0],
		  [0, 5, 0, 1],
		  [2, 1, 3, 10]]

	solution(matrix) = 9
*/
// https://app.codesignal.com/arcade/intro/level-2/xskq4ZxLyqQMCLshr
int solution_matrixElementsSum(vector<vector<int>> matrix)
{
	vector<int> continueCol;
	int answer = 0;
	for (vector<int> mat : matrix)
	{
		for (int i = 0; i < mat.size(); i++)
		{
			if (find(continueCol.begin(), continueCol.end(), i) != continueCol.end())
				continue;
			if (mat[i] == 0)
				continueCol.push_back(i);
			else
				answer += mat[i];
		}
	}
	return answer;
}