#include <string>
#include <vector>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n, m;
bool visited[5][5];
vector<vector<int>> MAP;
int moves(int x1, int y1, int x2, int y2){
    if(visited[x1][y1]) return 0;
    int ret = 0;
    for(int i = 0 ; i < 4; i++){
        int nx = x1+dx[i];
        int ny = y1+dy[i];
        if(nx<0||nx>=n||ny<0||ny>=m||visited[nx][ny]||!MAP[nx][ny]) continue;
        visited[x1][y1] = 1;
        int val = moves(x2,y2,nx,ny)+1;
        visited[x1][y1] = 0;
        if(ret % 2 == 0 && val % 2 == 1) ret = val;
        else if(ret % 2 == 0 && val % 2 == 0) ret = max(ret,val);
        else if(ret % 2 == 1 && val % 2 == 1) ret = min(ret,val);
    }
    return ret;
}
int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    n = board.size();
    m = board[0].size();
    MAP = board;
    return moves(aloc[0],aloc[1], bloc[0],bloc[1]);
}