#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int visited[100][100];
int BFS(vector<vector<int>> picture, int m, int n, int x, int y){
    int Color = picture[x][y];
    int Size = 1;
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    visited[x][y] = true;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx>=0 && ny>=0 && nx<m && ny<n){
                if(picture[nx][ny] == Color && visited[nx][ny] == false){
                    visited[nx][ny] = true;
                    q.push(make_pair(nx,ny));
                    Size++;
                }
            }
        }
    }
    return Size++;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for(int i = 0; i<m;i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = false;
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(picture[i][j] != 0 && visited[i][j] == false){
                int Size = BFS(picture,m,n,i,j);
                if(Size > max_size_of_one_area) max_size_of_one_area = Size;
                number_of_area++;
            }
        }
    }




    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}