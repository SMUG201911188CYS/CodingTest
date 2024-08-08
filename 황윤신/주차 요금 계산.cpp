#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
using namespace std;

int Carculate_parking(float car_elapsed_time, vector<int>& fees) {
    int car_fee = fees[1];
    if (car_elapsed_time > fees[0]) {
        car_elapsed_time -= fees[0];
        //올림 함수
        car_fee += ceil(car_elapsed_time / fees[2]) * fees[3];
    }
    return car_fee;
}

struct info {
    bool is_in_flag;
    int sum_time;
    int in_time;
};

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, info> in_table;
    int car_time_max = 23 * 60 + 59;
    for (int i = 0; i < records.size(); i++) {
        stringstream ss(records[i]);
        string car_num = ""; string car_time = ""; string state = "";
        ss >> car_time >> car_num >> state;

        int car_time_int = stoi(car_time.substr(0, 2)) * 60 + stoi(car_time.substr(3, 2));
        if (state == "IN") {
            //없으면 입차 테이블에 기록
            in_table[car_num].is_in_flag = true;
            in_table[car_num].in_time = car_time_int;
        }
        else {
            //있으면 누적 주차시간 계산
            in_table[car_num].sum_time += car_time_int - in_table[car_num].in_time;
            in_table[car_num].is_in_flag = false;
            in_table[car_num].in_time = 0;
        }
    }

    for (auto p : in_table) {
        info i = p.second;
        if (i.is_in_flag == true) {
            i.sum_time += (car_time_max - in_table[p.first].in_time);
        }
        answer.push_back(Carculate_parking(i.sum_time, fees));
    }

    return answer;
}