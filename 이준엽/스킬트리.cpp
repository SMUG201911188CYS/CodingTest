#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX 999999999
using namespace std;


vector<int> Clear(vector<int> s){
    for(int i=0;i<s.size();i++){
        s[i] = MAX;
    }
    return s;
}
void debug(vector<int> s){
    for(int i=0;i<s.size();i++){
        cout << s[i] << endl;
    }
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<int> s;
    for(int i = 0; i < skill.length(); i++){
        s.push_back(MAX);
    }
    for(int i = 0; i < skill_trees.size();i++){
        
        for(int j = 0;j < skill.length();j++){
            s[j] = skill_trees[i].find(skill[j]);
            if(s[j] == -1) s[j] = MAX;
        }
        bool fg = true;
        for(int j = 0;j < s.size() - 1;j++){
            if(s[j] > s[j+1]){
                fg = false;
            }
        }
        if(fg)answer++;
        cout << "answer : " <<answer << endl;
        cout << "fg : "<<fg << endl;
        s = Clear(s);
    }
    return answer;
}   

