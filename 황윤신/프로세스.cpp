#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

struct process {
    int prior = 0; //우선순위
    int pos = 0; //원래 위치
    int process_num = 0; //실제 실행 순서
};


int solution(vector<int> priorities, int location) {
    int q_size = priorities.size();
    vector<process> process_table;
    vector<int> prior;
    queue<int> q;
    int prior_num[10];
    memset(prior_num, 0, sizeof(prior_num));

    for (int i = 0; i < q_size; i++) {
        //처음 실행 대기 큐에 들어있는 프로세스 번호
        prior_num[priorities[i]]++;

        process p;
        p.prior = priorities[i];
        p.pos = i;
        p.process_num = 0;
        process_table.push_back(p);
        q.push(i);
    }

    sort(priorities.begin(), priorities.end());
    int prior_max = 0;

    for (int i = 0; i < q_size; i++) {


        if (priorities[i] > prior_max) {
            prior.push_back(priorities[i]);
            prior_max = priorities[i];
        }
    }


    int idx = 1;
    int pointer = prior.size() - 1;
    //cout << pointer;

    while (q.size()) {
        int n = q.front();

        //prior[pointer] 현재 제일 높은 우선순위
        //cout << process_table[n].prior << ' ' << prior[pointer] <<' ' << pointer << '\n';
        //if(idx==5) break;
        if (process_table[n].prior >= prior[pointer]) {
            q.pop();

            //프로세스 실행
            process_table[n].process_num = idx;
            idx++;

            prior_num[prior[pointer]]--;

            if (prior_num[prior[pointer]] == 0) {
                //그다음 프로세스로 줄이기
                pointer--;
            }
            else {

            }

        }
        else {
            //프로세스 빼놓고 다시 삽입
            q.pop();
            q.push(n);
        }

    }

    int answer = process_table[location].process_num;
    return answer;
}

int main(int argc, char** argv) {
    vector<int> v = { 1,1,9,1,1,1 };
    int location = 0;
    cout << solution(v, location);

}