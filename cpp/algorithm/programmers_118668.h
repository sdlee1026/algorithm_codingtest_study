#pragma once

#include <string>
#include <vector>

using namespace std;

int solution_118668(int alp, int cop, vector<vector<int>> problems);
int solve(int alp, int cop, vector<vector<int>>& problems, int goalALP, int goalCOP, int cache[151][151]);

int maxAlp, maxCop;
int cache[151][151];