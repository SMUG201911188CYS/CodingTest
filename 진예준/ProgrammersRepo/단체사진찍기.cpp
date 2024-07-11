#include "단체사진찍기.h"


void 단체사진찍기::진행()
{
    int n = 2;
	vector<string> data= { "N~F=0", "R~T>2" };

    std::cout << solution(data.size(), data);
}

#include <algorithm>

int 단체사진찍기::solution(int n, vector<string> data)
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
            const int relate_size = condition[4]-'0';
            
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