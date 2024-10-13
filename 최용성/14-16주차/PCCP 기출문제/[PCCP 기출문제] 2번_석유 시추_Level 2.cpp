#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <set>
#include <map>

using namespace std;

int _x[4] = {1, 0, -1, 0};
int _y[4] = {0, 1, 0, -1};

int max_oil;

vector<vector<int>> l;
vector<vector<int>> check_l;
map<int, int> oil_sum;

void findOil(int x, int y, int x_size, int y_size)
{
    
    queue<pair<int, int>> q;
    set<int> s;
    int oil = 1;
    
    check_l[x][y] = 0;
    
    q.emplace(x, y);
    s.insert(y);
    
    while(!q.empty())
    {
        pair<int,int> current_point = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int next_x = current_point.first + _x[i];
            int next_y = current_point.second + _y[i];
            
            if(next_x < 0 || next_x >= x_size)
                continue;
            if(next_y < 0 || next_y >= y_size)
                continue;
            if(l[next_x][next_y] != 1)
                continue;
            if(check_l[next_x][next_y] != 1)
                continue;
            
            oil++;
            
            check_l[next_x][next_y] = 0;
            
            q.emplace(next_x, next_y);
            s.insert(next_y);
        }
    }

    for(auto x_has_oil : s)
    {
        //cout << x_has_oil << ", " << x_oil_count[x_has_oil] << '\n';
        oil_sum[x_has_oil] += oil;
        //cout << x_has_oil << ", " << x_oil_count[x_has_oil] << '\n';
        max_oil = max(max_oil, oil_sum[x_has_oil]);
    }
}

int solution(vector<vector<int>> land) {
    l = land;
    check_l = land;
    int x_size = land[0].size();
    int y_size = land.size();
    max_oil = 0;
    
    for(int i = 0; i < x_size; i++)
    {
        for(int j = 0; j < y_size; j++)
        {
            if(check_l[j][i] == 1)
                findOil(j, i, y_size, x_size);
        }
    }

    //cout << max_oil << '\n';
    return max_oil; 
}