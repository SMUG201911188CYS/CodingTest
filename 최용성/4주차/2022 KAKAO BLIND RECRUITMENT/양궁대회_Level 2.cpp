#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> answer = {-1};
int maxScore = 0;

void print_vec(vector<int> v1, vector<int> v2)
{
    cout << "v1 shoot : ";
    for(auto it = v1.begin(); it != v1.end(); it++)
        cout << *it << ", ";
    cout << '\n';
    cout << "v2 shoot : ";
    for(auto it = v2.begin(); it != v2.end(); it++)
        cout << *it << ", ";
    cout << '\n';
}

void dfs(int count, int n, int depth, vector<int> lion, vector<int> info)
{
    if(count == n)
    {
        int lion_score = 0;
        int apache_score = 0;
        
        for(int i = 0; i < 10; i++)
        {
            if(lion[i] > info[i])
                lion_score += 10 - i;
            else if(info[i] > 0)
                apache_score += 10 - i;
        }
        
        lion_score -= apache_score;
        if(lion_score)
        {           
            if(lion_score > maxScore)
            {
                cout << "max : " << maxScore << ", lion : " << lion_score << '\n';
                maxScore = lion_score;
                answer = lion;   
            }
            else if(lion_score == maxScore)
            {
                for(int i = 10; i >= 0; i--)
                {
                    if(answer[i] > lion[i])
                    {
                        break;
                    }
                    else if(answer[i] < lion[i])
                    {
                        answer = lion;
                        break;
                    }
                }
            }
        }
        
        return;
    }
    
    for(int i = depth; i <= 10; i++)
    {
        int arrow = info[i] + 1;
        if(n - count < arrow)
            arrow = n - count;
        
        lion[i] = arrow;
        dfs(count + arrow, n, i+1, lion, info);
        lion[i] = 0;
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> lion(11, 0);
    
    dfs(0, n, 0, lion, info);
    
    return answer;
}