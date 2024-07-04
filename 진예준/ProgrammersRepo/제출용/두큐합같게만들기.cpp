#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> q1, vector<int> q2) {
    int answer = 0;

    long totalQueueSum = 0; // 두 큐의 합
    long queue1Sum = 0; // 1번 큐의 합
    queue<int> queue1;
    queue<int> queue2;

    for (int i = 0; i < q1.size(); i++) {
        totalQueueSum += q1[i] + q2[i];
        queue1Sum += q1[i];
        queue1.push(q1[i]);
        queue2.push(q2[i]);
    }

    if (totalQueueSum % 2 != 0) return -1; // 만약 두 큐의 합이 홀수면 같게 못 만듦.

    long target = totalQueueSum / 2;
    while (true) {
        if (answer > (q1.size() + q2.size()) + 2) return -1;
        if (queue1Sum == target) break;
        else if (queue1Sum > target) {
            queue1Sum -= queue1.front();
            queue2.push(queue1.front());
            queue1.pop();
        }
        else {
            queue1Sum += queue2.front();
            queue1.push(queue2.front());
            queue2.pop();
        }
        answer++;
    }

    return answer;
}