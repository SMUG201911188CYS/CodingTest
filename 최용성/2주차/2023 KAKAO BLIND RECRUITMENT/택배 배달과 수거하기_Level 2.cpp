#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> del_vec;
vector<int> pick_vec;
int _cap;

long long del_point;
long long pick_point;

long long find_Delivery()
{
    
    while(del_point >= 0 && del_vec[del_point] == 0)
    {
        del_point--;
    }
    
    if(del_point < 0)
        return 0;
    
    long long del_result = del_point +1;
    int temp = _cap;
    
    while(temp)
    {
        cout << "del point : " << del_point << " del : " << del_vec[del_point] << '\n';
        
        if(del_point < 0)
        {
            return del_result;
        }
        
        if(del_vec[del_point] == 0)
        {
            del_point--;
            continue;
        }
        
        if(del_vec[del_point] - temp > 0)
        {
            del_vec[del_point] -= temp;
            temp = 0;
        }
        else if(del_vec[del_point] - temp == 0){
            del_vec[del_point] -= temp;
            temp = 0;
            del_point--;
        }
        else {
            temp -= del_vec[del_point];
            del_vec[del_point] = 0;
            del_point--;
        }
    }
    
    return del_result;
}

long long find_Pickup(long long del_result)
{
    
    while(pick_point >= 0 && pick_vec[pick_point] == 0)
    {
        pick_point--;
    }
    
    if(pick_point < 0)
        return 0;
    
    long long pick_result = pick_point +1;
    long long pick_del_distance;
    int temp = _cap;
    
    while(temp)
    {
        cout << "pick point : " << pick_point << " pick : " << pick_vec[pick_point] << '\n';
        
        if(pick_point < 0)
        {
            return pick_result;
        }
        
        if(pick_vec[pick_point] == 0)
        {
            pick_point--;
            continue;
        }
        
        if(pick_vec[pick_point] - temp > 0)
        {
            pick_vec[pick_point] -= temp;
            temp = 0;
        }
        else if(pick_vec[pick_point] - temp == 0){
            pick_vec[pick_point] -= temp;
            temp = 0;
            pick_point--;
        }
        else {
            temp -= pick_vec[pick_point];
            pick_vec[pick_point] = 0;
            pick_point--;
        }
    }
    
    return pick_result;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    del_vec = deliveries;
    pick_vec = pickups;
    
    del_point = n-1;
    pick_point = n-1;
    _cap = cap;
    
    while(pick_point >= 0 || del_point >= 0)
    {
        long long temp = 0;
        long long temp1 = 0;
        temp += find_Delivery();
        cout << "del 거리 : " << temp << '\n';
        
        temp1 += find_Pickup(temp);
        cout << "pick 거리 : " << temp1 << '\n';
        
        
        if(temp1 == 0 || temp == 0)
        {
            answer += (temp1 + temp) * 2;
        }
        else
        {
            if(temp1 >= temp)
            {
                answer += temp1 + temp + (temp1 - temp);    
            }
            else
            {
                answer += temp1 + temp + (temp - temp1);
            }
        }
    }
    
    return answer;
}