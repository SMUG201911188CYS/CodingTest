#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> q;
    
    
    for(int i = 0; i < priorities.size(); i++)
        q.push(i);
    
    while(true) {
        int max = *max_element(priorities.begin(), priorities.end());
        int item = q.front(); q.pop();
        if(max == priorities[item]) {
            priorities[item] = 0;
            answer++;
            if(item == location) break;
        } else {
            q.push(item);
        }
    }
    
    return answer;
}