#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> relation)
{
    vector<vector<int>> combinations;
    int n = relation[0].size();
    int totalCombinationNumber = 1 << n;

    //비트마스크를 통해 조합구하기
    for (int bitmask = 0; bitmask < totalCombinationNumber; bitmask++)
    {
        vector<int> combination;
        for (int i = 0; i < n; i++)
        {
            if (bitmask & (1 << i))
            {
                combination.push_back(i);
            }
        }
        combinations.push_back(combination);
    }


    //유일성 확인
    vector<vector<int>> uniqueComb;
    for (auto combination : combinations)
    {
        for (int i = 0; i < combination.size(); i++)
        {

        }
        bool isUnique = true;
        std::sort(combination.begin(), combination.end());
        for (size_t i = 1; i < combination.size(); i++)
        {
            if (combination[i] == combination[i - 1]) isUnique = false;
        }
        if (isUnique) uniqueComb.push_back(combination);
    }

    for (auto comb : uniqueComb)
    {
        for (auto com : comb)
        {
            cout << com << " ";
        }
        cout << endl;
    }

    cout << relation.size() << " " << relation[0].size();
    int answer = 0;
    return answer;
}