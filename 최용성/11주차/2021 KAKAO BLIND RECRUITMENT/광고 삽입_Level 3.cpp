#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

// 접근 방식을 어떻게 해야할까?

// 광고의 재생 구간의 슬라이드(= 광고 슬라이드)는 고정되어 있다.
// 각 시청자들의 재생 구간의 슬라이드도 고정되어 있다.

// 시청자의 재생 구간 슬라이드 = int형 vector로 생각, vector의 각 index의 값은 1임. (begin => 시청 시작 시간, end => 시청 종료 시간)
// 여러 개의 int형 vector(시청자 재생 구간 슬라이드)를 하나의 vector로 합친다. (begin => 0, end => 3600000)
//      -> 동영상 재생 구간의 끝은 99:59:59가 최대, -> 100:00:00 - 00:00:01 -> 100 * 3600 - 1 = 359999
// 광고 슬라이드(0 - 광고 재생 시간)를 벡터와 마주 대 비교한다고 생각. (두 막대를 마주댄다고 생각.)
// 0부터 시작하여, vector의 끝까지 비교.
// 광고 슬라이드 길이 에서 vector의 index를 다 더했을때 나오는 Max값은 누적 재생시간이 가장 많은 곳.

// if vector의 size = 8, [1, 1, 2, 2, 3, 3, 1, 1], 광고 슬라이드의 길이 = 2라고 하였을 때,
//      [0, 1] = 2 / [1, 2] = 3 / [2, 3] = 4 / [3, 4] = 5 / [4, 5] = 6 / [5, 6] = 4 / [6, 7] = 2.
//      [4, 5]의 값이 제일 크다. 즉 이 곳이 누적 재생시간이 가장 많은 곳이다.

int time_to_int(string a)
{
    int hour = stoi(a.substr(0, 2));
    int min = stoi(a.substr(3, 2));
    int sec = stoi(a.substr(6, 2));

    return (hour * 3600) + (min * 60) + sec;
}

string time_to_string(int a)
{
    cout << a << '\n';
    int hour = a / 3600;
    a = a % 3600;
    int min = a / 60;
    int sec = a % 60;

    stringstream ss;
    ss << std::setfill('0') << std::setw(2) << to_string(hour) << ":" << std::setw(2) << to_string(min) << ":" << std::setw(2) << to_string(sec);
    return ss.str();
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";

    int time = 0;

    vector<int> sum(360001, 0);

    int p_time = time_to_int(play_time);
    int a_time = time_to_int(adv_time);

    if (play_time == adv_time)
    {
        return "00:00:00";
    }

    for (auto log : logs)
    {
        int start_time = time_to_int(log.substr(0, 8));
        int end_time = time_to_int(log.substr(9, 8));

        // 각 시청자의 시청 시작 시간부터,
        // 시청 끝 시간까지의 구간을 +1로 표시함.
        // -> 누적 시청 구간
        // 최종적으로 각 시청자들이 가장 많이 겹치는 구간이 표현됨.

        for (int i = start_time; i < end_time; i++)
        {
            sum[i]++;
        }

    }

    long long adv_sum = 0;
    long long adv_max_sum = 0;

    // 0부터, adv - 1 까지의 누적 시청 구간을 구함
    // 왜 -1? -> 시간 계산시, 1초 빼고 계산함
    // 1초부터 10초 -> 9초로 계산

    for (int i = 0; i < a_time; i++)
    {
        adv_sum += sum[i];
    }

    adv_max_sum = adv_sum;

    // 0 부터 adv - 1 까지의 누적 시청 구간과
    // 1 부터 adv 까지의 누적 시청 구간을 비교하면서, 최대의 재생구간을 구함.
    // 1씩 늘려감.
    // +1의 이유 -> 1초 빼고 계산한 것을 더해줌.

    for (int i = a_time; i < p_time; i++)
    {
        adv_sum -= sum[i - a_time];
        adv_sum += sum[i];

        if (adv_sum > adv_max_sum)
        {
            adv_max_sum = adv_sum;
            time = i - a_time + 1;
        }
    }

    answer = time_to_string(time);
    return answer;
}