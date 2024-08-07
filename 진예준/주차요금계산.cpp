#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    int basic_minute = fees[0];
    int basic_fee = fees[1];
    int minute = fees[2];
    int unit = fees[3];

    auto timeToMinutes = [](const string& time) -> int {
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3, 2));
        return hours * 60 + minutes;
        };

    set<string> car;
    for (const auto& record : records)
    {
        car.insert(record.substr(6, 4));
    }

    unordered_map<string, int> total_fees;
    for (const auto& c : car)
    {
        total_fees[c] = 0;
    }

    unordered_map<string, string> check;
    for (const auto& record : records)
    {
        string tmp_time = record.substr(0, 5);
        string tmp_car = record.substr(6, 4);
        string tmp_status = record.substr(11, 3);

        if (check.find(tmp_car) == check.end())
        {
            check[tmp_car] = tmp_time;
        }
        else {
            if (tmp_status == "OUT")
            {
                int out_time = timeToMinutes(tmp_time);
                int in_time = timeToMinutes(check[tmp_car]);
                total_fees[tmp_car] += out_time - in_time;
                check.erase(tmp_car);
            }
        }
    }

    if (!check.empty())
    {
        for (const auto& c : check) {
            int out_time = 1439; // 마지막 시간 23시 59분을 분으로 환산
            int in_time = timeToMinutes(c.second);
            total_fees[c.first] += out_time - in_time;
        }
    }

    vector<pair<string, int>> result;
    for (const auto& fee : total_fees)
    {
        if (fee.second <= basic_minute)
        {
            result.push_back({ fee.first, basic_fee });
        }
        else
        {
            result.push_back({ fee.first, basic_fee + static_cast<int>(ceil((fee.second - basic_minute) / static_cast<double>(minute)) * unit) });
        }
    }

    sort(result.begin(), result.end());

    vector<int> final_result;
    for (const auto& r : result)
    {
        final_result.push_back(r.second);
    }

    return final_result;
}
