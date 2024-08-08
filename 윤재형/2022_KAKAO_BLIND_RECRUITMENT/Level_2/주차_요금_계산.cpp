#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<pair<int, string>> cars;
    for(auto &i : records){
        if(i.find("IN") != string::npos){
            string hour = i.substr(0, 2);
            string min = i.substr(3, 2);
            string car_num = i.substr(6, 4);
            auto it = find_if(cars.begin(), cars.end(),
                              [&car_num](const pair<int, string> &element){
                                  return element.second == car_num;
                              });
            if(it != cars.end()){
                it->first -= stoi(hour) * 60 + stoi(min);
            }
            else
                cars.push_back(make_pair((stoi(hour) * 60 + stoi(min)) * -1, car_num));
        }
        else if(i.find("OUT")){
            string hour = i.substr(0, 2);
            string min = i.substr(3, 2);
            string car_num = i.substr(6, 4);
            auto it = find_if(cars.begin(), cars.end(),
                              [&car_num](const pair<int, string> &element){
                                  return element.second == car_num;
                              });
            it->first += stoi(hour) * 60 + stoi(min);
        }
    }
    
    sort(cars.begin(), cars.end(), [](const pair<int, string> &a, const pair<int, string> &b){
       return a.second < b.second;
    });
    
    for(auto i : cars){
        if(i.first <= 0) i.first += 1439;
        if(i.first <= fees[0]) answer.push_back(fees[1]);
        else
            answer.push_back(ceil((double)(i.first - fees[0]) / fees[2]) * fees[3] + fees[1]);
    }
    
    return answer;
}
