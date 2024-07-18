#include <vector>

using namespace std;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int mx, my;
int cnt = 0, num = 0;

void dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &pic){
    visited[i][j] = true;
    ++cnt;
    for(int n = 0; n < 4; ++n){
        int x = i + dx[n], y = j + dy[n];
        if(x < 0 || y < 0 || x >= mx || y >= my) continue;
        if(visited[x][y] || pic[x][y] != num) continue;
        dfs(x, y, visited, pic);
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    
    vector<int> answer(2, 0);
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    my = n; mx = m; 
    
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            if(!visited[i][j] && picture[i][j] != 0){
                ++answer[0];
                cnt = 0; num = picture[i][j];
                dfs(i, j, visited, picture);
                answer[1] = max(answer[1], cnt);
            }
            
    

    return answer;
}
