#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> answer, score;
unordered_map<string, vector<int>> map;

void com(string info) {
    int n;
    stringstream ss(info);
    string infos[4][2] = {{"-"}, {"-"}, {"-"}, {"-"}};
    
    for(int i = 0; i < 4; i++) ss >> infos[i][1];
    ss >> n;
    score.push_back(n);
    
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                for(int l = 0; l < 2; l++) {
                    string key = infos[0][i] + infos[1][j] + infos[2][k] + infos[3][l];
                    map[key].push_back(n);
                }
            }
        }
    }
}

void who(string info) {
    stringstream ss(info);
    string infos[8], key = "";
    
    for(int i = 0; i < 8; i++) ss >> infos[i];
    for(int i = 0; i < 8; i += 2) {
        if(infos[i] != "-") key += infos[i];
        else key += "-";
    }
    int idx = lower_bound(map[key].begin(), map[key].end(), (int)stoi(infos[7])) - map[key].begin();
    answer.push_back(map[key].size() - idx);
}

vector<int> solution(vector<string> info, vector<string> query) {
    for(auto s: info) com(s);
    for(auto i = map.begin(); i != map.end(); i++) sort(i->second.begin(), i->second.end());
    for(auto s: query) who(s);
    return answer;
}