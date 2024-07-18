#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<int> solution(int rows, int columns, vector<vector<int>> queries) 
{
    vector<int> answer;
    int Num = 1;
    int MAP[100][100];
    
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns; j++) MAP[i][j] = Num++;

    for(auto q : queries){
        int x = q[0]; x--;
        int y = q[1]; y--;
        int xx = q[2]; xx--;
        int yy = q[3]; yy--;

        int Min_Num;
        int Temp = MAP[x][y];
        Min_Num = Temp;
        for(int i = x; i < xx; i++)
        {
            Min_Num = min(Min_Num, MAP[i][y]);
            MAP[i][y] = MAP[i + 1][y];
        }
        for(int i = y; i < yy; i++)
        {
            Min_Num = min(Min_Num, MAP[xx][i]);
            MAP[xx][i] = MAP[xx][i + 1];
        }
        for (int i = xx; i > x; i--)
        {
            Min_Num = min(Min_Num, MAP[i][yy]);
            MAP[i][yy] = MAP[i - 1][yy];
        }
        for (int i = yy; i > y; i--)
        {
            Min_Num = min(Min_Num, MAP[x][i]);
            MAP[x][i] = MAP[x][i - 1];
        }
        MAP[x][y + 1] = Temp;
        
        answer.push_back(Min_Num);
    }
    
    return answer;
}

