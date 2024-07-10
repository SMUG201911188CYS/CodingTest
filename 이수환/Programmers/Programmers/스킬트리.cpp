#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<bool> isSkill(27, false);
    for (int num : skill) {
        isSkill[num - 'A'] = true;
    }

    for (string skill_tree : skill_trees) {
        int curSkillNum = 0;
        bool count = true;
        for (int num : skill_tree) {
            if (isSkill[num - 'A']) {
                if (!(num == (int)skill[curSkillNum++])) {
                    count = false;
                    break;
                }
            }
        }
        if (count)
            answer++;
    }


    return answer;
}