#include <string>
#include <vector>

using namespace std;

int Min(int a, int b){return a < b ? a : b;}

vector<int> solution(int rows, int columns, vector<vector<int>> q) {
    vector<int> answer;
    int MAP[110][110];
    int n = 1;
    for(int i = 0 ; i < rows;i++){
        for(int j = 0; j < columns; j++){
            MAP[i][j] = n++;
        }
    }
    for(int i = 0; i < q.size(); i++){
        int x1 = q[i][0]-1;
        int y1 = q[i][1]-1;
        int x2 = q[i][2]-1;
        int y2 = q[i][3]-1;
        int x = x1;
        int y = y1;
        int tmp = MAP[x][y];
        int min = MAP[x][y];
        for(int i = x1; i < x2; i++){
            MAP[i][y1] = MAP[i+1][y1];
            min = Min(MAP[i][y1],min);
        }
        for(int i = y1; i < y2; i++){
            MAP[x2][i] = MAP[x2][i+1];
            min = Min(MAP[x2][i],min);
        }
        for(int i = x2; i > x1; i--){
            MAP[i][y2] = MAP[i-1][y2];
            min = Min(MAP[i][y2],min);
        }
        for(int i = y2; i > y1; i--){
            MAP[x1][i] = MAP[x1][i-1];
            min = Min(MAP[x1][i],min);
        }
        MAP[x][y+1] = tmp;
        
        answer.push_back(min);
    }
        
    return answer;
}