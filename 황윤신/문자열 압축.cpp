#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s) {
    int answer = s.size();
    for (int token_size = 1; token_size <= (s.size() / 2); token_size++) {
        int offset = 0; int now_str_size = 0; string pre_token = "";
        int same_num = 1;
        while (offset < s.size()) {
            string token = s.substr(offset, token_size);
            if (token == pre_token) {
                same_num++;
            }
            else {
                if (same_num >= 2) {
                    now_str_size += to_string(same_num).size();
                    same_num = 1;
                }
                pre_token = token;
                now_str_size += token.size();
            }
            offset += token.size();
        }

        if (same_num >= 2) {
            now_str_size += to_string(same_num).size();
        }
        answer = min(answer, now_str_size);
    }
    return answer;
}
