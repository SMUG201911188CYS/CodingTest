#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_unique(vector<string> comb) {
    int comb_size = comb.size();

    for (int i = 0; i < comb_size; i++)
        if (find(comb.begin() + i + 1, comb.end(), comb[i]) != comb.end())
            return false;

    return true;
}

bool is_min(vector<string> candkey, string key) {
    bool check = true;

    for (const auto& ckey : candkey) {
        for (const auto& c : ckey) {
            if (key.find(c) == string::npos) {
                check = true;
                break;
            }
            else check = false;
        }
        if (!check) return false;
    }

    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int size = relation[0].size();
    vector<vector<int>> comb;
    vector<vector<string>> combinfo;
    vector<string> key;
    vector<string> candkey;

    for (int i = 0; i < size; i++) {
        vector<int> tmp;
        for (int j = 0; j < size; j++) {
            if (j <= i) {
                tmp.push_back(1);
            }
            else {
                tmp.push_back(0);
            }
        }
        comb.push_back(tmp);
    }

    for (auto& c : comb) {
        do {
            vector<string> tmp;
            string s = "";
            for (const auto& low : relation) {
                s = "";
                for (int i = 0; i < size; i++) 
                    if (c[i] == 1) s += low[i];
                tmp.push_back(s);
            }
            combinfo.push_back(tmp);

            s = "";
            for (int i = 0; i < size; i++)
                if (c[i] == 1)
                    s += to_string(i);
                    
            key.push_back(s);
                    
        } while (prev_permutation(c.begin(), c.end()));
    }

    int combinfo_size = combinfo.size();
    for (int i = 0; i < combinfo_size; i++) {
        if (is_unique(combinfo[i])) {
            if (candkey.empty()) candkey.push_back(key[i]);
            else if (is_min(candkey, key[i])) candkey.push_back(key[i]);
        }
    }

    answer = candkey.size();
    return answer;
}
