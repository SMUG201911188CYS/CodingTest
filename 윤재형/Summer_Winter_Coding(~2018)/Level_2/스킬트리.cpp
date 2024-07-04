#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(string s : skill_trees){
        int idx = -1;
        bool b = true;
        for(int i = 0; i < skill.size(); ++i){
            int f = s.find(skill[i]);
            if(f == string::npos) b = false;
            else{
                if(!b) break;
                if(idx < f) idx = f;
                else break;
            }
            if(i + 1 == skill.size()) ++answer;
        }
    }
    
    return answer;
}
