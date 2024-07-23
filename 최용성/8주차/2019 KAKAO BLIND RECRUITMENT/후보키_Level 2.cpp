#include <string>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <set>

using namespace std;

/*
-> 유일성 & 최소성이 확보된 조합과 현재 만들어진 조합을 비교함
-> 문제 예시
-> 기존 : 유일성 & 최소성 확보된 조합 0110 (이름, 전공)
-> 신규 : 유일성이 확보된 조합 0111 (이름, 전공, 학년)
-> & 연산을 함 => 0110
-> 이를 기존과 비교했을 때, 같다면 이는 최소성을 만족하지 못하는 조합, false 반환
-> 만약 기존에 존재하는 모든 조합과 비교했을 때 false가 나오지 않는다면 true
*/


bool checkUnique(int n, vector<int> & answer)
{
    for(int i = 0; i < answer.size(); i++)
    {
        if((answer[i] & n) == answer[i])
            return false;
    }
    
    return true;
}

/*
-> i가 1일때, 0001이라고 가정
-> 1 << col_len(길이) 라고 하였을때,
-> 0001을 왼쪽으로 4만큼 shift, 10000 -> 16이 됨.
-> 길이가 4(원소의 갯수)일때 만들 수 있는 조합의 갯수
-> 4C4 + 4C3 + 4C2 + 4C1 -> 15.
-> 즉 i < (1 << col_len) 조건을 통해 조합의 수를 구함
-------------------------------------------------
-> 1 << k => 1 << 0, 1 << 1... 처럼 돔
-> 0001, 0010... 로 생성되며, 이는 선택되는 값을 의미
-> Ex, 0001 => index가 0인 값만 접근
-> 0011 => index가 0, 1인 값만 접근
-> 0110 => index가 1, 2인 값만 접근
-> 이를 i와 & 연산을 통해, i의 비트를 확인하며 조합을 만듬
-> EX, i => 7 = 0110이면,
-> 1 << k가 돌면서 & 연산을 진행
-> k = 0, 0001 / i = 0110 / & 연산 값 = 0
-> k = 1, 0010 / i = 0110 / & 연산 값 = 2
-> k = 2, 0100 / i = 0110 / & 연산 값 = 4
-> k = 3, 1000 / i = 0110 / & 연산 값 = 0
-> 즉 k가 1, 2일때 if문에서 true가 됨으로 index가 1, 2인 값을 넣어주게 됨
---------------------------------------------------
-> 이를 set에 넣어주게 되면서 중복이 있는지 check
-> 중복이 없다면, 세로의 길이 값 만큼 set이 생성됨. -> 유일성 확인
*/

int solution(vector<vector<string>> relation) {
    vector<int> answer;
    int row_len = relation.size();
    int col_len = relation[0].size();
    
    for(int i = 1; i < (1 << col_len); i++) 
    {
        set<string> _set;
        for(int j = 0; j < row_len; j++)
        {
            string temp;
            for(int k = 0; k < col_len; k++)
            {
                if(i & (1 << k))
                {
                    temp += relation[j][k];
                }
            }
            _set.insert(temp);
        }
        
        if(_set.size() == row_len)
        {
            if(checkUnique(i, answer))
                answer.push_back(i);
        }
    }
    
    return answer.size();
}