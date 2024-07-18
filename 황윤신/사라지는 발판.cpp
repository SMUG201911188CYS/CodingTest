#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//�����¿�
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

//������ ������
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

//�̰��� �� ��� ĭ�� �������� �̰���� üũ�ϴ� ����Ʈ
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

//�� ���� �ִ��� Ȯ��
//(�� �� �ִ� ���� ���͸� ��ȯ��)
vector<int> check(vector<vector<int>>& board, pos player_pos, pos enemy_pos) {

    //�� �� �ִ� ��� ��� 
    vector<int> v;

    for (int i = 0; i < 4; i++) {
        int tx = player_pos.x + dx[i];
        int ty = player_pos.y + dy[i];

        if (tx < 0 || tx >= x_size || ty < 0 || ty >= y_size) continue;

        //������ ���� 
        if (board[ty][tx] == 1) {
            v.push_back(i);
        }

    }

    return v;
}

void move(vector<vector<int>>& board, vector<int>& v, pos a_pos, pos b_pos, int cnt, vector<pair<pos, pos>> route) {
    //�̵��� �� ����
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

    //üũ 
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
            //flag == true �� ���ٸ� ���� �ƴϰ�,
            //�� �� ���̳� �÷��̾�� ��ġ�� ������
            //������ �� �� ����. ���� �ȵ�
            if (enemy_pos.x == tx && enemy_pos.y == ty) {
                continue;
            }
            else {

                //�ƴϸ� ���� ������ 
            }

        }
        else {
            //flag == false �� ���ٸ� ����.
            //�� �ٸ� ���̳� ���̳� �÷��̾�� ��ġ�� ������
            //������ ������ �̱� �� ����. ������
            if (enemy_pos.x == tx && enemy_pos.y == ty) {

            }
            else {
                //�ƴϸ� �Ȱ��� �� ���� 
                continue;
            }



        }

        v_2.push_back(v[i]);
    }

    /*
    if(cnt%2==0)  cout << "a ("<< a_pos.x << " , " << a_pos.y << " )" <<  "�� �Ǽ����� ���� ��� ";
    else  cout << "b ("<< b_pos.x << " , " << b_pos.y << " )" <<  "�� �Ǽ����� ���� ��� / " << a_pos.x << ' ' << a_pos.y << " /";

    for(int i=0;i<v_2.size();i++){
       cout << v_2[i] << ' ';
    }
    cout << '\n';
     */

     //���� v_2.size() == 0�̸� �״�� v ���
     //�ƴϸ� v ���

    if (v_2.size() == 0) {

    }
    else {
        v = v_2;
    }

    //�̵�  
    for (int i = 0; i < v.size(); i++) {
        int tx = player_pos.x + dx[v[i]];
        int ty = player_pos.y + dy[v[i]];


        //������ �����
        board[player_pos.y][player_pos.x] = 0;


        if (cnt % 2 == 0) {

            //���� b�� �� ��ġ�� �־��ٸ� 
            if (b_pos.x == player_pos.x && b_pos.y == player_pos.y) {
                //a�� �¸�
                //cout << "a�� �ִ� ���� b�� �־���. a�� �¸�\n";
                pos temp(tx, ty);
                pair<pos, pos> p = make_pair(temp, b_pos);
                route.push_back(p);
                //print_route(route,cnt+1);


                a_win_cnt_list.push_back(cnt + 1);
            }
            else {
                //���� ���а� �������� �ʾ����Ƿ�
                //���� ������ �̵�

                progress(board, pos(tx, ty), b_pos, cnt + 1, route);
            }


        }
        else {
            //���� a�� �� ��ġ�� �־��ٸ�
            if (a_pos.x == player_pos.x && a_pos.y == player_pos.y) {
                //b�� �¸�
               //cout << "b�� �ִ� ���� a�� �־���. b�� �¸�\n";
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


        //���� ����
        board[player_pos.y][player_pos.x] = 1;
    }

}


//board[n][n] : 0 -> ������ ����
//board[n][n] : 1 -> ������ ����
void progress(vector<vector<int>>& board, pos a_pos, pos b_pos, int cnt, vector<pair<pos, pos>> route)
{

    //���� ��
    pair<pos, pos> p = make_pair(a_pos, b_pos);
    route.push_back(p);

    //cout << cnt << ' ';   
    //cnt�� Ȧ���� A�̵�, ¦���� B�̵�
    if (cnt % 2 == 0) {

        //a�� �̵��� �� �ִ� ���� �ִ��� ����
        vector<int> v = check(board, a_pos, b_pos);
        //cout << v.size() << ' ';

        if (v.size())move(board, v, a_pos, b_pos, cnt, route);
        else {
            //a�� �̵��� �� ���� - a�� �й�
            //'���� ����'���� �̵��� �� ���°�
            //cout << "a�� ���ٸ� �濡 ����.b�� �¸�\n";
            //print_route(route,cnt);
            b_win_cnt_list.push_back(cnt);
        }
    }
    else {
        //b�� �̵��� �� �ִ� ���� �ִ��� ����
        vector<int> v = check(board, b_pos, a_pos);
        //cout << v.size() << ' ';

        if (v.size())move(board, v, a_pos, b_pos, cnt, route);
        else {
            //b�� �̵��� �� ���� - b�� �й�
            //cout << "b�� ���ٸ� �濡 ����.a�� �¸�\n";
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
        //"�ּ��� �÷���"���� ���� ���� Ƚ��
        answer = a_win_cnt_list[0];

    }else if(b_win_cnt_list.size()>0){
        sort(b_win_cnt_list.begin(),b_win_cnt_list.end());
        //"�ּ��� �÷���"���� ���� ���� Ƚ��
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
    //���� 1
    /*
    vector<vector<int>> board {{1,1,1},{1,1,1},{1,1,1}};
    vector<int> aloc{1,0};
    vector<int> bloc{1,2};
    */

    //���� 2 
    /*
    vector<vector<int>> board {{1,1,1},{1,0,1},{1,1,1}};
    vector<int> aloc{1,0};
    vector<int> bloc{1,2};
    */

    //���� 3
    /*
    vector<vector<int>> board {{1,1,1,1,1}};
    vector<int> aloc{0,0};
    vector<int> bloc{0,4};
    */

    //���� 4
    /*
    vector<vector<int>> board {{1}};
    vector<int> aloc{0,0};
    vector<int> bloc{0,0};
    */

    //���� ���� 1
    /*
    vector<vector<int>> board {{1,1,1,1},{1,0,0,1},{1,0,0,1},{1,1,1,1}};
    vector<int> aloc{0,0};
    vector<int> bloc{3,3};
    */

    //���� ���� 2

    vector<vector<int>> board {{1, 1, 1, 1}, { 1,0,1,1 }, { 1,1,1,1 }, { 1,1,1,1 }};
    vector<int> aloc{1, 0};
    vector<int> bloc{1, 3};



    //�ݷ�
    //vector<vector<int>> board {{1,1,1,0},{1,1,0,1},{1,0,1,1},{0,1,1,1}};
    //vector<int> aloc{0,0};
    //vector<int> bloc{3,3};



    cout << solution(board, aloc, bloc);

    for (int i = 0; i < a_win_cnt_list.size(); i++)cout << a_win_cnt_list[i] << ' ';
    cout << '\n';
    for (int i = 0; i < b_win_cnt_list.size(); i++)cout << b_win_cnt_list[i] << ' ';

}