#include <vector>
#include <stack>
#include <memory.h>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    bool visited[100][100];
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    memset(visited, 0, sizeof(visited));
    
    stack<pair<int, int>> s;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j] && picture[i][j] != 0) {
                int cur_color = picture[i][j];
                s.push(make_pair(i, j));
                visited[i][j] = true;
                int area = 1;
                while(!s.empty()) {
                    pair<int, int> pos = s.top(); s.pop();
                    int x = pos.first;
                    int y = pos.second;
                    
                    for(int k = 0; k < 4; k++) {
                        int target_x = x + dx[k];
                        int target_y = y + dy[k];
                        if(target_x >= 0 && target_x < m &&
                            target_y >= 0 && target_y < n) {
                            if(!visited[target_x][target_y] &&
                                    picture[target_x][target_y] == cur_color) {
                                s.push(make_pair(target_x, target_y));
                                visited[target_x][target_y] = true;
                                area++;
                            }
                        }
                    }
                }
                
                answer[0]++;
                
                if(answer[1] < area) {
                    answer[1] = area;
                }
            }
        }
    }
    
    return answer;
}