#include "codeHeader.h"
#include "programmers/programmers_118667.h"
#include "programmers/programmers_118668.h"
#include "codesignal/challenge/codesignal_challenge_isAdmissibleOverpayment.h"
#include "codesignal/arcade/codesignal_arcade_EdgeOfTheOcean.h"
#include "codesignal/arcade/codesignal_arcade_SmoothSailing.h"
#include "codesignal/arcade/codesignal_arcade_ExploringTheWaters.h"


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
        printf("%s\n", s.c_str());*/
    /*auto a = solution_AreSimilar({832, 998, 148, 570, 533, 561, 894, 147, 455, 279}, {832, 570, 148, 998, 533, 561, 455, 147, 894, 279});
    printf("%d", a);*/
    // printf("%d", solution_arrayChange({ -1000, 0, -2, 0 }));
    printf("%d", solution_palindromeRearranging("zyyzzzzz"));
    return 0;
}