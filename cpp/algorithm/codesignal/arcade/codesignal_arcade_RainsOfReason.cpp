#include "../../codeHeader.h"
#include "codesignal_arcade_RainsOfReason.h"


/*

    Given an array of integers, replace all the occurrences of elemToReplace with substitutionElem.

    Example

    For inputArray = [1, 2, 1], elemToReplace = 1, and substitutionElem = 3, the output should be
    solution(inputArray, elemToReplace, substitutionElem) = [3, 2, 3].

*/
// https://app.codesignal.com/arcade/intro/level-6/mCkmbxdMsMTjBc3Bm
vector<int> solution_ArrayReplace(vector<int> inputArray, int elemToReplace, int substitutionElem)
{
    for (auto& i : inputArray)
    {
        if (i == elemToReplace)
            i = substitutionElem;
    }
    return inputArray;
}

/*

    Check if all digits of the given integer are even.

    Example

    For n = 248622, the output should be
    solution(n) = true;
    For n = 642386, the output should be
    solution(n) = false.

*/
// https://app.codesignal.com/arcade/intro/level-6/6cmcmszJQr6GQzRwW
bool solution_evenDigitsOnly(int n)
{
    for (auto& s : to_string(n))
        if (int(s) % 2 != 0)
            return false;
    return true;
}

/*

    Correct variable names consist only of English letters, digits and underscores and they can't start with a digit.

    Check if the given string is a correct variable name.

    Example

    For name = "var_1__Int", the output should be
    solution(name) = true;
    For name = "qq-q", the output should be
    solution(name) = false;
    For name = "2w2", the output should be
    solution(name) = false.

    [input] string name

    Guaranteed constraints:
    1 ¡Â name.length ¡Â 10.
*/
// https://app.codesignal.com/arcade/intro/level-6/6Wv4WsrsMJ8Y2Fwno

bool solution_variableName(string name)
{
    if (name[0] >= '0' && name[0] <= '9')
        return false;
    for (char c : name)
    {
        if (c == '_')
            continue;
        else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            continue;
        else
            return false;
    }
    return true;
}
bool solution_variableNameRegex(string name)
{
    regex r("[_a-zA-Z][_a-zA-Z0-9]*");
    return regex_match(name, r);
}

/*

    Given a string, your task is to replace each of its characters by the next one in the English alphabet; i.e. replace a with b, replace b with c, etc (z would be replaced by a).

    Example

    For inputString = "crazy", the output should be solution(inputString) = "dsbaz".

*/
// https://app.codesignal.com/arcade/intro/level-6/PWLT8GBrv9xXy4Dui

string solution_alphabeticShift(string inputString)
{
    for (char &c : inputString)
    {
        if (c == 'z')
            c = 'a';
        else
            c++;
    }
    return inputString;
}

/*

    Given two cells on the standard chess board, determine whether they have the same color or not.

    Example

    For cell1 = "A1" and cell2 = "C3", the output should be
    solution(cell1, cell2) = true.

*/
// https://app.codesignal.com/arcade/intro/level-6/t97bpjfrMDZH8GJhi/solutions

bool solution_chessBoardCellColor(string cell1, string cell2)
{
    return ((cell1[0] + cell1[1]) % 2) == ((cell2[0] + cell2[1]) % 2);
    // A 65
    // H 72
}