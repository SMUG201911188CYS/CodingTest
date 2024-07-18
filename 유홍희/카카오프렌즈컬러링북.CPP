#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// BFS 탐색을 위한 방향 배열
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

// 방문 여부를 체크할 배열
bool Visit[100][100];

// BFS 함수
int BFS(int a, int b, int m, int n, vector<vector<int>> &MAP) {
    int Color = MAP[a][b]; // 현재 영역의 색상
    int Size = 1; // 현재 영역의 크기
    queue<pair<int, int>> Q;
    Q.push({a, b});
    Visit[a][b] = true;

    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 유효한 좌표인지 검사
            if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                // 같은 색상이고 아직 방문하지 않았다면
                if (MAP[nx][ny] == Color && !Visit[nx][ny]) {
                    Visit[nx][ny] = true;
                    Q.push({nx, ny});
                    Size++;
                }
            }
        }
    }

    return Size;
}

// 솔루션 함수
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    // 방문 배열 초기화
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            Visit[i][j] = false;
        }
    }

    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] != 0 && !Visit[i][j]) {
                int Size = BFS(i, j, m, n, picture);
                if (Size > max_size_of_one_area) max_size_of_one_area = Size;
                number_of_area++;
            }
        }
    }

    return {number_of_area, max_size_of_one_area};
}

int main() {
    vector<vector<int>> picture = {
        {1, 1, 1, 0},
        {1, 2, 2, 0},
        {1, 0, 0, 1},
        {0, 0, 0, 1}
    };

    vector<int> result = solution(4, 4, picture);
    cout << "Number of areas: " << result[0] << endl;
    cout << "Max size of one area: " << result[1] << endl;

    return 0;
}