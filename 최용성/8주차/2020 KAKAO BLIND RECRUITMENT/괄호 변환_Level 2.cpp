#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool divideString(string & u, string & v, string p)
{
    int i = 0;
    int left = 0;
    int right = 0;
    int temp = 0;
    bool isPerfect = true; // 문자열 나누면서 완벽한지 체크
    
    while(i < p.length())
    {
        if(p[i] == '(')
        {
            left++;
            temp += 1;
        }
        else
        {
            right++;
            temp -= 1;
        }
        
        if(temp < 0) // ( -> +1, ) -> -1로 설정해서 temp의 값이 0 이하로 내려가면 완벽하지 않은 것이니 false로 처리
            isPerfect = false;
        
        u += p[i];
        
        if(left == right) // 올바른 괄호 됬을 시 Break
            break;
        
        i++;
    }
    
    for(i = i+1; i < p.length(); i++) // 남은 문자 v에 삽입
        v += p[i];
    
    return isPerfect;
}



string solution(string p) {
    string answer = "";
    
    if(p.empty())
        return p;
    
    string u;
    string v;
    
    if(divideString(u, v, p)) // u가 완벽하다면
        {
        answer = u + solution(v); // v에 대한 재귀
        }
    else // u가 완벽하지 않으면
        {
        answer += '(';
        answer += solution(v);
        answer += ')';
        
        if(u.length() > 2) // 조건에 따라 반전해서 넣어주기
            {
            for(int i = 1; i < u.length() - 1; i++)
            {
                if(u[i] == '(')
                    answer += ')';
                else
                    answer += '(';
            }
            }
        }
    
    return answer;
}