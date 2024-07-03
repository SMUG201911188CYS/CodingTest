#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    vector<char> q;
    
    for(auto s : skill)
        q.push_back(s);

    reverse(q.begin(), q.end());
    
    for(auto skill_tree : skill_trees) {
        vector<char> _q = q;
        bool flg = true;
        for(auto _skill : skill_tree) {
            if(_skill == _q.back()) {
                _q.pop_back();
                continue;
            }
            for(int i = 0; i < _q.size(); i++) {
                if(_skill == _q[i]) {
                    flg = false;
                    break;
                }
            }
        }
        
        if(flg)
            answer++;
    }
    
    return answer;
}