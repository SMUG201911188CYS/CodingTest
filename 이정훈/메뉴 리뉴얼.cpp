// https://cherishvert.tistory.com/109

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> combination;

void dfs(string &order, int &len, string tmp, int idx) {
    if (tmp.length() == len) {
        combination[tmp]++;
        
        return;
    }
    
    for (int i = idx; i < order.length(); i++) {
        dfs(order, len, tmp + order[i], i + 1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for (int len: course) {
        for (auto order: orders) {
            sort(order.begin(), order.end());
            dfs(order, len, "", 0);   
        }
        
        int max_count = 0;
        for (auto it : combination) {
            max_count = max(max_count, it.second);
        }
        
        for (auto it : combination) {
            if (max_count < 2) break;
            else if (combination[it.first] == max_count) answer.push_back(it.first);
        }
        
        combination.clear();
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
