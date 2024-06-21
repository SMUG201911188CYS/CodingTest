#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

unordered_map <string, vector<int>>um;

void addCases(string* s, int score) {
    // ---- 부터 하나씩 넣으면서 모든 경우 만들어두기
    for (int i = 0; i < 16; i++) {
        string str = "";
        int num = i;
        for (int j = 3; j >= 0; j--) {
            if (num <= 0 || num % 2 == 0)
            {
                str = "-" + str;
            }
            else str = s[j] + str;
            num /= 2;
        }
        um[str].push_back(score);
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    string s[4];
    string str = "";

    for (int i = 0; i < info.size(); i++) {
        // 공백과 개행을 빼줌
        istringstream stt(info[i]);
        stt >> s[0] >> s[1] >> s[2] >> s[3] >> str;
        addCases(s, (int)stoi(str));
    }

    // 점수로 정렬
    for (auto itr = um.begin(); itr != um.end(); itr++) {
        sort(itr->second.begin(), itr->second.end());
    }

    for (int i = 0; i < query.size(); i++) {
        istringstream stt(query[i]);
        // and 제거
        stt >> s[0] >> str >> s[1] >> str >> s[2] >> str >> s[3] >> str;
        // 마지막은 점수
        int score = (int)stoi(str);

        // 해쉬 테이블로 한 번에 찾을 수 있음
        vector<int> v = um[s[0] + s[1] + s[2] + s[3]];

        if (v.size() != 0) {
            int idx = lower_bound(v.begin(), v.end(), score) - v.begin();
            answer.push_back(v.size() - idx);
        }
        else answer.push_back(0);
    }


    return answer;
}