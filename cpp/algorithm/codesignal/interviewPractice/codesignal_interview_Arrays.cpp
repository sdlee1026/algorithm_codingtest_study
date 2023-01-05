#include "../../codeHeader.h"
#include "codesignal_interview_Arrays.h"
/*

    Given an array a that contains only numbers in the range from 1 to a.length, find the first duplicate number for which the second occurrence has the minimal index.
    
    In other words, if there are more than 1 duplicated numbers, return the number for which the second occurrence has a smaller index than the second occurrence of the other number does.
    
    If there are no such elements, return -1.

    Example

    For a = [2, 1, 3, 5, 3, 2], the output should be solution(a) = 3.

    There are 2 duplicates: numbers 2 and 3. The second occurrence of 3 has a smaller index than the second occurrence of 2 does, so the answer is 3.

    For a = [2, 2], the output should be solution(a) = 2;

    For a = [2, 4, 3, 5, 1], the output should be solution(a) = -1

    [input] array.integer a

    Guaranteed constraints:

    1 ¡Â a.length ¡Â 105,
    1 ¡Â a[i] ¡Â a.length.

*/
// https://app.codesignal.com/interview-practice/question/pMvymcahZ8dY4g75q/description
int solution_firstDuplicate(vector<int> a)
{
    vector<int>vec(a.size() + 1, 0);
    
    for (auto n : a)
    {
        if (vec[n] == 1)
            return n;
        vec[n]++;
    }
    return -1;
}

/*

    Given a string s consisting of small English letters, find and return the first instance of a non-repeating character in it.

    If there is no such character, return '_'.

    Example

    For s = "abacabad", the output should be
    solution(s) = 'c'.

    There are 2 non-repeating characters in the string: 'c' and 'd'. Return c since it appears in the string first.

    For s = "abacabaabacaba", the output should be
    solution(s) = '_'.

    There are no characters in this string that do not repeat.

    [input] string s

    A string that contains only lowercase English letters.

    Guaranteed constraints:
    1 ¡Â s.length ¡Â 105.

*/
// https://app.codesignal.com/interview-practice/question/uX5iLwhc6L5ckSyNC/description
char solution_firstNotRepeatingCharacter(string s)
{
    int count[26] = { 0, };
    for (auto str : s)
        count[int(str) - 97]++;
    for (auto str : s)
        if (count[int(str) - 97] == 1)
            return char(str);
    return '_';
}

/*

    Note: Try to solve this task in-place (with O(1) additional memory), since this is what you'll be asked to do during an interview.

    You are given an n x n 2D matrix that represents an image. Rotate the image by 90 degrees (clockwise).

    Example

    For

    a = [[1, 2, 3],
         [4, 5, 6],
         [7, 8, 9]]
    the output should be

    solution(a) =
        [[7, 4, 1],
         [8, 5, 2],
         [9, 6, 3]]

*/
// https://app.codesignal.com/interview-practice/question/5A8jwLGcEpTPyyjTB/description
vector<vector<int>> solution_rotateImage(vector<vector<int>> a)
{
    vector<vector<int>> v;
    int size = a.size();
    for (int i = 0; i < size; ++i)
    {
        vector <int> tempV;
        for (int j = 0; j < size; ++j)
            tempV.push_back(a[size - j - 1][i]);
        v.push_back(tempV);
    }
    return v;
}

/*

    Sudoku is a number-placement puzzle. The objective is to fill a 9 ¡¿ 9 grid with numbers in such a way that each column,
    
    each row, and each of the nine 3 ¡¿ 3 sub-grids that compose the grid all contain all of the numbers from 1 to 9 one time.

    Implement an algorithm that will check whether the given grid of numbers represents a valid Sudoku puzzle according to the layout rules described above.
    
    Note that the puzzle represented by grid does not have to be solvable.

    Example

    For

    grid = [['.', '.', '.', '1', '4', '.', '.', '2', '.'],
            ['.', '.', '6', '.', '.', '.', '.', '.', '.'],
            ['.', '.', '.', '.', '.', '.', '.', '.', '.'],
            ['.', '.', '1', '.', '.', '.', '.', '.', '.'],
            ['.', '6', '7', '.', '.', '.', '.', '.', '9'],
            ['.', '.', '.', '.', '.', '.', '8', '1', '.'],
            ['.', '3', '.', '.', '.', '.', '.', '.', '6'],
            ['.', '.', '.', '.', '.', '7', '.', '.', '.'],
            ['.', '.', '.', '5', '.', '.', '.', '7', '.']]
    the output should be
    solution(grid) = true;

    For

    grid = [['.', '.', '.', '.', '2', '.', '.', '9', '.'],
            ['.', '.', '.', '.', '6', '.', '.', '.', '.'],
            ['7', '1', '.', '.', '7', '5', '.', '.', '.'],
            ['.', '7', '.', '.', '.', '.', '.', '.', '.'],
            ['.', '.', '.', '.', '8', '3', '.', '.', '.'],
            ['.', '.', '8', '.', '.', '7', '.', '6', '.'],
            ['.', '.', '.', '.', '.', '2', '.', '.', '.'],
            ['.', '1', '.', '2', '.', '.', '.', '.', '.'],
            ['.', '2', '.', '.', '3', '.', '.', '.', '.']]
    the output should be
    solution(grid) = false.

    The given grid is not correct because there are two 1s in the second column. Each column, each row, and each 3 ¡¿ 3 subgrid can only contain the numbers 1 through 9 one time.

    Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] array.array.char grid

    A 9 ¡¿ 9 array of characters, in which each character is either a digit from '1' to '9' or a period '.'.

    [output] boolean

    Return true if grid represents a valid Sudoku puzzle, otherwise return false.

*/
// https://app.codesignal.com/interview-practice/question/SKZ45AF99NpbnvgTn/description

bool solution_sudoku2(vector<vector<char>> grid)
{
    for (auto row : grid)
    {
        vector<int> rowCheck(9, 0);
        for (auto n : row)
            if (n != '.')
                rowCheck[int(n) - 49]++;
        for (auto n : rowCheck)
            if (n > 1)
                return false;
    }
    for (int i = 0; i < grid.size(); ++i)
    {
        vector<int> colCheck(9, 0);
        for (int j = 0; j < grid.size(); ++j)
            if (grid[j][i] != '.')
                colCheck[int(grid[j][i] - 49)]++;
        for (auto n : colCheck)
            if (n > 1)
                return false;
    }
    for (int i = 0; i < grid.size(); i += 3)
        for (int j = 0; j < grid.size(); j += 3)
        {
            vector<int> check(9, 0);
            if (grid[i][j] != '.')      check[int(grid[i][j]) - 49]++;
            if (grid[i][j + 1] != '.')    check[int(grid[i][j + 1]) - 49]++;
            if (grid[i][j + 2] != '.')    check[int(grid[i][j + 2]) - 49]++;
            if (grid[i + 1][j] != '.')    check[int(grid[i + 1][j]) - 49]++;
            if (grid[i + 1][j + 1] != '.')  check[int(grid[i + 1][j + 1]) - 49]++;
            if (grid[i + 1][j + 2] != '.')  check[int(grid[i + 1][j + 2]) - 49]++;
            if (grid[i + 2][j] != '.')    check[int(grid[i + 2][j]) - 49]++;
            if (grid[i + 2][j + 1] != '.')  check[int(grid[i + 2][j + 1]) - 49]++;
            if (grid[i + 2][j + 2] != '.')  check[int(grid[i + 2][j + 2]) - 49]++;
            for (auto n : check)
                if (n > 1)
                    return false;
            check.clear();
        }

    return true;
}