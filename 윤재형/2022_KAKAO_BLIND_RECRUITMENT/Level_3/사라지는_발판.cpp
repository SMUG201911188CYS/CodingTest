#include <string>
#include <vector>

using namespace std;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
vector<vector<bool>> vis(5, vector<bool>(5, false));
vector<vector<int>> b;

int dfs(int curx, int cury, int nextx, int nexty){
    if(vis[curx][cury]) return 0;
    int ret = 0;
    for(int n = 0; n < 4; ++n){
        int nx = curx + dx[n], ny = cury + dy[n];
        if(nx < 0 || ny < 0 || nx >= b.size() || ny >= b[0].size()) continue;
        if(vis[nx][ny] || !b[nx][ny]) continue;
        vis[curx][cury] = true;
        int cnt = dfs(nextx, nexty, nx, ny) + 1;
        vis[curx][cury] = false;
        if(ret%2==0 && cnt%2==1) ret = cnt;
        else if(ret%2==0 && cnt%2==0) ret = max(ret, cnt);
        else if(ret%2==1 && cnt%2==1) ret = min(ret, cnt);
    }
    return ret;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    b = board;
    
    return dfs(aloc[0], aloc[1], bloc[0], bloc[1]);
}
