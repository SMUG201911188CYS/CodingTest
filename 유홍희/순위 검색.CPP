#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

map<string, vector<int>> input_info(vector<string> info_query) {
    vector<int> comb;
    map<string, vector<int>> info_map;
    string group = "";
    int score;

    for (auto& info : info_query) {
        vector<string> jeongbo(4);
        stringstream ss(info);
        for (int i = 0; i < 4; i++) {
            ss >> jeongbo[i];
        }
        ss >> score;

        for (int i = 0; i <= 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (j < i) {
                    comb.push_back(0);
                }
                else {
                    comb.push_back(1);
                }
            }
            do { // 그룹 조합 생성
                group = "";
                for (int i = 0; i < comb.size(); i++) {
                    if (comb[i] == 0) {
                        group += "-";
                    }
                    else {
                        group += jeongbo[i];
                    }
                }
                if (info_map.count(group)) {
                    info_map[group].push_back(score);
                }
                else {
                    info_map.insert({ group, { score } });
                }
            } while (next_permutation(comb.begin(), comb.end()));
            comb.clear();
        }
    }

    return info_map;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    map<string, vector<int>> jiwonja_map = input_info(info);

    for (auto& jiwonja : jiwonja_map) {
        sort(jiwonja.second.begin(), jiwonja.second.end());
    }

    for (auto& q : query) {
        string jogeon = "";
        vector<string> jeongbo(4);
        stringstream ss(q);
        vector<int> score_list;
        int score;
        for (int i = 0; i < 4; i++) {
            ss >> jeongbo[i];
            if (jeongbo[i] == "and") {
                i--;
            }
            else {
                jogeon += jeongbo[i];
            }
        }
        ss >> score;

        score_list = jiwonja_map[jogeon];
        answer.push_back(score_list.size() - (lower_bound(score_list.begin(), score_list.end(), score) - score_list.begin()));
    }

    return answer;
}