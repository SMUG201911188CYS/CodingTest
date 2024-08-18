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
    // �� �ʱ�ȭ
    for (auto& vec : map) {
        for (auto& val : vec) {
            val = num++;
        }
    }

    // queries Ȯ��
    for (auto& query : queries) {
        for (auto& val : query) {
            val--;
        }

        int curX = query[X1];
        int curY = query[Y1];

        // ���ذ�
        int pivotX[] = { 1, 3, 3, 1 };
        int pivotY[] = { 0, 0, 2, 2 };

        int min = rows * columns + 1;

        int curVal = 0;
        // �ð�������� ȸ��
        for (int i = 0; i < 4; i++) {
            curX = query[pivotX[i]];
            curY = query[pivotY[i]];

            // ������ ����
            if (i == 0)
                curVal = map[curY][curX];

            // ������ �̵��ϸ� �Ѿ��
            while (query[X1] <= curX && curX <= query[X2] &&
                query[Y1] <= curY && curY <= query[Y2]) {

                // ��ǥ �̵�
                curX += moveX[i];
                curY += moveY[i];

                // �Ѿ�� ���߱�
                if (curX < query[X1] || curX > query[X2] ||
                    curY < query[Y1] || curY > query[Y2]) {
                    break;
                }

                // �� �̵�
                int tmp = map[curY][curX];
                map[curY][curX] = curVal;
                curVal = tmp;

                // �ּҰ�
                if (curVal < min)
                    min = curVal;

            }
        }

        answer.push_back(min);

    }


    return answer;
}