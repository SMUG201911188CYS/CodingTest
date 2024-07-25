#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//상하좌우
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

//게임판 사이즈
int x_size = 0;
int y_size = 0;

struct pos {
    int x;
    int y;

    pos(int x_, int y_) {
        x = x_;
        y = y_;
    }

    pos() {}

};

vector<int> check(vector<vector<int>>& board, pos player_pos);
void progress(vector<vector<int>>& board, pos a_pos, pos b_pos, int cnt, vector<pair<pos, pos>> route);
void move(vector<vector<int>>& board, vector<int>& v, pos a_pos, pos b_pos, int cnt, vector<pair<pos, pos>> route);

//이겼을 때 몇번 칸을 움직여서 이겼는지 체크하는 리스트
vector<int> a_win_cnt_list;
vector<int> b_win_cnt_list;

void print_route(vector<pair<pos, pos>> v, int cnt) {
    cout << " " << cnt << '\n';
    for (int i = 0; i < v.size(); i++) {
        auto t = v[i];
        cout << " a_pos : (" << t.first.x << ", " << t.first.y << " ) ";
        cout << " b_pos : (" << t.second.x << ", " << t.second.y << " ) \n";
    }
    cout << '\n';
}

//갈 곳이 있는지 확인
//(갈 수 있는 방향 벡터만 반환함)
vector<int> check(vector<vector<int>>& board, pos player_pos, pos enemy_pos) {

    //갈 수 있는 모든 경로 
    vector<int> v;

    for (int i = 0; i < 4; i++) {
        int tx = player_pos.x + dx[i];
        int ty = player_pos.y + dy[i];

        if (tx < 0 || tx >= x_size || ty < 0 || ty >= y_size) continue;

        //발판이 있음 
        if (board[ty][tx] == 1) {
            v.push_back(i);
        }

    }

    return v;
}

void move(vector<vector<int>>& board, vector<int>& v, pos a_pos, pos b_pos, int cnt, vector<pair<pos, pos>> route) {
    //이동할 수 있음
    pos player_pos;
    pos enemy_pos;
    if (cnt % 2 == 0) {
        player_pos.x = a_pos.x;
        player_pos.y = a_pos.y;
        enemy_pos = b_pos;
    }
    else {
        player_pos.x = b_pos.x;
        player_pos.y = b_pos.y;
        enemy_pos = a_pos;
    }

    //체크 
    vector<int> v_2;
    for (int i = 0; i < v.size(); i++) {
        int tx = player_pos.x + dx[v[i]];
        int ty = player_pos.y + dy[v[i]];


        bool flag = false;
        for (int j = 0; j < 4; j++) {
            int ttx = tx + dx[j];
            int tty = ty + dy[j];

            if (ttx < 0 || ttx >= x_size || tty < 0 || tty >= y_size) continue;
            if (board[tty][ttx] == 0) continue;
            if (tty == player_pos.y && ttx == player_pos.x) continue;

            flag = true;
        }



        if (flag == true) {
            //flag == true 면 막다른 곳이 아니고,
            //이 때 적이나 플레이어랑 위치가 같으면
            //무조건 질 수 있음. 가면 안됨
            if (enemy_pos.x == tx && enemy_pos.y == ty) {
                continue;
            }
            else {

                //아니면 가도 괜찮음 
            }

        }
        else {
            //flag == false 면 막다른 곳임.
            //막 다른 곳이나 적이나 플레이어랑 위치가 같으면
            //오히려 무조건 이길 수 있음. 가야함
            if (enemy_pos.x == tx && enemy_pos.y == ty) {

            }
            else {
                //아니면 안가는 게 좋음 
                continue;
            }



        }

        v_2.push_back(v[i]);
    }

    /*
    if(cnt%2==0)  cout << "a ("<< a_pos.x << " , " << a_pos.y << " )" <<  "가 실수하지 않을 경로 ";
    else  cout << "b ("<< b_pos.x << " , " << b_pos.y << " )" <<  "가 실수하지 않을 경로 / " << a_pos.x << ' ' << a_pos.y << " /";

    for(int i=0;i<v_2.size();i++){
       cout << v_2[i] << ' ';
    }
    cout << '\n';
     */

     //만약 v_2.size() == 0이면 그대로 v 사용
     //아니면 v 사용

    if (v_2.size() == 0) {

    }
    else {
        v = v_2;
    }

    //이동  
    for (int i = 0; i < v.size(); i++) {
        int tx = player_pos.x + dx[v[i]];
        int ty = player_pos.y + dy[v[i]];


        //발판이 사라짐
        board[player_pos.y][player_pos.x] = 0;


        if (cnt % 2 == 0) {

            //만약 b가 그 위치에 있었다면 
            if (b_pos.x == player_pos.x && b_pos.y == player_pos.y) {
                //a의 승리
                //cout << "a가 있던 곳에 b가 있었음. a의 승리\n";
                pos temp(tx, ty);
                pair<pos, pos> p = make_pair(temp, b_pos);
                route.push_back(p);
                //print_route(route,cnt+1);


                a_win_cnt_list.push_back(cnt + 1);
            }
            else {
                //아직 승패가 결정나지 않았으므로
                //다음 턴으로 이동

                progress(board, pos(tx, ty), b_pos, cnt + 1, route);
            }


        }
        else {
            //만약 a가 그 위치에 있었다면
            if (a_pos.x == player_pos.x && a_pos.y == player_pos.y) {
                //b의 승리
               //cout << "b가 있던 곳에 a가 있었음. b의 승리\n";
                pos temp(tx, ty);
                pair<pos, pos> p = make_pair(a_pos, temp);
                route.push_back(p);
                //print_route(route,cnt+1);

                b_win_cnt_list.push_back(cnt + 1);
            }
            else {
                progress(board, a_pos, pos(tx, ty), cnt + 1, route);
            }

        }


        //발판 복구
        board[player_pos.y][player_pos.x] = 1;
    }

}


