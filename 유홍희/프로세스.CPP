#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) 
{
    queue<pair<int, int>> printerQueue;
    priority_queue<int> priorityQueue;

    for (int i = 0; i < priorities.size(); i++) 
    {
        printerQueue.push(make_pair(priorities[i], i));
        priorityQueue.push(priorities[i]);
    }

    int printOrder = 0;

    while (!printerQueue.empty()) 
    {
        int currentPriority = printerQueue.front().first;
        int currentIndex = printerQueue.front().second;
        printerQueue.pop();

        // 가장 높은 중요도의 프로세스가 현재 프로세스와 일치할 때
        if (currentPriority == priorityQueue.top()) 
        {
            printOrder++;
            priorityQueue.pop();

            // 찾는 프로세스가 실행?
            if (currentIndex == location) 
            {
                return printOrder;
            }
        } else 
        {
            // 아니면 큐의 마지막으로
            printerQueue.push(make_pair(currentPriority, currentIndex));
        }
    }

    return -1;
}

int main() {
    vector<int> priorities = {2, 1, 3, 2};
    int location = 2;

    cout << solution(priorities, location) << endl;

    return 0;
}