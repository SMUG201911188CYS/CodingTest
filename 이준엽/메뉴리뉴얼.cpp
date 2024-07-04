#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

map<string, int> combination;

void dfs(string order, int len, string tmp, int idx) {
    if (tmp.length() == len) {
        combination[tmp]++; 
        return;
    }
    
    for (int i=idx; i<order.length(); i++) {
        dfs(order, len, tmp + order[i], i + 1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int len:course){
        for(string order:orders){
            sort(order.begin(),order.end());
            dfs(order,len,"",0);
        }
        
        int max_order = 0;
        for(auto it : combination){
            max_order = max(it.second,max_order);
        }
        for(auto it : combination){
            if(max_order < 2) break;
            else if(it.second == max_order) answer.push_back(it.first);
        }
        combination.clear();
    }
    sort(answer.begin(),answer.end());
    return answer;
}