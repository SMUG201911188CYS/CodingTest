#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

//상하좌우
int dx[4];
int dy[4];

//범위
int x_size;
int y_size;

//방문 여부
bool visit[102][102];

int go(int x, int y, int& element, vector<vector<int>>& picture) {

    int ret = 1;
    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];

        //if(0 > tx || tx >= x_size || 0 > ty || ty >= y_size ) continue;

        if (0 <= ty && 0 <= tx && ty < y_size && tx < x_size) {
            if (visit[ty][tx] == false && picture[ty][tx] == element) {
                visit[ty][tx] = true;
                ret += go(tx, ty, element, picture);
            }
        }


    }

    return ret;

}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    //전역 변수 초기화 (이거 안하면 틀림ㅋㅋ)
    x_size = 0;
    y_size = 0;

    memset(visit, 0, sizeof(visit));
    //상하좌우
    dx[0] = 0;
    dx[1] = 0;
    dx[2] = -1;
    dx[3] = 1;

    dy[0] = -1;
    dy[1] = 1;
    dy[2] = 0;
    dy[3] = 0;



    //영역의 개수
    int number_of_area = 0;

    //가장 큰 영역
    int max_size_of_one_area = 0;



    //m : 세로 / n : 가로
    y_size = m; x_size = n;


    for (int i = 0; i < y_size; i++) {
        for (int j = 0; j < x_size; j++) {
            if (visit[i][j] == false && picture[i][j] != 0) {
                visit[i][j] = true;
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, go(j, i, picture[i][j], picture));
            }
        }
    }


    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}