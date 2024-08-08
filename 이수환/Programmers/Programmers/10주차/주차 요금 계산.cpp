#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    // first - 번호, second - 요금
    unordered_map<string, int> um_cost;
    // first - 번호, second - 입차 시간, 누적 시간
    unordered_map<string, pair<int, int>> um_entry;
    
    for(auto record : records){
        istringstream iss(record);
        string time, num, entry;

        iss >> time >> num >> entry;
        if(um_cost.find(num) != um_cost.end()){
            int calTime = stoi(time.substr(0, 2))*60 + stoi(time.substr(3));
            um_cost.insert({num, 0});
            um_entry.insert({num, {0,0}});
        }
        
        
        if(entry == "IN"){
            // In일 때는 입차 시간 업데이트
            // time -> int
            int calTime = stoi(time.substr(0, 2))*60 + stoi(time.substr(3));
            um_entry[num].first = calTime;

        }else if(entry == "OUT"){
            // Out일 때는 요금 업데이트
            // 시간 계산
            int calTime = stoi(time.substr(0, 2))*60 + stoi(time.substr(3));
            um_entry[num].second += calTime - um_entry[num].first;
            um_entry[num].first = -1;
        }
    }
    
    
    vector<pair<string, pair<int, int>>> elems(um_entry.begin(), um_entry.end());
    sort(elems.begin(), elems.end());
    for(auto car : elems){
        if(car.second.first != -1){
            car.second.second += 1439 - car.second.first;
        }
        
        int result = 0;
        int totalTime = car.second.second;
        int totalCost = 0;
        
        totalTime -= fees[0];
        totalCost += fees[1];
        //cout << "TotalTime : " << totalTime << ", " << (totalTime / fees[2]) * fees[3] << '\n';
        if(totalTime > 0) {
            if((totalTime % fees[2]) > 0) totalCost += fees[3];
            totalCost += (totalTime / fees[2]) * fees[3];
        }
        
        answer.push_back(totalCost);
        //cout << car.first<< " : " << car.second.first << ", " << car.second.second << " | " << totalCost <<'\n';
    }
    
    return answer;
}