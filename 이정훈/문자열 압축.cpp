#include <string>
#include <vector>
#include <iostream>

using namespace std;

int compression(string& s, int& size) {
    string res;
    string pattern = s.substr(0, size);
    int pattern_cnt = 1;
    for (int i = size; i <= s.size(); i = i + size) {
        string cmp_s = s.substr(i, size);

        if (pattern == cmp_s) {
            pattern_cnt++;
        }
        else {
            if (pattern_cnt == 1)
                res += pattern;
            else {
                res += to_string(pattern_cnt) + pattern;
                pattern_cnt = 1;
            }

            pattern = cmp_s;
        }
    }

    res += s.substr(s.size() / size, s.size() % size);

    return res.size();
}

int solution(string s) {
    int answer = s.size();

    for (int i = 1; i <= s.size() / 2; i++) {
        int cmp = compression(s, i);

        if (answer > cmp)
            answer = cmp;
    }

    return answer;
}