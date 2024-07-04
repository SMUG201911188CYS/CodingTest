// https://cherishvert.tistory.com/109
// map, dfs
// dfs 함수 이해 못함

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> combination;

// 각 order에 대해 조합의 수가 len인 단품메뉴 조합의 주문 개수 카운트
void dfs(string &order, int &len, string tmp, int idx) {
    if (tmp.length() == len) {
        combination[tmp]++; // 해당 조합의 주문 수++
        return;
    }
    
    for (int i=idx; i<order.length(); i++) {
        dfs(order, len, tmp + order[i], i + 1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for (int len: course) {
        for (string order: orders) {
            sort(order.begin(), order.end());
            dfs(order, len, "", 0);   
        }
        
        int maxCount = 0; // 가장 많이 주문된 수
        for (auto it: combination) {
            maxCount = max(maxCount, it.second);
        }
        
        for (auto it: combination) {
            if (maxCount < 2) break;
            else if (combination[it.first] == maxCount) answer.push_back(it.first);
        }
        
        combination.clear(); // 다음 단품메뉴의 개수의 연산을 위해 clear
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}