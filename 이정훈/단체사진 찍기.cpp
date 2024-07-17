#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;

    queue<pair<vector<char>, vector<char>>> q;
    vector<char> kakao_friends = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
    vector<vector<char>> cond;

    for (string elem : data) {
        vector<char> _cond;
        _cond.push_back(elem[0]);
        _cond.push_back(elem[2]);
        _cond.push_back(elem[3]);
        _cond.push_back(elem[4]);
        cond.push_back(_cond);
    }

    for (int i = 0; i < kakao_friends.size(); i++) {
        vector<char> first;
        vector<char> second;
        for (int j = 0; j < kakao_friends.size(); j++) {
            if (i == j) {
                first.push_back(kakao_friends[j]);
            }
            else {
                second.push_back(kakao_friends[j]);
            }
        }
        q.push(make_pair(first, second));
    }

    int count = 0;

    while (!q.empty()) {
        pair<vector<char>, vector<char>> elem = q.front(); q.pop();

        if (elem.first.size() == 8) {
            bool flg = true;
            for (auto _cond : cond) {
                auto it1 = find(elem.first.begin(), elem.first.end(), _cond[0]);
                auto it2 = find(elem.first.begin(), elem.first.end(), _cond[1]);

                int it1_idx = it1 - elem.first.begin();
                int it2_idx = it2 - elem.first.begin();

                switch (_cond[2]) {
                case '=':
                    if (abs(it2_idx - it1_idx) - 1 != _cond[3] - '0') {
                        flg = false;
                    }
                    break;
                case '<':
                    if (abs(it2_idx - it1_idx) - 1 >= _cond[3] - '0') {
                        flg = false;
                    }
                    break;
                case '>':
                    if (abs(it2_idx - it1_idx) - 1 <= _cond[3] - '0') {
                        flg = false;
                    }
                    break;
                }
                if (!flg) break;
            }
            if (flg) {
                answer++;
            }
        }
        else {
            for (int i = 0; i < elem.second.size(); i++) {
                vector<char> first;
                vector<char> second;
                for (int j = 0; j < elem.second.size(); j++) {
                    if (i != j) {
                        second.push_back(elem.second[j]);
                    }
                    else {
                        first = elem.first;
                        first.push_back(elem.second[j]);
                    }
                }
                q.push(make_pair(first, second));
            }
        }
    }

    return answer;
}