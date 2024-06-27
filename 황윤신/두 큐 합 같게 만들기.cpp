#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

//궁금증 1. fp가 ep보다 더 커지는거 범위 설정 어떻게 해야하나 (원형큐라서 fp>ep 라고 작성할 수도 없음)
//궁금증 2. 왜 궁금증 1의 범위 설정 안했는데도 이왜맞 했을까
int solution(vector<int> queue1, vector<int> queue2) {
    map<string, bool> table;

    int answer = -1;

    vector<int> round_q;
    int fp = 0;
    int ep = queue1.size() - 1;
    string key = to_string(fp) + to_string(ep);
    int job_time = 0;

    int round_q_size = queue1.size() + queue2.size();
    long long ret = 0;
    long long now = 0;


    for (int i = 0; i < queue1.size(); i++) {
        round_q.push_back(queue1[i]);
        ret += queue1[i];
    }

    now = ret;

    for (int i = 0; i < queue2.size(); i++) {
        round_q.push_back(queue2[i]);
        ret += queue2[i];
    }

    if (ret % 2 == 1) return -1;
    ret /= 2;



    while (table[key] == false) {

        //cout << "fp : " << fp << " ep : " << ep << '\n';
        //cout << "now : " << now << '\n';
        //cout << '\n';

        if (now == ret) {
            if (answer == -1) answer = job_time;
            else answer = min(job_time, answer);

        }
        else if (now > ret) {
            //값을 줄여야됨
            now -= round_q[fp];
            fp = (fp + 1) % round_q.size();


        }
        else if (now < ret) {
            //값을 늘려야됨
            ep = (ep + 1) % round_q.size();
            now += round_q[ep];
        }

        table[key] = true;
        key = to_string(fp) + to_string(ep);

        job_time++;
    }


    return answer;
}
