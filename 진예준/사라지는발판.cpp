#include <string>
#include <vector>

using namespace std;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };
int width;
int height;

int dfs(vector<vector<int>>& board, vector<int> cur, vector<int> opposite)
{
    int curx = cur[0];
    int cury = cur[1];
    int max_result = 0;
    int min_result = (1 << 30);
    if (board[curx][cury] == 0)
    {
        return 0;
    }

    bool win = false;
    for (int d = 0; d < 4; d++)
    {
        int nx = curx + dx[d];
        int ny = cury + dy[d];

        if ((0 <= nx) && (nx < height) && (0 <= ny) && (ny < width) && (board[nx][ny] == 1))
        {
            board[curx][cury] = 0;
            int step = dfs(board, opposite, { nx, ny }) + 1;
            board[curx][cury] = 1;

            if (step % 2 == 1)
            {
                win = true;
                min_result = min_result < step ? min_result : step;
            }
            else
            {
                max_result = max_result < step ? step : max_result;
            }
        }
    }
    return win ? min_result : max_result;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc)
{
    int answer = 0;
    height = board.size();
    width = board[0].size();

    answer = dfs(board, aloc, bloc);
    return answer;
}