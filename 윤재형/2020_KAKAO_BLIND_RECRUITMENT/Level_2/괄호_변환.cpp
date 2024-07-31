#include <string>
#include <vector>
#include <iostream>

using namespace std;

string u = "", v = "";

bool check_valid(string s){
    vector<char> v;
    
    for(char c : s){
        if(c == '(') v.push_back(c);
        else if(c == ')')
            if(!v.empty()) v.pop_back();
    }
    
    if(v.empty()) return true;
    else return false;
}

string removeAndReverse(string u)
{
    u.erase(u.begin());
    u.erase(u.end() - 1);
    
    for(int i = 0; i < u.length(); i++)
    {
        if (u[i] == '(') u[i] = ')'; 
        else if (u[i] == ')') u[i] = '(';
    }
    
    return u;
}

string convert(string w)
{
    if (w == "") return w;
    
    int openCount = 0; int closeCount = 0;
    int index = 0;
    for(int i = 0; i < w.length(); i++)
    {
        if (w[i] == '(') openCount++;
        if (w[i] == ')') closeCount++;
        
        if (openCount == closeCount) 
        {
            index = i + 1;
            break;
        }
    }
    string u = w.substr(0, index);
    string v = w.substr(index);
    
    string result = "";
    if (check_valid(u))
        result = u + convert(v); 
    else
        result =  "(" + convert(v) + ")" + removeAndReverse(u);

    return result; 
}

string solution(string p) {
    string answer = convert(p);
    
    return answer;
}
