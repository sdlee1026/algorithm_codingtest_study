#include "../../codeHeader.h"
/*
codesignal_challenge_electricField
	the bot stays in the top left corner of a rectangular grid.
	 In one move he can walk to one of the nearest cells (directly above, below, to the left or to the right of his current position).

	Ratiorg's goal is to get to the bottom right corner in the least possible number of moves.

	However, it's not as simple as it seems: there are electric wires running through the grid.

	If Ratiorg steps on a wire, his microchips will be burnt to a crisp, so Ratiorg, prudent bot that he is, wants to do his best to avoid them.

	You want to give Ratiorg a hint by telling him the least possible number of moves required to get to the destination.

	Given the grid and the wires, return the minimum number of moves required to get to the bottom right corner from the top left corner. If it's not possible to get there, return -1 instead.

	봇은 직사각형 그리드의 왼쪽 상단 모서리에 있습니다.
	한 번의 이동으로 가장 가까운 셀(현재 위치의 바로 위, 아래, 왼쪽 또는 오른쪽) 중 하나로 걸어갈 수 있습니다.

	라티오르그의 목표는 최소한의 움직임으로 오른쪽 아래 구석으로 가는 것이다.

	하지만, 그것은 보이는 것처럼 간단하지 않다: 전기선들이 그리드를 통해 흐르고 있다.

	라티오르그가 철사를 밟으면 마이크로칩이 바삭바삭 타버릴 것이기 때문에 신중한 라티오르그는 그것들을 피하기 위해 최선을 다하고 싶어한다.

	Ratiorg에게 목적지에 도달하는 데 필요한 최소한의 이동 횟수를 알려줌으로써 힌트를 주려고 합니다.

	그리드와 와이어가 주어지면 왼쪽 상단 모서리에서 오른쪽 하단 모서리로 이동하는 데 필요한 최소 이동 횟수를 반환합니다. 만약 그곳에 가는 것이 불가능하다면, 대신 -1을 돌려주세요.


	Example

	For grid = [4, 8] and

	wires = [[1, 0, 1, 3], [3, 1, 3, 2], [4, 1, 4, 3], [4, 2, 4, 4],
		 [1, 3, 3, 3], [2, 1, 7, 1], [2, 2, 7, 2], [5, 3, 8, 3]]

*/
int solution_electricField(vector<int> grid, vector<vector<int>> wires)
{
	int vecX = 0, vecY = 0;
	int moveCount = 0;
	// 가려하는 좌표로 이동하려 할떄 경계선에 있는 선을 지나치는 와이어가 있는가?
	return 0;
}