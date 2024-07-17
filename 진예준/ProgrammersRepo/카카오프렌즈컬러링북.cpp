#include "카카오프렌즈컬러링북.h"

void 카카오프렌즈컬러링북::진행()
{
    int m = 6;
    int n = 4;
    vector<vector<int>> picture = 
    {
        {1, 1, 1, 0} ,
        {1, 2, 2, 0},
        {1, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 3},
        {0, 0, 0, 3} 
    };
    auto answer = solution(m, n, picture);
    cout << endl << "Solution: " << answer[0] << ", " << answer[1];
}

int acount;
int target;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int x, int y, vector<vector<bool>>& visited, vector<vector<int>>& picture)
{
    visited[x][y] = true; //방문 체크
    acount++;// 영역++
    for (int dir = 0; dir < 4; dir++) 
    {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= visited.size() || ny >= visited[0].size()) continue;
        if (visited[nx][ny] || picture[nx][ny] != target) continue;
        dfs(nx, ny, visited, picture);
    }
}


vector<int> 카카오프렌즈컬러링북::solution(int m, int n, vector<vector<int>> picture)
{
    int row = picture.size();
    int col = picture[0].size();
    vector<int> answer(2, 0);
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            // 방문하지 않았고 색칠하는 부분이면
            if (!visited[i][j] && picture[i][j]) 
            {
                answer[0]++;// 개수++
                acount = 0; target = picture[i][j];
                dfs(i, j, visited, picture);
                answer[1] = max(answer[1], acount);// 최대범위로 갱신
            }
        }
    }
    return answer;

}
