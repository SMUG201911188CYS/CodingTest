#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool find_str(string tree, string skill)
{
    int before_point;
    int current_point;
    
    before_point = tree.find_first_of(skill[0]);
    
    if(before_point == -1)
        before_point = 99999;
    
    for(int i = 1; i < skill.length(); i++)
    {
        current_point = tree.find_first_of(skill[i]);
        if(current_point == -1)
            current_point = 99999;
        
        if(current_point < before_point)
            return false;
        
        before_point = current_point;
    }
    
    return true;
}

int solution(string skill, vector<string> skill_trees) { 
    int answer = 0;
    
    for(int i = 0; i < skill_trees.size(); i++)
    {
        if(find_str(skill_trees[i], skill))
        {
            answer++;
        }
    }
    
    return answer;
}