//board[n][n] : 0 -> 발판이 없음
//board[n][n] : 1 -> 발판이 있음
void progress(vector<vector<int>>& board, pos a_pos, pos b_pos, int cnt, vector<pair<pos, pos>> route)
{

    //현재 판
    pair<pos, pos> p = make_pair(a_pos, b_pos);
    route.push_back(p);

    //cout << cnt << ' ';   
    //cnt가 홀수면 A이동, 짝수면 B이동
    if (cnt % 2 == 0) {

        //a가 이동할 수 있는 곳이 있는지 판정
        vector<int> v = check(board, a_pos, b_pos);
        //cout << v.size() << ' ';

        if (v.size())move(board, v, a_pos, b_pos, cnt, route);
        else {
            //a가 이동할 수 없음 - a의 패배
            //'현재 상태'에서 이동할 수 없는것
            //cout << "a가 막다른 길에 몰림.b의 승리\n";
            //print_route(route,cnt);
            b_win_cnt_list.push_back(cnt);
        }
    }
    else {
        //b가 이동할 수 있는 곳이 있는지 판정
        vector<int> v = check(board, b_pos, a_pos);
        //cout << v.size() << ' ';

        if (v.size())move(board, v, a_pos, b_pos, cnt, route);
        else {
            //b가 이동할 수 없음 - b의 패배
            //cout << "b가 막다른 길에 몰림.a의 승리\n";
            //print_route(route,cnt);
            a_win_cnt_list.push_back(cnt);
        }
    }

}




int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int answer = -1;
    pos a_pos(aloc[1], aloc[0]);
    pos b_pos(bloc[1], bloc[0]);
    x_size = board[0].size();
    y_size = board.size();

    //cout << x_size << ' ' << y_size;
    //a,b
    vector<pair<pos, pos>> route;

    progress(board, a_pos, b_pos, 0, route);

    int a_min = -1;
    int b_min = -1;
    /*
    if(a_win_cnt_list.size() >0){
        sort(a_win_cnt_list.begin(),a_win_cnt_list.end());
        //"최선의 플레이"에서 제일 적은 횟수
        answer = a_win_cnt_list[0];

    }else if(b_win_cnt_list.size()>0){
        sort(b_win_cnt_list.begin(),b_win_cnt_list.end());
        //"최선의 플레이"에서 제일 적은 횟수
        answer = b_win_cnt_list[0];
    }
    */

    sort(a_win_cnt_list.begin(), a_win_cnt_list.end());
    sort(b_win_cnt_list.begin(), b_win_cnt_list.end());
    if (a_win_cnt_list.size() > 0) {
        a_min = a_win_cnt_list[0];
    }

    if (b_win_cnt_list.size() > 0) {
        b_min = b_win_cnt_list[0];
    }

    if (a_min == -1 && b_min == -1) answer = 0;
    else if (a_min != -1 && b_min == -1) answer = a_min;
    else if (a_min == -1 && b_min != -1) answer = b_min;
    else if (a_min != -1 && b_min != -1) answer = min(a_min, b_min);

    return answer;
}

int main(int argc, char** argv)
{
    //예제 1
    /*
    vector<vector<int>> board {{1,1,1},{1,1,1},{1,1,1}};
    vector<int> aloc{1,0};
    vector<int> bloc{1,2};
    */

    //예제 2 
    /*
    vector<vector<int>> board {{1,1,1},{1,0,1},{1,1,1}};
    vector<int> aloc{1,0};
    vector<int> bloc{1,2};
    */

    //예제 3
    /*
    vector<vector<int>> board {{1,1,1,1,1}};
    vector<int> aloc{0,0};
    vector<int> bloc{0,4};
    */

    //예제 4
    /*
    vector<vector<int>> board {{1}};
    vector<int> aloc{0,0};
    vector<int> bloc{0,0};
    */

    //만든 예제 1
    /*
    vector<vector<int>> board {{1,1,1,1},{1,0,0,1},{1,0,0,1},{1,1,1,1}};
    vector<int> aloc{0,0};
    vector<int> bloc{3,3};
    */

    //만든 예제 2

    vector<vector<int>> board {{1, 1, 1, 1}, { 1,0,1,1 }, { 1,1,1,1 }, { 1,1,1,1 }};
    vector<int> aloc{1, 0};
    vector<int> bloc{1, 3};



    //반례
    //vector<vector<int>> board {{1,1,1,0},{1,1,0,1},{1,0,1,1},{0,1,1,1}};
    //vector<int> aloc{0,0};
    //vector<int> bloc{3,3};



    cout << solution(board, aloc, bloc);

    for (int i = 0; i < a_win_cnt_list.size(); i++)cout << a_win_cnt_list[i] << ' ';
    cout << '\n';
    for (int i = 0; i < b_win_cnt_list.size(); i++)cout << b_win_cnt_list[i] << ' ';

}