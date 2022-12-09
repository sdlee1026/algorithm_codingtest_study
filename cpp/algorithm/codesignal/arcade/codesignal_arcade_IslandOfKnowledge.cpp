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

/*

	An IP address is a numerical label assigned to each device (e.g., computer, printer) participating in a computer network that uses the Internet Protocol for communication.
	There are two versions of the Internet protocol, and thus two versions of addresses. One of them is the IPv4 address.

	Given a string, find out if it satisfies the IPv4 address naming rules.

		An identification number for devices connected to the internet. An IPv4 addresses written in dotted quad notation consists of four 8-bit integers separated by periods.

		In other words, it's a string of four numbers each between 0 and 255 inclusive, with a "." character in between each number. All numbers should be present without leading zeros.

		Examples:

		192.168.0.1
		is a valid IPv4 address
		255.255.255.255
		is a valid IPv4 address
		280.100.92.101
		is not a valid IPv4 address because 280 is too large to be an 8-bit integer (the largest 8-bit integer is 255)
		255.100.81.160.172
		is not a valid IPv4 address because it contains 5 integers instead of 4
		1..0.1
		is not a valid IPv4 address because it's not properly formatted
		17.233.00.131 and 17.233.01.131
		are not valid IPv4 addresses because they contain leading zeros

	Example

	For inputString = "172.16.254.1", the output should be
	solution(inputString) = true;

	For inputString = "172.316.254.1", the output should be
	solution(inputString) = false.

	316 is not in range [0, 255].

	For inputString = ".254.255.0", the output should be
	solution(inputString) = false.

	There is no first number.

*/

// https://app.codesignal.com/arcade/intro/level-5/veW5xJednTy4qcjso

bool solution_isIPv4Address(string inputString)
{
	int prev = 0, strC = 0;
	int split = inputString.find('.');
	inputString += '.';
	while (split != string::npos)
	{
		string subStr = inputString.substr(prev, split - prev);
		if (subStr.size() == 0 || subStr.size() > 3)
			return false;
		prev = split + 1;
		for (auto& s : subStr)
		{
			if (s < '0' || s > '9')
				return false;
		}
		int subStrInt = stoi(subStr.c_str());
		if (to_string(subStrInt) != subStr || subStrInt > 255)
			return false;
		split = inputString.find('.', prev);
		strC++;
	}
	if (strC != 4)
		return false;
	return true;
}

/*

	You are given an array of integers representing coordinates of obstacles situated on a straight line.

	Assume that you are jumping from the point with coordinate 0 to the right. You are allowed only to make jumps of the same length represented by some integer.

	Find the minimal length of the jump enough to avoid all the obstacles.

	For inputArray = [5, 3, 6, 7, 9], the output should be
	solution(inputArray) = 4.

	Check out the image below for better understanding:
*/
// https://app.codesignal.com/arcade/intro/level-5/XC9Q2DhRRKQrfLhb5
int solution_avoidObstacles(vector<int> inputArray)
{
	for (int jump = 1; ; ++jump)
	{
		bool jumpAble = false;
		for (int index = 0; index < inputArray.size() && jumpAble == false; ++index)
		{
			if (inputArray[index] % jump == 0)
				jumpAble = true;
		}
		if (jumpAble == false)
			return jump;
	}
}

/*

	Last night you partied a little too hard.
	Now there's a black and white photo of you that's about to go viral! You can't let this ruin your reputation,
	so you want to apply the box blur algorithm to the photo to hide its content.

	The pixels in the input image are represented as integers.

	The algorithm distorts the input image in the following way:

		Every pixel x in the output image has a value equal to the average value of the pixel values
		from the 3 ¡¿ 3 square that has its center at x, including x itself.
		All the pixels on the border of x are then removed.

	Return the blurred image as an integer, with the fractions rounded down.

	Example

	For

	image = [[1, 1, 1],
			 [1, 7, 1],
			 [1, 1, 1]]
	the output should be solution(image) = [[1]].

	To get the value of the middle pixel in the input 3 ¡¿ 3 square: (1 + 1 + 1 + 1 + 7 + 1 + 1 + 1 + 1) = 15 / 9 = 1.66666 = 1. The border pixels are cropped from the final result.

	For

	image = [[7, 4, 0, 1],
			 [5, 6, 2, 2],
			 [6, 10, 7, 8],
			 [1, 4, 2, 0]]
	the output should be

	solution(image) = [[5, 4],
					  [4, 4]]
	There are four 3 ¡¿ 3 squares in the input image, so there should be four integers in the blurred output.
	To get the first value:
		(7 + 4 + 0 + 5 + 6 + 2 + 6 + 10 + 7) = 47 / 9 = 5.2222 = 5. The other three integers are obtained the same way, then the surrounding integers are cropped from the final result.

*/

// https://app.codesignal.com/arcade/intro/level-5/5xPitc3yT3dqS7XkP
vector<vector<int>> solution_BoxBlur(vector<vector<int>> image)
{
	vector<vector<int>> answer;

	int sizeI = image.size();
	int sizeJ = image[0].size();

	for (int i = 0; i <= sizeI - 3; i++)
	{
		vector<int> pushVec;
		for (int j = 0; j <= sizeJ - 3; j++)
		{
			pushVec.push_back(floor((image[i][j] + image[i][j + 1] + image[i][j + 2] +
				image[i + 1][j] + image[i + 1][j + 1] + image[i + 1][j + 2] +
				image[i + 2][j] + image[i + 2][j + 1] + image[i + 2][j + 2]) / 9.0f));
		}
		answer.push_back(pushVec);
	}
	return answer;
}

	/*
	In the popular Minesweeper game you have a board with some mines and those cells that
	don't contain a mine have a number in it that indicates the total number of mines in the neighboring cells.
	Starting off with some arrangement of mines we want to create a Minesweeper game setup.

	Example

	For

	matrix = [[true, false, false],
			  [false, true, false],
			  [false, false, false]]
	the output should be

	solution(matrix) = [[1, 2, 1],
						[2, 1, 1],
						[1, 1, 1]]
	Check out the image below for better understanding:

*/

//https://app.codesignal.com/arcade/intro/level-5/ZMR5n7vJbexnLrgaM

vector<vector<int>> solution_Minesweeper(vector<vector<bool>> matrix)
{	
	int sizeI = matrix.size();
	int sizeJ = matrix[0].size();
	vector < vector<int>> answer;
	for (int i = 0; i < sizeI+2; i++)
	{
		vector<int> tempVec2;
		for (int j = 0; j < sizeJ+2; j++)
			tempVec2.push_back(0);
		answer.push_back(tempVec2);
	}
	
	for (int i = 0; i < sizeI; i++)
	{
		for (int j = 0; j < sizeJ; j++)
		{
			if (matrix[i][j] == true)
			{
				answer[i][j]++;
				answer[i][j + 1]++;
				answer[i][j + 2]++;
				answer[i + 1][j]++;
				answer[i + 1][j + 2]++;
				answer[i + 2][j]++;
				answer[i + 2][j + 1]++;
				answer[i + 2][j + 2]++;
			}
		}
	}
	answer.erase(answer.begin());
	answer.pop_back();
	for (auto& vec : answer)
	{
		if (!vec.empty())
		{
			vec.erase(vec.begin());
			vec.pop_back();
		}
	}
	return answer;
}