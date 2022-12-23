#include "../../codeHeader.h"
#include "codesignal_arcade_RainbowOfClarity.h"

/*

	Determine if the given character is a digit or not.

	A character which is either a digit or not.

	Guaranteed constraints:
	Given symbol is from ASCII table.

	[output] boolean

	true if symbol is a digit, false otherwise
*/
// https://app.codesignal.com/arcade/intro/level-11/Zr2XXEpkBPtYWqPJu
bool solution_isDigit(char symbol)
{
	return isdigit(symbol);
}

/*

	Given a string, return its encoding defined as follows:

	First, the string is divided into the least possible number of disjoint substrings consisting of identical characters
	for example, "aabbbc" is divided into ["aa", "bbb", "c"]
	Next, each substring with length greater than one is replaced with a concatenation of its length and the repeating character
	for example, substring "bbb" is replaced by "3b"
	Finally, all the new strings are concatenated together in the same order and a new string is returned.
	Example

	For s = "aabbbc", the output should be
	solution(s) = "2a3bc".

*/
// https://app.codesignal.com/arcade/intro/level-11/o2uq6eTuvk7atGadR
string solution_lineEncoding(string s)
{
	string strToken = string(s.begin(), s.begin()+1), answer = "";
	s = string(s.begin() + 1, s.end());

	for (auto& c : s)
	{
		if (*(strToken.end() - 1) != c)
		{
			if (strToken.size() > 1)
				answer += to_string(strToken.size()) + strToken.at(0);
			else
				answer += strToken;
			strToken = "";
		}
		strToken += c;
	}
	if (strToken.size() > 1)
		return answer += to_string(strToken.size()) + strToken.at(0);
	else
		return answer += strToken;
}

/*

	Given a position of a knight on the standard chessboard, find the number of different moves the knight can perform.

	The knight can move to a square that is two squares horizontally and one square vertically, or two squares vertically and one square horizontally away from it.
	The complete move therefore looks like the letter L. Check out the image below to see all valid moves for a knight piece that is placed on one of the central squares.


	Example

	For cell = "a1", the output should be
	solution(cell) = 2.
	
	For cell = "c2", the output should be
	solution(cell) = 6.

	input 

	String consisting of 2 letters - coordinates of the knight on an 8 ¡¿ 8 chessboard in chess notation.
*/

// https://app.codesignal.com/arcade/intro/level-11/pwRLrkrNpnsbgMndb
int solution_chessKnight(string cell)
{
	int board[12][12] = { -1, };
	for (int i = 2; i < 10; i++)
		for (int j = 2; j < 10; j++)
			board[i][j] = 0;

	int vecX = int(cell[0] - 'a') + 2;
	int vecY = int(cell[1] - '1') + 2;
	int answer = 0;

	board[vecX - 2][vecY + 1]++; board[vecX - 2][vecY - 1]++; board[vecX + 2][vecY + 1]++; board[vecX + 2][vecY - 1]++;
	board[vecX - 1][vecY + 2]++; board[vecX - 1][vecY - 2]++; board[vecX + 1][vecY + 2]++; board[vecX + 1][vecY - 2]++;

	for (int i = 2; i < 10; i++)
		for (int j = 2; j < 10; j++)
			answer += board[i][j];

	return answer;
}

/*

	Given some integer, find the maximal number you can obtain by deleting exactly one digit of the given number.
	Example

	For n = 152, the output should be
	solution(n) = 52;
	For n = 1001, the output should be
	solution(n) = 101.

*/
// https://app.codesignal.com/arcade/intro/level-11/vpfeqDwGZSzYNm2uX
int solution_deleteDigit(int n)
{
	vector<int> numVec;
	string numStr = to_string(n);

	for (int i = 0; i < numStr.size(); i++)
		numVec.push_back(stoi(string(numStr.begin(), numStr.begin() + i) + string(numStr.begin() + i + 1, numStr.end())));
	return *max_element(numVec.begin(), numVec.end());
}