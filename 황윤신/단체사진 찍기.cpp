#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

char arr[8];
bool visit[8];
int data_size;
int ret;



//쿼리문 판별
bool check(string& s, vector<string>& data) {
    bool flag = true;
    for (int i = 0; i < data.size(); i++) {
        char query = data[i][3];
        int gap = data[i][4] - '0';

        char c1 = data[i][0];
        char c2 = data[i][2];

        int c1_idx = 0;
        int c2_idx = 0;

        int now_gap = 0;
        for (int i = 0; i < data_size; i++) {
            if (c1 == s[i]) {
                c1_idx = i;
            }
            else if (c2 == s[i]) {
                c2_idx = i;
            }

        }

        if (c1_idx <= c2_idx) {
            now_gap = c2_idx - c1_idx - 1;
        }
        else {
            //1 2
            //2-1 = 1 -1 = 0 
            now_gap = c1_idx - c2_idx - 1;
        }


        if (query == '=') {
            if (now_gap != gap) flag = false;
        }
        else if (query == '<') {
            if (now_gap >= gap) flag = false;
        }
        else if (query == '>') {
            if (now_gap <= gap) flag = false;
        }
    }

    return flag;

}

//수열 만들기
void go(int depth, string s, vector<string>& data) {
    if (depth == data_size) {
        //수열 완성
        if (check(s, data)) {
            ret++;
            return;
        }
    }

    for (int i = 0; i < data_size; i++) {
        if (visit[i] == false) {
            visit[i] = true;
            s += arr[i];

            go(depth + 1, s, data);

            s.pop_back();
            visit[i] = false;
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    arr[0] = 'A'; arr[1] = 'C';
    arr[2] = 'F'; arr[3] = 'J';
    arr[4] = 'M'; arr[5] = 'N';
    arr[6] = 'R'; arr[7] = 'T';

    data_size = 8;
    memset(visit, false, sizeof(visit));
    string str = "";
    ret = 0;

    for (int i = 0; i < data_size; i++) {
        visit[i] = true;
        str = arr[i];

        go(1, str, data);

        str = "";
        visit[i] = false;
    }

    int answer = ret;
    return answer;
}

