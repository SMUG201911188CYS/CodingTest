#include <string>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

string go(string ipt) {
    cout << ipt << '\n';

    //1. 입력이 빈 문자열인 경우, 빈 문자열을 반환
    if (ipt == "") return ipt;

    //2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리
    string u = "";
    string v = "";
    stack<char> s;

    //처음 온 괄호의 갯수 ('('인지 ')'인지는 상관 없음)
    int num = 0;
    int num_2 = 0;

    for (int i = 0; i < ipt.length(); i++) {
        char c = ipt[i];
        u += c;

        if (ipt[0] == c) {
            s.push(c);
            num++;
        }
        else {
            if (c == ')' && !s.empty()) s.pop();
            num_2++;
        }

        if (num == num_2) {
            v = ipt.substr(i + 1);
            break;
        }
    }

    //3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행
    if (s.empty()) {
        // 3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환 
        return u + go(v);

    }
    else {
        //4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행 
           // 4-1. 빈 문자열에 첫 번째 문자로 '('를 붙임 
           // 4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙임
           // 4-3. ')'를 다시 붙임
        string str = "(" + go(v) + ")";

        // 4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙임
        string str_2 = u.substr(1, u.length() - 2);
        for (int i = 0; i < str_2.length(); i++) {
            if (str_2[i] == '(') str_2[i] = ')';
            else str_2[i] = '(';
        }

        // 4-5. 생성된 문자열을 반환
        return str + str_2;


    }
}


string solution(string p) {
    stack<char> s;
    for (char ch : p) {
        if (ch == '(')s.push(ch);
        else if (!s.empty() && ch == ')') s.pop();
    }


    //만약 p가 이미 "올바른 괄호 문자열"이라면 그대로 return
    if (s.empty()) return p;
    else return go(p);

}


int main(int argc, char** argv) {
    string p = "()))((()";
    cout << solution(p);
}