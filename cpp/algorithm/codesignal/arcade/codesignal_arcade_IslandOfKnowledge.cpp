#include "../../codeHeader.h"
#include "codesignal_arcade_IslandOfKnowledge.h"


/*

	Call two arms equally strong if the heaviest weights they each are able to lift are equal.

	Call two people equally strong if their strongest arms are equally strong (the strongest arm can be both the right and the left), and so are their weakest arms.

	Given your and your friend's arms' lifting capabilities find out if you two are equally strong.

	Example

	For yourLeft = 10, yourRight = 15, friendsLeft = 15, and friendsRight = 10, the output should be
	solution(yourLeft, yourRight, friendsLeft, friendsRight) = true;
	For yourLeft = 15, yourRight = 10, friendsLeft = 15, and friendsRight = 10, the output should be
	solution(yourLeft, yourRight, friendsLeft, friendsRight) = true;
	For yourLeft = 15, yourRight = 10, friendsLeft = 15, and friendsRight = 9, the output should be
	solution(yourLeft, yourRight, friendsLeft, friendsRight) = false.

	true if you and your friend are equally strong, false otherwise.


	yourLeft: 10
	yourRight: 15
	friendsLeft: 15
	friendsRight: 10
	Expected Output:
	true
*/

// https://app.codesignal.com/arcade/intro/level-5/g6dc9KJyxmFjB98dL
bool solution_areEquallyStrong(int yourLeft, int yourRight, int friendsLeft, int friendsRight)
{
	auto you = minmax(yourLeft, yourRight);
	auto friends = minmax(friendsLeft, friendsRight);
	return you.first == friends.first && you.second == friends.second;
}


/*

	Given an array of integers, find the maximal absolute difference between any two of its adjacent elements.

	Example

	For inputArray = [2, 4, 1, 0], the output should be
	solution(inputArray) = 3.

	Input/Output

	[execution time limit] 0.5 seconds (cpp)

	[input] array.integer inputArray

	Guaranteed constraints:
	3 ¡Â inputArray.length ¡Â 10,
	-15 ¡Â inputArray[i] ¡Â 15.

*/

// https://app.codesignal.com/arcade/intro/level-5/EEJxjQ7oo7C5wAGjE
int solution_arrayMaximalAdjacentDifference(vector<int> inputArray)
{
	int answer = 0;
	for (int i = 0; i < inputArray.size() - 1; i++)
	{
		int n = abs(inputArray[i] - inputArray[i + 1]);
		if (answer < n)
			answer = n;
	}
	return answer;
}