#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

typedef struct candidate {
    vector<string> str;
    vector<int> attr_idx;
    int depth = 0;
} candidate;

int solution(vector<vector<string>> relations) {
    int answer = 0;

    int num_attributes = relations[0].size();
    int num_tuples = relations.size();

    vector<vector<string>> attr(num_attributes, vector<string>());
    vector<bool> is_candi(num_attributes, false);
    queue<candidate> preprocess_q;
    queue<candidate> q;

    for (const auto& relation : relations) {
        for (int i = 0; i < relation.size(); i++) {
            attr[i].push_back(relation[i]);
        }
    }

    for (int depth = 0; depth < num_attributes; depth++) {
        for (int i = 0; i < num_attributes; i++) {
            if (!is_candi[i]) {
                candidate candi;
                candi.str.resize(num_tuples);
                candi.attr_idx.push_back(i);

                preprocess_q.push(candi);
            }
        }

        while (!preprocess_q.empty()) {
            candidate candi = preprocess_q.front(); preprocess_q.pop();
            if (candi.depth == depth) {
                for (int idx : candi.attr_idx) {
                    for (int i = 0; i < num_tuples; i++) {
                        candi.str[i] += relations[i][idx] + " ";
                    }
                }
                q.push(candi);

                continue;
            }

            int cur_idx = candi.attr_idx.back();

            for (int i = cur_idx + 1; i < num_attributes; i++) {
                if (!is_candi[i]) {
                    candidate new_candi = candi;
                    new_candi.attr_idx.push_back(i);
                    new_candi.depth++;
                    preprocess_q.push(new_candi);
                }
            }
        }

        while (!q.empty()) {
            candidate candi = q.front(); q.pop();

            unordered_set<string> unique_tuples(candi.str.begin(), candi.str.end());

            if (unique_tuples.size() == num_tuples) {
                answer++;

                for (int idx : candi.attr_idx) {
                    is_candi[idx] = true;
                }
            }
        }
    }

    return answer;
}