#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isRightString(string s){
    int left = 0;
    int right = 0;
    for(int i = 0 ; i < s.length(); i++){
        if(left < right){return false;}

        if(s[i] == '('){
            left++;
        }else{
            right++;
        }
    }
    return true;
}


string solution(string p) {
    string answer = "";
    int left = 0;
    int right = 0;
    string u;
    string v;
    //입력이 빈 문자열인 경우, 빈 문자열을 반환
    if(p == ""){return "";}
    //문자열을 두 균형잡힌 괄호 문자열 u,v로 분리
    for(int i = 0; i < p.length(); i++){
        if(p[i] == '('){
            left++;
        }else if(p[i]== ')'){
            right++;
        }
        if(left == right){
            u = p.substr(0, i+1);
            v = p.substr(i+1);
            break;
        }
    }

    if(isRightString(u)){
        v = solution(v);
        answer = u + v;
        return answer;
    }else{
        
        answer = "(";
        answer = answer + solution(v);
        answer = answer + ')';
        
        u.erase(0,1);
        u.erase(u.length()-1,1);
        for(int i = 0; i<u.length();i++){
            if(u[i]=='('){
                answer = answer + ')';
            }else if(u[i] == ')'){
                answer = answer + '(';
            }
        }
       
        return answer;
    }
}