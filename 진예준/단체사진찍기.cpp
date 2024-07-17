#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data)
{
    int answer = 0;
    vector<char> elements = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
    sort(elements.begin(), elements.end());

    int count = 0;
    do
    {
        bool checklist = true;
        for (auto& condition : data)
        {
            if (!checklist) break;
            const char first = condition[0];
            const char second = condition[2];
            const char sign = condition[3];
            const int relate_size = condition[4] - '0';

            int index_first = find(elements.begin(), elements.end(), first) - elements.begin();
            int index_second = find(elements.begin(), elements.end(), second) - elements.begin();
            auto relate_amount = abs(index_first - index_second) - 1;
            ;
            switch (sign)
            {
            case '>':
                if (relate_amount > relate_size); else checklist = false;
                break;
            case '=':
                if (relate_amount == relate_size); else
                {
                    checklist = false;
                }
                break;
            case '<':
                if (relate_amount < relate_size); else checklist = false;
                break;
            default:
                break;
            }
        }
        if (checklist) answer++;
    } while (next_permutation(elements.begin(), elements.end()));
    return answer;
}