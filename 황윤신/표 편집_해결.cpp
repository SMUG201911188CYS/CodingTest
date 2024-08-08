#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    bool isEnabled;
    Node* Llink;
    Node* Rlink;
    Node(int data_) {
        data = data_;
        Llink = NULL;
        Rlink = NULL;
    }
};
Node* headNode;
Node* selectNode;
stack<Node*> deleteLogStack;

string ret(1000001, 'O');

void Init_List(int n, int pos) {
    headNode = new Node(-1);
    Node* preNode = headNode;
    for (int i = 0; i < n; i++) {
        Node* newNode = new Node(i);
        preNode->Rlink = newNode;
        newNode->Llink = preNode;
        preNode = newNode;
        if (i == pos) selectNode = newNode;
    }
}


void Delete_Node() {
    ret[selectNode->data] = 'X';
    deleteLogStack.push(selectNode);
    if (selectNode->Rlink == NULL) {
        selectNode->Llink->Rlink = selectNode->Rlink;
        selectNode = selectNode->Llink;
    }
    else {
        selectNode->Llink->Rlink = selectNode->Rlink;
        selectNode->Rlink->Llink = selectNode->Llink;
        selectNode = selectNode->Rlink;
    }
}

void Recover_Node() {
    if (deleteLogStack.size() <= 0)return;
    Node* recoveryNode = deleteLogStack.top();
    deleteLogStack.pop();
    ret[recoveryNode->data] = 'O';

    recoveryNode->Llink->Rlink = recoveryNode;
    if (recoveryNode->Rlink != NULL) recoveryNode->Rlink->Llink = recoveryNode;
}

void Move_Pos(int targetNum) {
    int moveNum = 0;
    if (targetNum < 0) {
        while (selectNode->Llink != NULL && moveNum != targetNum) {
            moveNum--;
            selectNode = selectNode->Llink;
        }
    }
    else if (targetNum > 0) {
        while (selectNode->Rlink != NULL && moveNum != targetNum) {
            moveNum++;
            selectNode = selectNode->Rlink;
        }
    }
}

string solution(int n, int k, vector<string> cmd) {
    int pos = k;
    Init_List(n, pos);

    for (int i = 0; i < cmd.size(); i++) {
        char s_1 = cmd[i][0];
        int delta = 0;
        if (cmd[i].size() >= 2) delta = stoi(cmd[i].substr(2));

        if (s_1 == 'C') {
            Delete_Node();
        }
        else if (s_1 == 'Z') {
            Recover_Node();
        }
        else if (s_1 == 'U') {
            Move_Pos(-delta);
        }
        else if (s_1 == 'D') {
            Move_Pos(delta);
        }

    }

    return ret.substr(0, n);
}
