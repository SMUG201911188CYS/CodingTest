#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    int total_queue_size = queue1.size() + queue2.size();
    long long sum1 = 0, sum2 = 0; // int->overflow?
    int idx1 = 0, idx2 = 0; // erase->timeout
    
    for(int elem : queue1) {
        sum1 += elem;
    }
    
    for(int elem : queue2) {
        sum2 += elem;
    }
    
    while(answer != total_queue_size*2) {
        if(sum1 < sum2) {
            int front = queue2[idx2++];
            queue1.push_back(front);
            sum1 += front;
            sum2 -= front;
        } else if(sum1 > sum2) {
            int front = queue1[idx1++];
            queue2.push_back(front);
            sum2 += front;
            sum1 -= front;
        } else {
            return answer;
        }
        answer++;
    }
    
    return -1;
}