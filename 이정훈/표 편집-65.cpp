#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int cursor;
int tail_cursor;
stack<int> closed_cursor;
int table_size;

string answer = "";

inline void up(int idx) {
    for (int i = 0; i < idx; i++) {
        cursor -= 1;

        if (answer[cursor] == 'X')
            i -= 1;
    }
}

inline void down(int idx) {
    for (int i = 0; i < idx; i++) {
        cursor += 1;

        if (answer[cursor] == 'X')
            i -= 1;
    }
}

void close() {
    closed_cursor.push(cursor);
    answer[cursor] = 'X';

    if (cursor == tail_cursor) {
        up(1);
        tail_cursor = cursor;

        return;
    }

    down(1);
}

void undo() {
    int _closed_cursor = closed_cursor.top();
    answer[_closed_cursor] = 'O';

    if (_closed_cursor > tail_cursor)
        tail_cursor = _closed_cursor;

    closed_cursor.pop();
}

void execute_cmd(string& cmd) {
    if (cmd == "C") {
        close();
    }
    else if (cmd == "Z") {
        undo();
    }
    else {
        string cmd1 = cmd.substr(0, 1);
        string cmd2 = cmd.substr(2);

        if (cmd1 == "U") {
            up(stoi(cmd2));
        }
        else {
            down(stoi(cmd2));
        }
    }
}

string solution(int n, int k, vector<string> v_cmd) {
    for (int i = 0; i < n; i++)
        answer.append("O");

    cursor = k;
    table_size = n;
    tail_cursor = n - 1;

    for (string cmd : v_cmd) {
        execute_cmd(cmd);
    }

    return answer;
}