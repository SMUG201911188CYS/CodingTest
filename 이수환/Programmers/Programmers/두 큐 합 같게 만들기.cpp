#include <iostream>
#include <vector>
#include <numeric>
#include <deque>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;

    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0);

    long long sum = sum1 + sum2;
    // È¦¼öÀÎ °æ¿ì
    if (sum & 1) return -1;

    deque<int> q1, q2;
    while (!queue1.empty()) {
        q1.push_front(queue1.back());
        queue1.pop_back();
    }
    while (!queue2.empty()) {
        q2.push_front(queue2.back());
        queue2.pop_back();
    }

    int len = q1.size();
    for (int i = 0; i <= (len * 3); i++) {
        if (sum1 > sum2) {
            sum1 -= q1.front();
            sum2 += q1.front();
            int tmp = q1.front();
            q1.pop_front();
            q2.push_back(tmp);
            answer++;
        }
        else if (sum1 < sum2) {
            sum1 += q2.front();
            sum2 -= q2.front();
            int tmp = q2.front();
            q2.pop_front();
            q1.push_back(tmp);
            answer++;
        }
        else {
            return answer;
        }
    }

    return -1;
}