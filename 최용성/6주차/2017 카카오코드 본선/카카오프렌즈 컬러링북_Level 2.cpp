#include <vector>
#include <iostream>
#include <queue>

using namespace std;
int maxSize;
int maxArea;

void find_size(int m, int n, int a, int b, vector<vector<int>> picture, vector<vector<bool>> & check)
{
    queue<pair<int, int>> q;
    q.push(make_pair(a, b));
    
    check[a][b] = false;
    maxArea++;
    
    int dir1[] = {1, -1, 0, 0};
    int dir2[] = {0, 0, -1, 1};
    
    int size = 1;
    int target = picture[a][b];
    int a_temp = 0;
    int b_temp = 0;
    
    while(!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            a_temp = temp.first + dir1[i];
            b_temp = temp.second + dir2[i];
            //cout << a_temp << ", " << b_temp << '\n';
            if(a_temp >= m || a_temp < 0 || b_temp >= n || b_temp < 0)
                continue;
            if(picture[a_temp][b_temp] != target || !check[a_temp][b_temp])
                continue;
            
            q.push(make_pair(a_temp, b_temp));
            size++;
            check[a_temp][b_temp] = false;
        }
    }
    
    if(maxSize < size)
    {
        maxSize = size;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<vector<bool>> check(m, vector<bool>(n, true));
    
    maxSize = 0;
    maxArea = 0;
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(picture[i][j] != 0 && check[i][j])
                find_size(m, n, i, j, picture, check);
        }
    }
    
    vector<int> answer(2);
    answer[0] = maxArea;
    answer[1] = maxSize;
    return answer;
}