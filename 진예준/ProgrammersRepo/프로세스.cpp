#include "프로세스.h"

#include <queue>

void 프로세스::진행()
{
	vector<int> priorities = {1, 1, 9, 1, 1, 1};
	int location = 0;

	cout << "Solution: " << solution(priorities, location);
}

int 프로세스::solution(vector<int> priorities, int location)
{
	
	int anwser = 0;
	
	queue<pair<int, int>> que; //location, priorty

	vector<int> count = vector<int>(10);

	for (int i = 0; i < priorities.size(); i++)
	{
		count[priorities[i]]++;
		que.push(pair<int, int>(i, priorities[i]));
	}

	/*
	while (!que.empty()) 
	{
		cout << que.front().first << " " << que.front().second << " ";
		que.pop();
		cout << endl;
	}
	*/

	/*
	1. 실행 대기 큐(Queue)에서 대기중인 프로세스 하나를 꺼냅니다.
	2. 큐에 대기중인 프로세스 중 우선순위가 더 높은 프로세스가 있다면 방금 꺼낸 프로세스를 다시 큐에 넣습니다.
	3. 만약 그런 프로세스가 없다면 방금 꺼낸 프로세스를 실행합니다.
		3.1 한 번 실행한 프로세스는 다시 큐에 넣지 않고 그대로 종료됩니다.	
	*/

	while (!que.empty())
	{
		//1. 실행 대기 큐(Queue)에서 대기중인 프로세스 하나를 꺼냅니다.
		auto temp = que.front();
		
		//cout << "Location: " << temp.first << endl << "Priority: " << temp.second << endl;

		//2. 큐에 대기중인 프로세스 중 우선순위가 더 높은 프로세스가 있다면

		for (auto& c : count)
		{
			//cout << c << endl;
		}


		bool success = true;
		for (int i = temp.second + 1; i < 10; i++)
		{
			//cout << count[i];
			if (count[i] > 0)
			{
				success = false; 
			}
		}

		if (!success)
		{
			//방금 꺼낸 프로세스를 다시 큐에 넣습니다.
			que.pop();
			que.push(temp);
			
		}
		else
		{
			//만약 그런 프로세스가 없다면 방금 꺼낸 프로세스를 실행합니다.
			que.pop();
			count[temp.second]--;
			anwser++;
			if (temp.first == location)
			{
				break;
			}
		}
		//cout << endl;
	}

	
	return anwser;
}
