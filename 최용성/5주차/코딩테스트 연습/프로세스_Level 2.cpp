#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int cmp(int a, int b)
{
    return a > b;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int, int>> q;
    
    for(int i = 0; i < priorities.size(); i++)
    {
        if(location == i)
            q.push(make_pair(priorities[i], 1));   
        else
            q.push(make_pair(priorities[i], 0));  
    }
    
    sort(priorities.begin(), priorities.end(), cmp);
    
    while(!q.empty())
    {
        pair<int, bool> temp = q.front();
        q.pop();
        
        if(temp.first == priorities[answer])
        {
            answer++;
            if(temp.second == 1)
                break;
        }
        else
            q.push(temp);
        
    }
    
    
    return answer;
}