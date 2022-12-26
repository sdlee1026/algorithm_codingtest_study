#include "../../codeHeader.h"
#include "codesignal_arcade_LandOfLogic.h"

/*

	Define a word as a sequence of consecutive English letters. Find the longest word from the given string.
	
	Example

	For text = "Ready, steady, go!", the output should be
	solution(text) = "steady".
*/
// https://app.codesignal.com/arcade/intro/level-12/s9qvXv4yTaWg8g4ma
string solution_longestWord(string text)
{
	vector<string> stringVec;
	string tempStr = "";
	int maxlen = 0, index = 0, maxIndex = -1;
	text += '@';
	for (auto& c : text)
	{
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
			tempStr += c;
		else if (tempStr.size() > 0)
		{
			stringVec.push_back(tempStr);
			tempStr = "";
		}
	}

	for (auto& s : stringVec)
	{
		if (s.size() > maxlen)
		{
			maxlen = s.size();
			maxIndex = index;
		}
		index++;
	}
	return stringVec[maxIndex];
}

/*

	Check if the given string is a correct time representation of the 24-hour clock.

	Example

	For time = "13:58", the output should be
	solution(time) = true;
	For time = "25:51", the output should be
	solution(time) = false;
	For time = "02:76", the output should be
	solution(time) = false.
*/
// https://app.codesignal.com/arcade/intro/level-12/ywMyCTspqGXPWRZx5
bool solution_ValidTime(string time)
{
	int first = stoi(time.substr(0, time.find(':')));
	int second = stoi(time.substr(time.find(':') + 1));
	if (first >= 0 && first < 24 && second >= 0 && second < 60)
		return true;
	return false;
}

/*

	CodeMaster has just returned from shopping. He scanned the check of the items he bought and gave the resulting string to Ratiorg to figure out the total number of purchased items. Since Ratiorg is a bot he is definitely going to automate it, so he needs a program that sums up all the numbers which appear in the given input.

	Help Ratiorg by writing a function that returns the sum of numbers that appear in the given inputString.

	Example

	For inputString = "2 apples, 12 oranges", the output should be
	solution(inputString) = 14.

*/
// https://app.codesignal.com/arcade/intro/level-12/YqZwMJguZBY7Hz84T
int solution_sumUpNumbers(string inputString)
{
	int answer = 0;
	string str = "";
	inputString.push_back('@');
	for (auto& c : inputString)
	{
		if (isdigit(c))
			str += c;
		else if (str.size() > 0)
		{
			answer += stoi(str);
			str = "";
		}
	}
	return answer;
}

/*

	Given a rectangular matrix containing only digits, calculate the number of different 2 ¡¿ 2 squares in it.

	Example

	For

	matrix = [[1, 2, 1],
			  [2, 2, 2],
			  [2, 2, 2],
			  [1, 2, 3],
			  [2, 2, 1]]
		  
	the output should be
	solution(matrix) = 6.

	Here are all 6 different 2 ¡¿ 2 squares:

	1 2
	2 2,
	2 1
	2 2,
	2 2
	2 2,
	2 2
	1 2,
	2 2
	2 3,
	2 3
	2 1
*/
// https://app.codesignal.com/arcade/intro/level-12/fQpfgxiY6aGiGHLtv
int solution_DifferentSquares(vector<vector<int>> matrix)
{
	set<vector<int>> setSq;
	for (int i = 0; i < matrix.size() - 1; i++)
		for (int j = 0; j < matrix[i].size() - 1; j++)
			setSq.insert({ matrix[i][j], matrix[i][j + 1], matrix[i + 1][j], matrix[i + 1][j + 1] });
	return setSq.size();
}
/*

	Given an integer product, find the smallest positive (i.e. greater than 0) integer the product of whose digits is equal to product. If there is no such integer, return -1 instead.

	Example

	For product = 12, the output should be
	solution(product) = 26;
		-> 2 * 6 = 12
		-> 4 * 3 = 12
			-> 26<43 ~ answer = 26
	For product = 19, the output should be
	solution(product) = -1.

*/
// https://app.codesignal.com/arcade/intro/level-12/NJJhENpgheFRQbPRA
int solution_digitsProduct(int product)
{
	if (product == 0)
		return 10;
	else if (product < 10)
		return product;

	string answer = "";
	for (int divNum = 9; divNum > 1; divNum--)
		for (; product % divNum == 0; product /= divNum)
			answer = to_string(divNum) + answer;

	return product == 1 ? stoi(answer) : -1;
}

