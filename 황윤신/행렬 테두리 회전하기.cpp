#include <string>
#include <vector>
#include <deque>
#include <algorithm>


using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int arr[101][101];
    int idx = 1;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            arr[i][j] = idx;
            idx++;
        }
    }



    for (int i = 0; i < queries.size(); i++) {
        int min_n = 10002;

        int y1 = queries[i][0];
        int x1 = queries[i][1];
        int y2 = queries[i][2];
        int x2 = queries[i][3];


        deque<int> q;

        for (int i = x1; i <= x2; i++) {
            q.push_back(arr[y1][i]);
        }

        for (int i = y1 + 1; i <= y2; i++) {
            q.push_back(arr[i][x2]);
        }

        for (int i = x2 - 1; i >= x1; i--) {
            q.push_back(arr[y2][i]);
        }

        for (int i = y2 - 1; i >= y1 + 1; i--) {

            q.push_back(arr[i][x1]);

        }

        int temp = q.back();
        q.pop_back();
        q.push_front(temp);

        for (int i = x1; i <= x2; i++) {
            arr[y1][i] = q.front();
            min_n = min(arr[y1][i], min_n);
            q.pop_front();
        }

        for (int i = y1 + 1; i <= y2; i++) {
            arr[i][x2] = q.front();
            min_n = min(arr[i][x2], min_n);
            q.pop_front();
        }

        for (int i = x2 - 1; i >= x1; i--) {
            arr[y2][i] = q.front();
            min_n = min(arr[y2][i], min_n);
            q.pop_front();
        }

        for (int i = y2 - 1; i >= y1 + 1; i--) {
            arr[i][x1] = q.front();
            min_n = min(arr[i][x1], min_n);
            q.pop_front();
        }

        answer.push_back(min_n);
    }



    return answer;
}