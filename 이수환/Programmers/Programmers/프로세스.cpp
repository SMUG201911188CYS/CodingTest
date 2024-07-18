#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int& a, int& b) {
    return a > b;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> prioritiesQueue;
    queue<pair<int, int>> indexQueue;

    int index = 0;
    for (int priority : priorities) {
        indexQueue.push(pair<int, int>(index++, priority));
    }

    sort(priorities.begin(), priorities.end(), compare);
    for (int priority : priorities) {
        prioritiesQueue.push(priority);
    }

    while (!prioritiesQueue.empty()) {
        pair<int, int> curFront = indexQueue.front();
        int curFrontPriority = prioritiesQueue.front();

        if (curFrontPriority == curFront.second) {
            indexQueue.pop();
            prioritiesQueue.pop();
            answer++;
            if (location == curFront.first) {
                return answer;
            }
        }
        else {
            indexQueue.pop();
            indexQueue.push(curFront);
        }
    }


    return answer;
}