#include <string>
#include <vector>
#include <queue>

using namespace std;

int cnt[360000];

int to_sec(string st){
    int h = stoi(st.substr(0, 2)) * 3600;
    int m = stoi(st.substr(3, 2)) * 60;
    int s = stoi(st.substr(6, 2));
    return h + m + s;
}

string to_time(int n){
    
    int s = n % 60;
    n /= 60;
    int m = n % 60;
    n /= 60;
    int h = n;
    string st = "";
    if(h < 10) st += '0';
    st += to_string(h) + ':';
    if(m < 10) st += '0';
    st += to_string(m) + ':';
    if(s < 10) st += '0';
    st += to_string(s);
    return st;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    for (string s : logs) {
        int start = to_sec(s.substr(0, 8));
        int end = to_sec(s.substr(9));
        for (int i = start; i < end; i++) cnt[i]++;
    }
    int playtime = to_sec(play_time);
    int advtime = to_sec(adv_time);

    queue<int> q;
    int idx = 0;
    long long tmp = 0; 
    long long result = 0;

    for (int i = 0; i < advtime; i++) {
        tmp += cnt[i];
        q.push(cnt[i]);
    }

    result = tmp;
    for (int i = advtime; i < playtime; i++) {
        tmp -= q.front();
        q.pop();
        tmp += cnt[i];
        q.push(cnt[i]);
        if (result < tmp) {
            result = tmp;
            idx = i - advtime + 1;
        }
    }
    answer = to_time(idx);

    return answer;
}
