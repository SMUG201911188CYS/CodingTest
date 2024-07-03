// https://cherishvert.tistory.com/108

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

map<string, vector<int>> scores;

void storeScore(vector<vector<string>> &tmp, int score) {
    string c1, c2, c3, c4;
    
    for (int i=0; i<2; i++) {
        c1 = tmp[0][i];
        for (int j=0; j<2; j++) {
            c2 = tmp[1][j];
            for (int k=0; k<2; k++) {
                c3 = tmp[2][k];
                for (int l=0; l<2; l++) {
                    c4 = tmp[3][l];
                    scores[c1 + c2 + c3 + c4].push_back(score);
                }
            }
        }
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<vector<string>> tmp(4, vector<string>(2, "-"));
    
    for (int i=0; i<info.size(); i++) {
        string s;
        int idx = 0, score = 0;
        
        stringstream ss(info[i]);
        
        while (ss >> s) {
            if (idx < 4) tmp[idx++][0] = s;
            else score = stoi(s);
        }
        
        storeScore(tmp, score);
    }
    
    for (auto it: scores) {
        sort(scores[it.first].begin(), scores[it.first].end());
    }
    
    for (string q: query) {
        string s, key = "";
        int idx = 0, score = 0;
        
        stringstream ss(q);
        
        while (ss >> s) {
            if (s == "and") continue;
            
            if (idx < 4) {
                key += s;
                idx++;
            } else {
                score = stoi(s);
            }
        }
        
        auto it = lower_bound(scores[key].begin(), scores[key].end(), score);
        answer.push_back(scores[key].size() - (it - scores[key].begin()));
    }
    
    return answer;
}