/*
	You are given an array of strings names representing filenames. The array is sorted in order of file creation, such that names[i] represents the name of a file created before names[i+1] and after names[i-1] (assume 0-based indexing). Because all files must have unique names, files created later with the same name as a file created earlier should have an additional (k) suffix in their names, where k is the smallest positive integer (starting from 1) that does not appear in previous file names.

	Your task is to iterate through all elements of names (from left to right) and update all filenames based on the above. Return an array of proper filenames.

	Example

	For names = ["doc", "doc", "image", "doc(1)", "doc"], the output should be solution(names) = ["doc", "doc(1)", "image", "doc(1)(1)", "doc(2)"].

	Since names[0] = "doc" and names[1] = "doc", update names[1] = "doc(1)"
	Since names[1] = "doc(1)" and names[3] = "doc(1)", update names{3} = "doc(1)(1)"
	Since names[0] = "doc", names[1] = "doc(1)", and names[4] = "doc", update names[4] = "doc(2)"
*/
// https://app.codesignal.com/arcade/intro/level-12/sqZ9qDTFHXBNrQeLC
vector<string> solution_FileNaming(vector<string> names)
{
	map<string, int> mapStr;
	for (auto& s : names)
	{
		if (mapStr.find(s) != mapStr.end())
		{
			string tempS = "(" + to_string(mapStr[s]) + ")";
			while (mapStr.find(s + tempS) != mapStr.end())
			{
				mapStr[s]++;
				tempS = "(" + to_string(mapStr[s]) + ")";
			}
			mapStr[s]++;
			s += tempS;
			mapStr[s] = 1;
		}
		else
			mapStr[s] = 1;
	}
	return names;
}
/*

	You are taking part in an Escape Room challenge designed specifically for programmers.
	In your efforts to find a clue, you've found a binary code written on the wall behind a vase, and realized that it must be an encrypted message.
	After some thought, your first guess is that each consecutive 8 bits of the code stand for the character with the corresponding extended ASCII code.

	Assuming that your hunch is correct, decode the message.

	Example

	For code = "010010000110010101101100011011000110111100100001", the output should be
	solution(code) = "Hello!".

	The first 8 characters of the code are 01001000, which is 72 in the binary numeral system. 72 stands for H in the ASCII-table, so the first letter is H.
	Other letters can be obtained in the same manner.

*/
// https://app.codesignal.com/arcade/intro/level-12/sCpwzJCyBy2tDSxKW

string solution_messageFromBinaryCode(string code)
{
	string answer = "";
	int count = 0;
	while (count != code.size() / 8)
	{
		string s = code.substr(count * 8, 8);
		answer += messageFromBinaryCode_convert(stoi(s));
		count++;
	}
	return answer;
}
char messageFromBinaryCode_convert(int n)
{
	int dec = 0, i = 0, rem;
	while (n != 0)
	{
		rem = n % 10;
		n /= 10;
		dec += rem * pow(2, i);
		++i;
	}
	return (char)dec;
}
/*

	Construct a square matrix with a size N ¡¿ N containing integers from 1 to N * N in a spiral order, starting from top-left and in clockwise direction.
	
	Example

	For n = 3, the output should be

	solution(n) = [[1, 2, 3],
					[8, 9, 4],
					[7, 6, 5]]
*/
// https://app.codesignal.com/arcade/intro/level-12/uRWu6K8E7uLi3Qtvx
vector<vector<int>> solution_spiralNumbers(int n)
{
	vector<vector<int>> vec;
	vector<int> tempV;
	for (int i = 0; i < n; i++)
		tempV.push_back(0);
	for (int i = 0; i < n; i++)
		vec.push_back(tempV);
	int insertN = 1;
	int left = 0, right = n - 1, top = 0, down = n - 1;
	while (insertN < (n * n) + 1)
	{
		for (int x = left; x <= right; x++)
			vec[top][x] = insertN++;
		top++;
		for (int y = top; y <= down; y++)
			vec[y][right] = insertN++;
		right--;
		for (int x = right; x >= left; x--)
			vec[down][x] = insertN++;
		down--;
		for (int y = down; y >= top; y--)
			vec[y][left] = insertN++;
		left++;
	}
	return vec;
}

/*

	Sudoku is a number-placement puzzle. The objective is to fill a 9 ¡¿ 9 grid with digits so that each column,
	each row, and each of the nine 3 ¡¿ 3 sub-grids that compose the grid contains all of the digits from 1 to 9.

	This algorithm should check if the given grid of numbers represents a correct solution to Sudoku.

	grid = [[1, 3, 2, 5, 4, 6, 9, 8, 7],
		[4, 6, 5, 8, 7, 9, 3, 2, 1],
		[7, 9, 8, 2, 1, 3, 6, 5, 4],
		[9, 2, 1, 4, 3, 5, 8, 7, 6],
		[3, 5, 4, 7, 6, 8, 2, 1, 9],
		[6, 8, 7, 1, 9, 2, 5, 4, 3],
		[5, 7, 6, 9, 8, 1, 4, 3, 2],
		[2, 4, 3, 6, 5, 7, 1, 9, 8],
		[8, 1, 9, 3, 2, 4, 7, 6, 5]]

	the output should be
	solution(grid) = true;
*/
// https://app.codesignal.com/arcade/intro/level-12/tQgasP8b62JBeirMS
bool solution_Sudoku(vector<vector<int>> grid)
{
	for (auto& row : grid)
	{
		set<int> tempSet;
		for (auto& num : row)
			if (tempSet.find(num) == tempSet.end())
				tempSet.insert(num);
			else
				return false;
	}
	for (int j = 0; j < grid.size(); j++)
	{
		set<int> tempSet;
		for (int i = 0; i < grid.size(); i++)
		{
			if (tempSet.find(grid[i][j]) == tempSet.end())
				tempSet.insert(grid[i][j]);
			else
				return false;
		}		
	}
	int widthStart = 0, heightStart = 0;
	while (!(heightStart == grid.size()))
	{
		set<int>tempSet;
		for (int i = heightStart; i < heightStart + 3; i++)
		{
			for (int j = widthStart; j < widthStart + 3; j++)
			{
				if (tempSet.find(grid[i][j]) == tempSet.end())
					tempSet.insert(grid[i][j]);
				else
					return false;
			}
		}
		if (widthStart < 6)
			widthStart += 3;
		else
		{
			heightStart += 3;
			widthStart = 0;
		}			
	}
	return true;
}
