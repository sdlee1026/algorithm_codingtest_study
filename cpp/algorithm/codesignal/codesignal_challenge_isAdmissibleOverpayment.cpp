#include "../codeHeader.h"
/*
�ֱ� �ν�ŸīƮ�� ��Ÿ �׽��� ������ �׷쿡 �շ��� ��, ����� �׵��� ���ο� API�� �����ϱ�� �����Ѵ�.
API�� �׸��� ������ ���� �� ���ݰ� �ٸ� �� ����ڿ��� �˷��ִ�
���� �� ���ݺ��� 10.0% ���ų� ���� �� ���ݺ��� 5.0% ���� �׸� ���÷��� �غ� ���ڿ��� ��ȯ�մϴ�.

�׷��� ������� ��ü ���� īƮ�� �󸶸� �� ������ �������� ���� �� ���� ���ظ� ���������ν� �� ����� Ȯ���ϰ��� �մϴ�.

����� ���� ����ڰ� �ν�Ÿ�׷��� ���� ���� �� ���ݿ� ���� ������ ������ �ִ� �� x �ݾ��� ������ �� �ְ� �Ѵ�.
�̰��� ���� �ΰ������ �մϴ�.

����� ���� �־��� ���� ��õ� ���� �ΰ��� x�� �������� �׵��� īƮ�� �ִ� Ư�� ǰ�� ���� ������ ������ �ִ��� ���θ� �����ϴ� ���̴�.

prices = [110, 95, 70],

notes = ["10.0% higher than in-store",
         "5.0% lower than in-store",
         "Same as in-store"]

x = 5, ����� ������ ���ƾ� �մϴ�.

solution(prices, notes, x) = true

ù ��°�� �� ��° ǰ���� ���� �� ������ 100�̰�, �� ��° ǰ���� ������ 70�ε�, �̴� ���� ���� �ΰ����� ���� �Ⲩ�� �ϴ� 10 - 5 + 0 = 5�� ���� �����ϰ� �ִٴ� ���� �ǹ��Ѵ�.



prices = [48, 165]
notes = ["20.00% lower than in-store",
         "10.00% higher than in-store"]

x = 2, ����� ������ ���ƾ� �մϴ�.
solution(prices, notes, x) = false.

ù ��° ǰ���� ���� �� ������ 60�̰�, �� ��° ǰ���� 150�Դϴ�. �ʰ� ���޾��� 15 - 12 = 3����, ���� �Ⲩ�� �����ϱ⿡�� �ʹ� �����ϴ�.

*/
bool solution_codesignal_challenge_isAdmissibleOverpayment(vector<double> prices, vector<string> notes, double x)
{
    double diffValue = 0.f;
    int vecIndex = 0;
    for (auto& note : notes)
    {
        if (note.find("Same") != string::npos)
        {
            vecIndex++;
            continue;
        }
        string result = note.substr(0, note.find("%"));
        double per = stod(result);

        if (note.find("higher") != string::npos)
            diffValue += (prices[vecIndex] - prices[vecIndex] / ((100 + per) / 100.0f));
        else
            diffValue += prices[vecIndex] - (prices[vecIndex] * (100.0f / (100 - per)));
        vecIndex++;
    }
    diffValue = round(diffValue * 100000) / 100000;
    if (diffValue <= x)
        return true;

    return false;
}
