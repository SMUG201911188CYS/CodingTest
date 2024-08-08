#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <iostream>

using namespace std;

int calc_time(string& in, string& out) {
    int out_time = stoi(out.substr(0, 2)) * 60 + stoi(out.substr(3, 2));
    int in_time = stoi(in.substr(0, 2)) * 60 + stoi(in.substr(3, 2));

    return out_time - in_time;
}

int calc_fee(int& time, vector<int>& fees) {
    double surcharge_time = time - fees[0];

    if (surcharge_time > 0)
        return fees[1] + ceil(surcharge_time / fees[2]) * fees[3];

    return fees[1];
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<string> plate;
    vector<string> _record(3);
    unordered_map<string, string> um;
    unordered_map<string, int> receipts;

    for (string record : records) {
        istringstream iss(record);
        iss >> _record[0] >> _record[1] >> _record[2];

        auto it = um.find(_record[1]);

        if (_record[2] == "IN") {
            um.insert({ _record[1],_record[0] });
        }
        else {
            int time = calc_time(it->second, _record[0]);

            if (receipts.find(_record[1]) != receipts.end())
                receipts[_record[1]] += time;
            else
                receipts[_record[1]] = time;

            um.erase(_record[1]);
        }
    }

    for (auto remained : um) {
        string out = "23:59";
        int time = calc_time(remained.second, out);

        if (receipts.find(remained.first) != receipts.end())
            receipts[remained.first] += time;
        else
            receipts[remained.first] = time;
    }

    for (auto receipt : receipts)
        plate.push_back(receipt.first);

    sort(plate.begin(), plate.end());

    for (auto _plate : plate)
        answer.push_back(calc_fee(receipts[_plate], fees));

    return answer;
}