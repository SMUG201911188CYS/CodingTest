#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> answer;

unordered_map<string, int> order_map;

bool cmp(pair<string, int> &a, pair<string, int> &b){
    return a.second > b.second;
}
void find_combination(string order, int length, string combination, int index)
{
    if(length == combination.length())
    {
        order_map[combination]++;
        return;
    }
    
    for(int i = index; i < order.length(); i++)
    {
        find_combination(order, length, combination + order[i], i + 1);
    }
    
}
vector<string> solution(vector<string> orders, vector<int> course) {
    
    for(int i = 0; i < course.size(); i++)
    {
        for(int j = 0; j < orders.size(); j++)
        {
            sort(orders[j].begin(), orders[j].end());
            find_combination(orders[j], course[i], "", 0);
        }
        
        /*for(auto it = order_map.begin(); it != order_map.end(); it++)
            cout << it->first << ", " << it->second << '\n';
        */
        if(!order_map.empty())
        {
            vector< pair<string, int> > sort_map(order_map.begin(), order_map.end());
            sort(sort_map.begin(), sort_map.end(), cmp);
            int max_order = sort_map[0].second;
            
            if(max_order < 2)
                continue;
            
            answer.push_back(sort_map[0].first);
            //cout << sort_map[0].first << " " << sort_map[0].second << '\n';
            
            for(int i = 1; i < sort_map.size(); i++)
            {  
                //cout << sort_map[i].first << " " << sort_map[i].second << '\n';
                if(sort_map[i].second != max_order)
                {
                    break;
                }
                answer.push_back(sort_map[i].first);
            }
        }
        
        order_map.clear();
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}