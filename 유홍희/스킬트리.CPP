#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) 
{
    int answer = 0;

    for(int i = 0; i < skill_trees.size(); i++) 
    {
        string skill_tree = skill_trees[i];
        int skill_idx = 0;

        bool is_valid = true;
        for(char c : skill_tree) 
        {
            size_t pos = skill.find(c);
            if (pos != string::npos) 
            {
                if (pos == skill_idx) 
                {
                    skill_idx++;
                } 
                else 
                {
                    is_valid = false;
                    break;
                }
            }
        }

        if (is_valid) 
        {
            answer++;
        }
    }

    return answer;
}