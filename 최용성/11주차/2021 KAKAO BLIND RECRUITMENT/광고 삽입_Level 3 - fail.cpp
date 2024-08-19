#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

int time_to_int(string a)
{
    int hour = stoi(a.substr(0, 2));
    int min = stoi(a.substr(3, 2));
    int sec = stoi(a.substr(6, 2));

    return (hour * 3600) + (min * 60) + sec;
}

int during_time_to_int(string a, string b)
{
    int hour = stoi(a.substr(0, 2)) + stoi(b.substr(0, 2));
    int min = stoi(a.substr(3, 2)) + stoi(b.substr(3, 2));
    int sec = stoi(a.substr(6, 2)) + stoi(b.substr(6, 2));

    /*while(sec >= 60)
    {
        sec -= 60;
        min += 1;
    }

    while(min >= 60)
    {
        min -= 60;
        hour += 1;
    }

    //cout << hour << ", " << min << ", " << sec << '\n';
    stringstream ss;
    ss << std::setfill('0') << std::setw(2) << to_string(hour) << ":" << std::setw(2) << to_string(min) << ":" << std::setw(2) << to_string(sec);
    return ss.str();
    */

    return (hour * 3600) + (min * 60) + sec;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";

    int maxCount = 0;
    int max_log = 0;
    sort(logs.begin(), logs.end());

    if (play_time == adv_time)
    {
        return "00:00:00";
    }

    for (int i = 0; i < logs.size(); i++)
    {
        int cnt = 0;

        string start_str = logs[i].substr(0, 8);
        string end_str = logs[i].substr(9, 8);

        int start_time = time_to_int(start_str);
        int end_time = time_to_int(end_str);

        int adv_end_time = during_time_to_int(start_str, adv_time);

        //cout << "current : " << start_time << '\n';     
        //cout << "during_time : " << adv_end_time << '\n';

        for (auto log : logs)
        {
            string next_start_str = log.substr(0, 8);
            string next_end_str = log.substr(9, 8);

            int next_start_time = time_to_int(next_start_str);
            int next_end_time = time_to_int(next_end_str);

            //cout << "next start : " << next_start_time << '\n';     
            //cout << "next end : " << next_end_time << '\n';

            if (next_start_str == start_str)
                continue;

            if (next_start_time >= start_time && next_start_time <= adv_end_time)
            {
                //cout << "in time : " << log << '\n';
                cnt++;
            }
            else if (next_end_time >= start_time && next_end_time <= adv_end_time)
            {
                //cout << "in time : " << log << '\n';
                cnt++;
            }
        }

        cout << '\n';

        if (maxCount < cnt)
        {
            maxCount = cnt;
            max_log = i;
            answer = start_str;
        }

    }

    //cout << "Max : " << logs[max_log] << '\n';

    return answer;
}