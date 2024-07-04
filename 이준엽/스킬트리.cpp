#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Clear(vector<int> s){
    for(int i=0;i<s.size();i++){
        s[i] = 0;
    }
}

int solution(string skill, vector<string> skill_trees) {
    int answer = -1;
    vector<int> s;
    for(int i = 0; i < skill.length(); i++){
        s.push_back(0);
    }
    for(int i = 0; i < skill_trees.size();i++){
        for(int j = 0;j < skill.length();j++){
            
        }
    }
    return answer;
}   

