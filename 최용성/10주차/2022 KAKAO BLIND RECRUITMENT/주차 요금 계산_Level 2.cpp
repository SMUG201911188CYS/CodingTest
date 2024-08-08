#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;

void string_split(string carNum, string inTime_str, string outTime_str, map<string, string> & IO_History, map<string, int> & result)
{
    //cout << "Out, ";
    //cout << IO_History[carNum] << ", " << carNum << '\n';

    int inTime_H = stoi(inTime_str.substr(0, 2));
    int inTime_M = stoi(inTime_str.substr(3));
    int outTime_H = stoi(outTime_str.substr(0, 2));
    int outTime_M = stoi(outTime_str.substr(3));

    //cout << inTime_H << ", " << inTime_M << '\n';
    //cout << outTime_H << ", " << outTime_M << '\n';

    result[carNum] += ((outTime_H - inTime_H) * 60) + (outTime_M - inTime_M);
    IO_History.erase(carNum);
    //cout << result[carNum] << '\n';

}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    int defaultTime = fees[0];
    int defaultFee = fees[1];
    double unitTime = fees[2];
    int unitFee = fees[3];
    
    map<string, string> IO_History;
    map<string, int> result;
    
    string time;
    string carNum;
    string history;
    
    for(int i = 0; i < records.size(); i++)
    {
        stringstream temp(records[i]);
        temp >> time >> carNum >> history;
        
        //cout << time << ", " << carNum << ", " << history << '\n';
        
        if(history == "IN")
        {
            IO_History[carNum] = time;
        }
        else
        {
            string_split(carNum, IO_History[carNum], time, IO_History, result);
        }
    }
    
    for(auto itr : IO_History)
    {
        string_split(itr.first, IO_History[itr.first], "23:59", IO_History, result);
        
    }
    
    
    for(auto itr : result)
    {
        //cout << itr.first << ", " << itr.second << '\n';
        
        int result_fee = defaultFee;
        
        if(itr.second - defaultTime > 0)
        {
            double temp = (itr.second - defaultTime) / unitTime;
            result_fee += ceil(temp) * unitFee;
        }
        
        answer.push_back(result_fee);
    }
    
    return answer;
}