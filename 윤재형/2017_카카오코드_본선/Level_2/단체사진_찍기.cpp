#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    string s = "ACFJMNRT";
    sort(s.begin(), s.end());
    
    do{
        
        bool b = true;
        for(string t : data){
            
            int first = s.find(t[0]);
            int second = s.find(t[2]);
            int diff = abs(first - second) - 1;
            int n = t[4] - '0';
            
            if(t[3] == '=')
                if(n == diff) continue;
            if(t[3] == '>')
                if(diff > n) continue;
            if(t[3] == '<')
                if(diff < n) continue;
            
            b = false;
            break;
        }
        
        if(b) ++answer;
        
    }while(next_permutation(s.begin(), s.end()));
    
    return answer;
}
