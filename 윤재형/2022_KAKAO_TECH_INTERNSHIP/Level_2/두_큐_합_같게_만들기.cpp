#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    
    long long sum1 = 0, sum2 = 0;
    queue<int> q1, q2;
    
    for(int i : queue1){
        sum1 += i;
        q1.push(i);
    }
    for(int i : queue2){
        sum2 += i;
        q2.push(i);
    }
    
    int answer = 0;
    int idx1 = 0, idx2 = 0;
    int Maxidx = queue1.size() + queue2.size();
    
    while(idx1 < Maxidx && idx2 < Maxidx){
        
        if(sum1 == sum2) return answer;
        
        ++answer;
        
        if(sum1 < sum2){
            int cur = q2.front();
            q2.pop();
            q1.push(cur);
            sum1 += cur;
            sum2 -= cur;
            ++idx2;
        }
        else{
            int cur = q1.front();
            q1.pop();
            q2.push(cur);
            sum1 -= cur;
            sum2 += cur;
            ++idx1;
        }
    }
    return -1;
}
