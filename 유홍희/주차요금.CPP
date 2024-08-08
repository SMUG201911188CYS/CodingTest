#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<string>> parking; // 각 차량의 주차 기록을 저장할 맵

    for (const auto& record : records) {
        stringstream ss(record);
        string time = "";
        string car_num = "";
        string in_out = "";

        ss >> time;
        ss >> car_num;
        ss >> in_out;

        parking[car_num].push_back(time); // 차량 번호를 키로 하여 주차 시간을 저장
    }

    for (auto& car : parking) {
        // 출차 내역이 없다면 23:59에 출차된 것으로 간주한다.
        if (car.second.size() % 2 == 1) {
            car.second.push_back("23:59");
        }

        int parkingtime = 0; // 총 주차 시간을 저장할 변수
        int c_size = car.second.size(); // 현재 차량의 주차 기록 수
        int in_hour, out_hour; // 입차 시간의 시(hour), 출차 시간의 시(hour)
        int in_min, out_min; // 입차 시간의 분(minute), 출차 시간의 분(minute)
        for (int i = 0; i < c_size; i++) {
            // 입차 시간
            if (i % 2 == 0) {
                in_hour = stoi(car.second[i].substr(0, 2));
                in_min = stoi(car.second[i].substr(3, 2));
            }
            // 출차 시간
            else {
                out_hour = stoi(car.second[i].substr(0, 2));
                out_min = stoi(car.second[i].substr(3, 2));

                // 입차 시간과 출차 시간의 차이를 계산하여 총 주차 시간에 더한다
                if ((out_min - in_min) < 0) {
                    parkingtime += (out_hour - in_hour - 1) * 60 + (out_min - in_min + 60);
                } else {
                    parkingtime += (out_hour - in_hour) * 60 + (out_min - in_min);
                }
            }
        }

        // 주차 시간이 기본 시간 이하이면 기본 요금을 청구
        if (parkingtime <= fees[0]) {
            answer.push_back(fees[1]);
        }
        // 주차 시간이 기본 시간을 초과하면 추가 요금을 계산
        else {
            int fee = fees[1] + ceil((double)(parkingtime - fees[0]) / fees[2]) * fees[3];
            answer.push_back(fee);
        }
    }

    return answer; // 각 차량의 주차 요금을 반환
}