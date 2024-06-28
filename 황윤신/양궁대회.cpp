#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

//점수차 - 라이언이 쏜 화살 배열 리스트
map<int, vector<vector<int>>> lion_info_list;

//현재 제일 높은 점수차 
int max_score_gap = -1;

void print_lion_info(vector<int>& lion_info) {
    for (int a : lion_info) {
        cout << a << ' ';
    }
    cout << "\n\n";
}

//10점~0점을 몇 발 맞힐 지 횟수 정하기
void set_min_arrow(int now_idx, int last_arrow, int peach_sum, vector<int>& peach_info, int lion_sum, vector<int>& lion_info) {

    //now_idx = 0 => info 배열에서 10점이 위치한 자리

    if (now_idx == 11) {
        //화살을 다 맞췄다.


        if (peach_sum < lion_sum) {
            //라이언의 우승
            int score_gap = lion_sum - peach_sum;

            if (max_score_gap <= score_gap) {
                lion_info_list[score_gap].push_back(lion_info);
                max_score_gap = score_gap;

                if (lion_info[0] == 0) {
                    //cout << "lion_sum : " << lion_sum << "peach_score : " << peach_total << '\n';
                    //print_lion_info(lion_info);
                }
            }
        }

        return;
    }

    //마지막 화살이면 자동으로 남은 화살 배정
    if (now_idx == 10) {

        int arrow = last_arrow;
        int lion_score = 0;
        int peach_score = 0;
        if (peach_info[now_idx] < arrow) {
            lion_score = 10 - now_idx;
        }
        else {
            peach_score = 10 - now_idx;
        }

        //다음 점수 화살 날리기
        lion_info[now_idx] = arrow;
        set_min_arrow(now_idx + 1, last_arrow - arrow, peach_sum + peach_score, peach_info, lion_sum + lion_score, lion_info);
        lion_info[now_idx] = 0;

    }
    else {
        //날릴 화살 정하기 
        for (int arrow = 0; arrow <= last_arrow; arrow++) {
            int lion_score = 0;
            int peach_score = 0;

            if (peach_info[now_idx] < arrow) {
                lion_score = 10 - now_idx;
            }
            else {
                if (peach_info[now_idx] != 0) {
                    peach_score = 10 - now_idx;
                }
            }

            //다음 점수 화살 날리기
            lion_info[now_idx] = arrow;
            set_min_arrow(now_idx + 1, last_arrow - arrow, peach_sum + peach_score, peach_info, lion_sum + lion_score, lion_info);
            lion_info[now_idx] = 0;

        }
    }





}


vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<int> lion_info(11);
    //화살은 110발이 total
    set_min_arrow(0, n, 0, info, 0, lion_info);

    if (max_score_gap == -1) answer.push_back(-1);
    else {
        int min_idx = 10;
        int min_num = 200;
        int idx = 0;
        //cout << max_score_gap;
        for (vector<int> v : lion_info_list[max_score_gap]) {

            if (idx == 0) {
                for (int i = 10; i >= 0; i--) {
                    if (v[i] > 0) {
                        min_idx = i;
                        min_num = v[i];
                        answer = v;
                        break;
                    }
                }
            }
            else {
                for (int i = 10; i >= 0; i--) {
                    if (min_idx < i && v[i] > 0) {
                        min_idx = i;
                        min_num = v[i];
                        answer = v;
                    }
                    else if (min_idx == i && v[i] > 0 && min_num < v[i]) {
                        min_idx = i;
                        min_num = v[i];
                        answer = v;
                    }

                }
            }

            idx++;
        }
    }

    return answer;
}

int main(int argc, char** argv) {
    int n = 5;
    vector<int> info{ 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};

    //int n = 1;
    //vector<int> info{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    //int n = 10;
    //vector<int> info{0,0,0,0,0,0,0,0,3,4,3};

    vector<int> answer = solution(n, info);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
}