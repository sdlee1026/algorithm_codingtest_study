#include <string>
#include <vector>
#include "programmers_118667.h"
#include "programmers_118668.h"
using namespace std;


int main()
{
    //printf("solution_118667 : answer : %d", solution_118667({ 1, 2, 1, 2 }, { 1, 10, 1, 2 }));

    /*
        10	10	[[10,15,2,1,2],[20,20,3,3,4]]	15
        0	0	[[0,0,2,1,2],[4,5,3,1,2],[4,11,4,0,2],[10,4,0,4,2]]	13
    */
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
    return 0;
}