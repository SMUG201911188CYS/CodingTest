#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int Check(char c){
    if(c == '(') return 1;
    else return -1;
}

string Recursive(string s){
    if(s == "") return s;
    
    string u, v;   
    
    int index = 0;
    int count = 0;
    bool flag = Check(s[index]);
    if(s[index] == '(') flag = true;
    else flag = false;
    
    count += Check(s[index++]);
    while(index < s.length() && count != 0){
        count += Check(s[index++]);
    }
    u = s.substr(0, index);
    v = Recursive(s.substr(index, s.length()));
    if(!flag){
        string tmp = "(";
        tmp += v;
        tmp += ")";
        for(int i = 0; i < u.length(); i++){
            if(u[i] == '(') u[i] = ')';
            else if(u[i] == ')') u[i] = '(';
        }
        u.erase(u.begin());
        u.erase(u.begin() + u.length()-1);
        tmp += u;
        cout << tmp;
            
        return tmp;
    }else{       
        return u+v;
    }
    
}


string solution(string p) {
    string answer = "";
    answer = Recursive(p);
    return answer;
}