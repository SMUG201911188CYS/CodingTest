#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string play_time, string adv_time, vector<string> logs) 
{
    auto calculateTime = [](const string &time) 
    {
        int HH, MM, SS;
        sscanf(time.c_str(), "%d:%d:%d", &HH, &MM, &SS);
        return HH * 3600 + MM * 60 + SS;
    };

    auto formatterTime = [](int time) 
    {
        int HH = time / 3600;
        int MM = (time % 3600) / 60;
        int SS = time % 60;
        char buffer[9];
        sprintf(buffer, "%02d:%02d:%02d", HH, MM, SS);
        return string(buffer);
    };

    int pt = calculateTime(play_time);
    int at = calculateTime(adv_time);
    vector<long long> times(pt + 1, 0);

    for (const auto& log : logs) 
    {
        int ws = calculateTime(log.substr(0, 8));
        int we = calculateTime(log.substr(9, 8));
        times[ws]++;
        times[we]--;
    }

    for (int i = 1; i <= pt; ++i)
    {
        times[i] += times[i - 1];
    }
    
    for (int i = 1; i <= pt; ++i)
    {
        times[i] += times[i - 1];
    }   

    long long sum = times[at - 1];
    int idx = 0;

    for (int i = at; i <= pt; ++i) 
    {
        long long tempSum = times[i] - times[i - at];
        if (sum < tempSum) 
        {
            sum = tempSum;
            idx = i - at + 1;
        }
    }

    return formatterTime(idx);
}