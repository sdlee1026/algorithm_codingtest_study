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

}