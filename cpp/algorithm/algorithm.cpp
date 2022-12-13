#include "codeHeader.h"
#include "programmers/programmers_118667.h"
#include "programmers/programmers_118668.h"
#include "codesignal/challenge/codesignal_challenge_isAdmissibleOverpayment.h"
#include "codesignal/arcade/codesignal_arcade_EdgeOfTheOcean.h"
#include "codesignal/arcade/codesignal_arcade_SmoothSailing.h"
#include "codesignal/arcade/codesignal_arcade_ExploringTheWaters.h"
#include "codesignal/arcade/codesignal_arcade_IslandOfKnowledge.h"
#include "codesignal/arcade/codesignal_arcade_RainsOfReason.h"

int main()
{
    //printf("solution_118667 : answer : %d", solution_118667({ 1, 2, 1, 2 }, { 1, 10, 1, 2 }));

    /*
        10	10	[[10,15,2,1,2],[20,20,3,3,4]]	15
        0	0	[[0,0,2,1,2],[4,5,3,1,2],[4,11,4,0,2],[10,4,0,4,2]]	13
    
    printf("soultion_118668 : answer : %d, ", solution_118668(10, 10, {
        {10, 15, 2, 1, 2},
        {20, 20, 3, 3, 4} 
        }));
    printf("soultion_118668 : answer : %d, ", solution_118668(0, 0, {
        {0,0,2,1,2},
        {4,5,3,1,2},
        {4,11,4,0,2},
        {10,4,0,4,2}
        }));
        */
    /*
    vector<double> prices = { 110, 95, 70 };
    vector<string> notes = { "10.0% higher than in-store",
        "5.0% lower than in-store",
        "Same as in-store" };
    int x = 5;

    prices = { 40, 40, 40, 40 };
    notes = { "0.001% higher than in-store",
 "0.0% lower than in-store",
 "0.0% higher than in-store",
 "0.0% lower than in-store" };
    x = 0;
    printf("%d", solution_codesignal_challenge_isAdmissibleOverpayment(prices, notes, x));*/

    // printf("%d", solution_adjacentElementsProduct({ 3, 6, -2, -5, 7, 3 }));

    // printf("%d", solution_shapeArea(100));
    // printf("%d", solution_MakeArrayConsecutive2({6,2,3,8}));
    // printf("%d", solution_almostIncreasingSequence({ 1, 1, 2, 3, 4, 4 }));
    /*printf("%d", solution_matrixElementsSum({
        {0,1,1,2},
        {0,5,0,0},
        {2,0,3,3}
        }));*/
    /*printf("%d", solution_matrixElementsSum({
        {1,1,1,0},
        {0,5,0,1},
        {2,1,3,10}
        }));*/
    /*auto answer = solution_AllLongestStrings({"aba", "aa", "ad", "vcd", "aba"});
    for (auto& a : answer)
    {
        printf("%s", a.c_str());
    }*/
    // printf("%d", solution_commonCharacterCount("aabcc", "adcaa"));
    // printf("%d", solution_isLucky(1230));
    /*
    auto answer = solution_SortByHeight({ -1, 150, 190, 170, -1, -1, 160, 180 });
    for (auto& a : answer)
    {
        printf("%d\n", a);
    }*/
    /*string a = "foo(bar)baz(blim)";
    printf("%s", solution_reverseInParentheses(a).c_str());*/

    /*auto a = solution_alternatingSums({50,60,60,45,70});
    
    for (auto& n : a)
        printf("%d  ", n);*/
    /*auto a = solution_AddBorder({"abc","ded"});
    for (auto& s : a)
        printf("%s\n", s.c_str());
        */
    /*
    auto a = solution_AreSimilar({832, 998, 148, 570, 533, 561, 894, 147, 455, 279}, {832, 570, 148, 998, 533, 561, 455, 147, 894, 279});
    printf("%d", a);
    */
    // printf("%d", solution_arrayChange({ -1000, 0, -2, 0 }));
    // printf("%d", solution_palindromeRearranging("zyyzzzzz"));

    // printf("%d", solution_areEquallyStrong(10, 15, 15, 10));
    // printf("%d", solution_arrayMaximalAdjacentDifference({ 2, 4, 1, 0 }));
    // printf("%d", solution_isIPv4Address("1.1.1.1a"));
    // printf("%d", solution_avoidObstacles({ 19, 32, 11, 23 }));
    /*
    auto a = solution_BoxBlur({
        {1,1,1},
        {1,7,1},
        {1,1,1}
        });
    for (auto& q : a)
    {
        for (auto& qq: q)
            printf("%d", qq);
    }
    */

    /*
    auto Vec = solution_Minesweeper({
        {true, false, false},
        {false, true, false},
        {false, false, false},
        });
    for (auto& n : Vec)
    {
        for (auto& nn : n)
            printf("%d", nn);
        printf("\n");
    }
    */

    /*
    auto a = solution_ArrayReplace({1,2,3,2,1}, 3, 0);
    for (auto& n : a)
    {
        printf("%d ", n);
    }
    */
    // printf("%d", solution_evenDigitsOnly(268622));
    
    printf("%d\n", solution_variableName("var_1___Int"));
    printf("%d\n", solution_variableNameRegex("var_1___Int"));
    printf("%s\n", solution_alphabeticShift("crazy").c_str());

    return 0;
}