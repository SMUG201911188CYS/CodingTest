#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

//�����¿�
int dx[4];
int dy[4];

//����
int x_size;
int y_size;

//�湮 ����
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

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    //���� ���� �ʱ�ȭ (�̰� ���ϸ� Ʋ������)
    x_size = 0;
    y_size = 0;

    memset(visit, 0, sizeof(visit));
    //�����¿�
    dx[0] = 0;
    dx[1] = 0;
    dx[2] = -1;
    dx[3] = 1;

    dy[0] = -1;
    dy[1] = 1;
    dy[2] = 0;
    dy[3] = 0;



    //������ ����
    int number_of_area = 0;

    //���� ū ����
    int max_size_of_one_area = 0;



    //m : ���� / n : ����
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