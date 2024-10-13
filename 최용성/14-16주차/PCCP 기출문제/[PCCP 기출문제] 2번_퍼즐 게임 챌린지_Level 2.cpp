#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int minimun_level = 100001;

vector<int> _diffs;
vector<int> _times;

long long _limit;


bool check(int level, int length)
{
    long long time_amt = 0;
    long long time_cur = 0;
    long long time_prev = 0;
    
    for(int i = 0; i < length; i++)
    {
        time_cur = _times[i];
        time_prev = _times[i-1];
        
        int retry = _diffs[i] - level <= 0 ? 0 : _diffs[i] - level;
        
        if(retry >= 1)
        {
            time_amt += (_times[i] + time_prev) * retry + _times[i];
        }
        else
        {
            time_amt += _times[i];
        }
        
    }
    
    //cout << level << "," << time_amt << '\n';
    
    if(time_amt > _limit)
        return false;
    
    return true;
}


int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int length = diffs.size();
    
    _diffs = diffs;
    _times = times;
    _limit = limit;
    
    int low = 1;
    int high = 100000;
    
    while(low <= high)
    {
        int mid = (low + high) / 2;
        
        if(check(mid, length))
        {
            minimun_level = min(minimun_level, mid);
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    
    return minimun_level;
}