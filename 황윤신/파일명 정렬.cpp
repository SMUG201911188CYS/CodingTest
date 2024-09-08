#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct file_info {
    string head;
    int number;
    int order;
};
map<string, file_info> table;

bool compare(const string& a, const string& b) {
    if (table[a].head == table[b].head) {
        if (table[a].number == table[b].number) {
            return table[a].order < table[b].order;
        }
        else return table[a].number < table[b].number;
    }
    else return table[a].head < table[b].head;
}

void split_files(vector<string>& files) {
    int now_order = 0;

    for (string s : files) {
        int number_cnt = 0;
        string tmp = "";
        file_info info;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (c >= '0' && c <= '9') {
                //숫자
                if (!number_cnt) {
                    transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
                    info.head = tmp;
                    tmp = "";
                }

                if (number_cnt >= 5) break;
                number_cnt++;
            }
            else {
                //문자
                if (number_cnt) break;
            }
            tmp += c;
        }

        info.number = stoi(tmp);
        info.order = now_order++;
        table[s] = info;
    }
}

vector<string> solution(vector<string> files) {
    split_files(files);
    sort(files.begin(), files.end(), compare);
    return files;
}