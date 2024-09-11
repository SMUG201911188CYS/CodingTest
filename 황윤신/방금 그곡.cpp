#include <string>
#include <vector>
#include <iostream>
using namespace std;

void set_vec(vector<pair<string, pair<string, int>>>& title_melody_vec, vector<string>& musicinfos) {
    for (string info : musicinfos) {
        int cnt = 0;
        int comma_pos = info.find(',');
        string title = "";
        string melody = "";
        int start_time = 0, end_time = 0;

        while (comma_pos != string::npos) {
            string tmp = info.substr(0, comma_pos);
            if (cnt == 0) {
                start_time = (stoi(tmp.substr(0, 2)) * 60) + (stoi(tmp.substr(3)));
            }
            else if (cnt == 1) {
                end_time = (stoi(tmp.substr(0, 2)) * 60) + (stoi(tmp.substr(3)));
            }
            else if (cnt == 2) {
                title = tmp;
            }
            info = info.substr(comma_pos + 1);
            comma_pos = info.find(',');
            cnt++;
        }

        int gap_time = end_time - start_time;
        int offset = 0;
        string tmp = "";

        for (int i = 0; i < gap_time; i++) {
            bool sharp_flag = false;
            if (offset + 1 < info.size() && info[offset + 1] == '#') sharp_flag = true;

            tmp += info[offset];
            if (sharp_flag) {
                tmp += info[offset + 1];
                offset += 2;
            }
            else offset++;

            if (offset == info.size()) offset = 0;
        }
        melody = tmp;
        title_melody_vec.push_back(make_pair(title, make_pair(melody, gap_time)));
    }
}

void compare_melody(vector<pair<string, pair<string, int>>>& title_melody_vec, string& neo_melody, string& answer) {
    int answer_time = -1;
    for (int i = 0; i < title_melody_vec.size(); i++) {
        string title = title_melody_vec[i].first;
        string melody = title_melody_vec[i].second.first;
        int gap_time = title_melody_vec[i].second.second;

        int offset = 0;
        int melody_offset = 0;
        bool same_flag = false;

        //cout << neo_melody << " " << title << " " << melody << '\n';
        while (melody_offset < melody.size()) {
            bool melody_sharp = false, neo_melody_sharp = false;
            if (melody_offset + 1 < melody.size() && melody[melody_offset + 1] == '#') melody_sharp = true;
            if (offset + 1 < neo_melody.size() && neo_melody[offset + 1] == '#') neo_melody_sharp = true;
            //���� ������ �� 
            if (melody[melody_offset] == neo_melody[offset] && melody_sharp == neo_melody_sharp) {

                //���� ���� offset�� �÷���
                if (neo_melody_sharp) {
                    offset += 2;
                }
                else offset++;

                if (offset == neo_melody.size()) {
                    same_flag = true;
                    break;
                }
            }
            else {
                same_flag = false;
                offset = 0;

                //���� �׿� ���ڿ��� �ʱ�ȭ �ƴµ�, �׿� ���ڿ��� ù���ڿ� ���� ���ڿ��� ù���ڰ� ���ٸ�
                //���� ���ڿ��� �������� �÷��ָ� �ȵȴ�.
                neo_melody_sharp = false;
                if (offset + 1 < neo_melody.size() && neo_melody[offset + 1] == '#') neo_melody_sharp = true;
                if (melody[melody_offset] == neo_melody[offset] && melody_sharp == neo_melody_sharp) continue;
            }

            if (melody_sharp) {
                melody_offset += 2;
            }
            else melody_offset++;
        }

        if (same_flag && answer_time < gap_time) {
            answer = title;
            answer_time = gap_time;
        }
    }
}

string solution(string m, vector<string> musicinfos) {

    //first : �� ����, second.first : ��۵� ��ε� ��ü, second.second : ��۽ð�
    vector<pair<string, pair<string, int>>> title_melody_vec;

    string answer = "(None)";
    set_vec(title_melody_vec, musicinfos);
    compare_melody(title_melody_vec, m, answer);

    return answer;
}

int main(int argc, char** argv) {
    string m = "ABC";
    vector<string> musicinfos = { "12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF" };
    cout << solution(m, musicinfos);
}