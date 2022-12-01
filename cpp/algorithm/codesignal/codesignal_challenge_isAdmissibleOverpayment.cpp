#include "../codeHeader.h"
/*
최근 인스타카트의 베타 테스팅 개발자 그룹에 합류한 후, 당신은 그들의 새로운 API를 실험하기로 결정한다.
API는 항목의 가격이 상점 내 가격과 다를 때 사용자에게 알려주는
상점 내 가격보다 10.0% 높거나 상점 내 가격보다 5.0% 낮은 항목별 디스플레이 준비 문자열을 반환합니다.

그러나 사람들이 전체 쇼핑 카트에 얼마를 더 지불할 것인지에 대한 더 나은 이해를 제공함으로써 이 기능을 확장하고자 합니다.

당신의 앱은 사용자가 인스타그램을 통해 상점 내 가격에 대해 지불할 의향이 있는 총 x 금액을 결정할 수 있게 한다.
이것을 가격 민감도라고 합니다.

당신의 일은 주어진 고객이 명시된 가격 민감도 x를 기준으로 그들의 카트에 있는 특정 품목에 대해 지불할 의향이 있는지 여부를 결정하는 것이다.

prices = [110, 95, 70],

notes = ["10.0% higher than in-store",
         "5.0% lower than in-store",
         "Same as in-store"]

x = 5, 출력은 다음과 같아야 합니다.

solution(prices, notes, x) = true

첫 번째와 두 번째 품목의 매장 내 가격은 100이고, 세 번째 품목의 가격은 70인데, 이는 고객이 가격 민감도에 따라 기꺼이 하는 10 - 5 + 0 = 5를 과다 지급하고 있다는 것을 의미한다.



prices = [48, 165]
notes = ["20.00% lower than in-store",
         "10.00% higher than in-store"]

x = 2, 출력은 다음과 같아야 합니다.
solution(prices, notes, x) = false.

첫 번째 품목의 매장 내 가격은 60이고, 두 번째 품목은 150입니다. 초과 지급액은 15 - 12 = 3으로, 고객이 기꺼이 지불하기에는 너무 많습니다.

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
