#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> _q1;
vector<int> _q2;
long sum;
int limit;
long q1_sum;
long q2_sum;
int answer;

int Cal()
{
    queue<int> q1, q2;
    
    for(int i = 0; i < _q1.size(); i++)
    {
        q1.push(_q1[i]);
        q2.push(_q2[i]);
        
        q1_sum += _q1[i];
        q2_sum += _q2[i];
    }
    sum = q1_sum + q2_sum;
    
    if(sum % 2 != 0)
    {
        return -1;
    }
    
    long temp = 0;
    limit = q1.size() * 2 + 1;
    
    while(!q1.empty() && !q2.empty())
    {
        if(q1_sum == q2_sum)
        {
            return answer;
        }
        
        if(answer >= limit)
        {
            break;
        }
        
        if(q1_sum > q2_sum)
        {
            temp = q1.front();
            q1.pop();
            q1_sum -= temp;
            
            q2.push(temp);
            q2_sum += temp;
        }
        else
        {
            temp = q2.front();
            q2.pop();
            q2_sum -= temp;
            
            q1.push(temp);
            q1_sum += temp;
        }
        answer++;
    }
    
    return -1;
}

int solution(vector<int> queue1, vector<int> queue2) {
    _q1 = queue1;
    _q2 = queue2;
    
    answer = Cal();
    return answer;
}