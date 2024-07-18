#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer = 0;

void permutation(int depth, vector<string> data, int n, string friends, string list, vector<bool> check)
{
    if(depth == 8)
    {
        for(int i = 0; i < n; i++)
        {
            string temp = data[i];
            int a;
            int b;
            
            a = list.find(temp[0]);
            b = list.find(temp[2]);
            
            int distance;
            if(a > b)
                distance = a - b;
            else
                distance = b - a;
            
            int condition = temp[4] - '0' + 1;
            
            if(temp[3] == '=' && distance != condition)
                return;
            if(temp[3] == '<' && distance >= condition)
                return;
            if(temp[3] == '>' && distance <= condition)
                return;
        }
        answer += 1;
        //cout << answer << '\n';
        return;
    }
    
    for(int i = 0; i < 8; i++)
    {
        if(check[i])
            continue;
        
        check[i] = true;
        list[depth] = friends[i];
        permutation(depth + 1, data, n, friends, list, check);
        check[i] = false;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    answer = 0;
    
    string list = "AAAAAAAA";
    vector<bool> check(8, false);
    string friends{'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    
    permutation(0, data, n, friends, list, check);
    
    return answer;
}