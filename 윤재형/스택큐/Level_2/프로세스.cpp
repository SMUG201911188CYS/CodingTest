#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    
    int answer = 1;
    queue<int> q;
    for(int i = 0; i < priorities.size(); ++i) q.push(i);
    while(true){
        int max = 0;
        for(int n : priorities) if(max < n) max = n;
        if(priorities[0] == max){
            if(q.front() == location) return answer;
            priorities.erase(priorities.begin());
            ++answer;
            q.pop();
        }
        else{
            for(int i = 0; i < priorities.size() - 1; ++i) swap(priorities[i], priorities[i + 1]);
            q.push(q.front());
            q.pop();
        }
    }
}
