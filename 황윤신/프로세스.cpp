#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

struct process {
    int prior = 0; //�켱����
    int pos = 0; //���� ��ġ
    int process_num = 0; //���� ���� ����
};


int solution(vector<int> priorities, int location) {
    int q_size = priorities.size();
    vector<process> process_table;
    vector<int> prior;
    queue<int> q;
    int prior_num[10];
    memset(prior_num, 0, sizeof(prior_num));

    for (int i = 0; i < q_size; i++) {
        //ó�� ���� ��� ť�� ����ִ� ���μ��� ��ȣ
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

        //prior[pointer] ���� ���� ���� �켱����
        //cout << process_table[n].prior << ' ' << prior[pointer] <<' ' << pointer << '\n';
        //if(idx==5) break;
        if (process_table[n].prior >= prior[pointer]) {
            q.pop();

            //���μ��� ����
            process_table[n].process_num = idx;
            idx++;

            prior_num[prior[pointer]]--;

            if (prior_num[prior[pointer]] == 0) {
                //�״��� ���μ����� ���̱�
                pointer--;
            }
            else {

            }

        }
        else {
            //���μ��� ������ �ٽ� ����
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