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

	���� ���簢�� �׸����� ���� ��� �𼭸��� �ֽ��ϴ�.
	�� ���� �̵����� ���� ����� ��(���� ��ġ�� �ٷ� ��, �Ʒ�, ���� �Ǵ� ������) �� �ϳ��� �ɾ �� �ֽ��ϴ�.

	��Ƽ�������� ��ǥ�� �ּ����� ���������� ������ �Ʒ� �������� ���� ���̴�.

	������, �װ��� ���̴� ��ó�� �������� �ʴ�: ���⼱���� �׸��带 ���� �帣�� �ִ�.

	��Ƽ�����װ� ö�縦 ������ ����ũ��Ĩ�� �ٻ�ٻ� Ÿ���� ���̱� ������ ������ ��Ƽ�����״� �װ͵��� ���ϱ� ���� �ּ��� ���ϰ� �;��Ѵ�.

	Ratiorg���� �������� �����ϴ� �� �ʿ��� �ּ����� �̵� Ƚ���� �˷������ν� ��Ʈ�� �ַ��� �մϴ�.

	�׸���� ���̾ �־����� ���� ��� �𼭸����� ������ �ϴ� �𼭸��� �̵��ϴ� �� �ʿ��� �ּ� �̵� Ƚ���� ��ȯ�մϴ�. ���� �װ��� ���� ���� �Ұ����ϴٸ�, ��� -1�� �����ּ���.


	Example

	For grid = [4, 8] and

	wires = [[1, 0, 1, 3], [3, 1, 3, 2], [4, 1, 4, 3], [4, 2, 4, 4],
		 [1, 3, 3, 3], [2, 1, 7, 1], [2, 2, 7, 2], [5, 3, 8, 3]]

*/
int solution_electricField(vector<int> grid, vector<vector<int>> wires)
{
	int vecX = 0, vecY = 0;
	int moveCount = 0;
	// �����ϴ� ��ǥ�� �̵��Ϸ� �ҋ� ��輱�� �ִ� ���� ����ġ�� ���̾ �ִ°�?
	return 0;
}