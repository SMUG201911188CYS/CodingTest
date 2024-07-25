#include <string>
#include <vector>
#include <iostream>
#include <queue>

#define X1 1
#define Y1 0
#define X2 3
#define Y2 2

int moveX[] = { 1, 0, -1, 0 };
int moveY[] = { 0, 1, 0, -1 };


using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    vector<vector<int>> map(rows, vector<int>(columns));

    int num = 1;
    // 맵 초기화
    for (auto& vec : map) {
        for (auto& val : vec) {
            val = num++;
        }
    }

    // queries 확인
    for (auto& query : queries) {
        for (auto& val : query) {
            val--;
        }

        int curX = query[X1];
        int curY = query[Y1];

        // 기준값
        int pivotX[] = { 1, 3, 3, 1 };
        int pivotY[] = { 0, 0, 2, 2 };

        int min = rows * columns + 1;

        int curVal = 0;
        // 시계방향으로 회전
        for (int i = 0; i < 4; i++) {
            curX = query[pivotX[i]];
            curY = query[pivotY[i]];

            // 시작점 설정
            if (i == 0)
                curVal = map[curY][curX];

            // 끝까지 이동하면 넘어가기
            while (query[X1] <= curX && curX <= query[X2] &&
                query[Y1] <= curY && curY <= query[Y2]) {

                // 좌표 이동
                curX += moveX[i];
                curY += moveY[i];

                // 넘어가면 멈추기
                if (curX < query[X1] || curX > query[X2] ||
                    curY < query[Y1] || curY > query[Y2]) {
                    break;
                }

                // 값 이동
                int tmp = map[curY][curX];
                map[curY][curX] = curVal;
                curVal = tmp;

                // 최소값
                if (curVal < min)
                    min = curVal;

            }
        }

        answer.push_back(min);

    }


    return answer;
}