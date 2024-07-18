#include <string>
#include <vector>

using namespace std;

inline int swap(vector<vector<int>>& matrix, int& x, int& y, int val, int& min) {
    if (val < min)
        min = val;

    int temp = matrix[y][x];
    matrix[y][x] = val;
    return temp;
}

int rotate(vector<vector<int>>& matrix, vector<int>& query) {
    int x1 = query[1], x2 = query[3];
    int y1 = query[0], y2 = query[2];
    int temp = matrix[y1][x1];
    int min = 10001;

    for (int x = x1 + 1; x <= x2; x++)
        temp = swap(matrix, x, y1, temp, min);

    for (int y = y1 + 1; y <= y2; y++)
        temp = swap(matrix, x2, y, temp, min);

    for (int x = x2 - 1; x >= x1; x--)
        temp = swap(matrix, x, y2, temp, min);

    for (int y = y2 - 1; y >= y1; y--)
        temp = swap(matrix, x1, y, temp, min);

    return min;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    vector<vector<int>> matrix(rows + 1, vector<int>(columns + 1));

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            matrix[i][j] = (i - 1) * columns + j;
        }
    }

    for (vector<int> query : queries) {
        answer.push_back(rotate(matrix, query));
    }

    return answer;
}