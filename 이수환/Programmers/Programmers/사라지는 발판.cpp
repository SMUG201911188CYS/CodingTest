#include <string>
#include <vector>
#include <iostream>

#define PlayerA 0
#define PlayerB 1

using namespace std;

int moveX[] = { 1, 0, -1, 0 };
int moveY[] = { 0, -1, 0, 1 };

vector<vector<int>> map;
pair<int, int> playerPos[2];

int dfs(bool isPlayerA) {
    int playerNum = PlayerA;
    if (!isPlayerA) playerNum = PlayerB;

    int curX = playerPos[playerNum].first;
    int curY = playerPos[playerNum].second;

    if (map[curY][curX] == 0) return 0;

    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int nextX = curX + moveX[i];
        int nextY = curY + moveY[i];

        if (nextX < 0 || nextX >= map[0].size() || nextY < 0 || nextY >= map.size() ||
            map[nextY][nextX] == 0) continue;


        map[curY][curX] = 0;
        playerPos[playerNum].first = nextX;
        playerPos[playerNum].second = nextY;


        int val = dfs(!isPlayerA) + 1;


        map[curY][curX] = 1;
        playerPos[playerNum].first = curX;
        playerPos[playerNum].second = curY;


        // 플레이어 A를 기준으로 이동 수가 짝수면 패배, 홀수면 승리

         // 1. 현재 저장된 턴은 패배인데 새로 계산된 턴은 승리인 경우
        if (ret % 2 == 0 && val % 2 == 1) ret = val; // 바로 갱신
        // 2. 현재 저장된 턴과 새로 계산된 턴이 모두 패배인 경우
        else if (ret % 2 == 0 && val % 2 == 0) ret = max(ret, val); // 최대한 늦게 지는걸 선택
        // 3. 현재 저장된 턴과 새로 계산된 턴이 모두 승리인 경우
        else if (ret % 2 == 1 && val % 2 == 1) ret = min(ret, val); // 최대한 빨리 이기는걸 선택

    }

    return ret;
}


int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int answer = -1;

    map = board;
    playerPos[PlayerA].first = aloc[1];
    playerPos[PlayerA].second = aloc[0];

    playerPos[PlayerB].first = bloc[1];
    playerPos[PlayerB].second = bloc[0];

    cout << dfs(true) << '\n';
    answer = dfs(true);

    return answer;
}