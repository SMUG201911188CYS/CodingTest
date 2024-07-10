#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<char> nameList = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };

int count = 0;



bool checkData(string data, vector<char>& combVec) {
    char first = data[0];
    char second = data[2];
    char oper = data[3];
    int value = data[4] - '0';

    int firstIndex = 0;
    int secondIndex = 0;
    int index = 0;
    for (char cur : combVec) {
        if (cur == first) {
            firstIndex = index;
        }
        if (cur == second) {
            secondIndex = index;
        }
        index++;
    }

    int dis = abs(firstIndex - secondIndex) - 1;

    if (oper == '>') return dis > value;
    else if (oper == '=') return dis == value;
    else if (oper == '<') return dis < value;

    return false;
}
void comb(vector<char> combVec, vector<bool> check, int depth, vector<string>& dataVec)
{
    if (depth > nameList.size())
    {
        bool flag = true;
        for (string data : dataVec)
        {
            if (!checkData(data, combVec))
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            count++;
        }
        return;
    }

    for (int i = 0; i < nameList.size(); i++)
    {
        if (!check[i])
        {
            vector<bool> newCheck(check);
            vector<char> newCombVec(combVec);
            newCheck[i] = true;
            newCombVec.push_back(nameList[i]);
            comb(newCombVec, newCheck, depth + 1, dataVec);
        }
    }

}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data)
{
    int answer = 0;
    count = 0;

    vector<bool> check(nameList.size(), false);
    vector<char> combVec;
    comb(combVec, check, 1, data);
    answer = count;

    return answer;
}