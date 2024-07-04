#include <string>
#include <vector>

using namespace std;

struct skill_info {
    bool isEmpty;
    int num;
};

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    skill_info v[26];
    for (int i = 0; i < 26; i++) {
        v[i].isEmpty = true;
        v[i].num = 0;
    }

    for (int i = 0; i < skill.size(); i++) {
        int c = skill[i] - 'A';
        v[c].isEmpty = false;
        v[c].num = i;
    }

    for (int i = 0; i < skill_trees.size(); i++) {
        string s = skill_trees[i];

        int sk_order = 0;
        bool flag = true;
        for (int j = 0; j < s.size(); j++) {
            int c = s[j] - 'A';
            if (!v[c].isEmpty) {
                if (sk_order == v[c].num) {
                    sk_order++;

                }
                else {
                    flag = false;
                    break;
                }
            }

        }

        if (flag) answer++;


    }


    return answer;

}