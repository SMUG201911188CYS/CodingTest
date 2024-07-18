#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> moveX = { 1, 0, -1, 0 };
vector<int> moveY = { 0, -1, 0, 1 };


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    // m이 y, n이 x
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    vector<bool> vec(n, false);
    vector<vector<bool>> visit(m, vec);


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int count = 0;
            if (visit[i][j] == false && picture[i][j] != 0)
            {
                stack<pair<int, int>> s;
                s.push(pair(j, i));
                while (!s.empty()) {
                    int curX = s.top().first;
                    int curY = s.top().second;
                    s.pop();
                    visit[curY][curX] = true;
                    count++;

                    for (int i = 0; i < 4; i++) {
                        int newX = curX + moveX[i];
                        int newY = curY + moveY[i];

                        if (newX >= 0 && newX < n && newY >= 0 && newY < m
                            && visit[newY][newX] == false && picture[curY][curX] == picture[newY][newX]) {
                            visit[newY][newX] = true;
                            s.push(pair(newX, newY));
                        }
                    }


                }

                if (count > 0) {
                    number_of_area++;
                }

                if (count > max_size_of_one_area) {
                    max_size_of_one_area = count;
                }

            }
        }
    }

    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}