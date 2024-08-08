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
        isEnabled = true;
        Llink = NULL;
        Rlink = NULL;
    }
};
Node* headNode;
Node* selectNode;
stack<Node*> deleteLogStack;

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

string Traversal_List(int n) {
    string str = "";
    for (int i = 0; i < n; i++)str += 'X';
    Node* preNode = headNode;
    while (preNode->Rlink != NULL) {
        Node* newNode = preNode->Rlink;
        // cout << newNode->data << "-> ";
        if (newNode->isEnabled) str[newNode->data] = 'O';
        preNode = newNode;
    }
    return str;
}

void Delete_Node() {
    selectNode->isEnabled = false;
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
    recoveryNode->isEnabled = true;
    recoveryNode->Rlink = recoveryNode->Llink->Rlink;
    recoveryNode->Llink->Rlink = recoveryNode;
    if (recoveryNode->Rlink != NULL) recoveryNode->Rlink->Llink = recoveryNode;
}

void Move_Pos(int targetNum) {
    int moveNum = 0;
    if (targetNum < 0) {
        while (selectNode->Llink != NULL && moveNum != targetNum) {
            if (selectNode->Llink->isEnabled == true) moveNum--;
            selectNode = selectNode->Llink;
        }
    }
    else if (targetNum > 0) {
        while (selectNode->Rlink != NULL && moveNum != targetNum) {
            if (selectNode->Rlink->isEnabled == true) moveNum++;
            selectNode = selectNode->Rlink;
        }
    }
}

string solution(int n, int k, vector<string> cmd) {
    int pos = k;
    Init_List(n, pos);

    for (int i = 0; i < cmd.size(); i++) {
        stringstream ss(cmd[i]);
        string s_1 = "", s_2 = "";
        ss >> s_1 >> s_2;

        if (s_2 == "") {
            if (s_1 == "C") {
                Delete_Node();
            }
            else if (s_1 == "Z") {
                Recover_Node();
            }
        }
        else {
            int delta = stoi(s_2);
            if (s_1 == "U") {
                Move_Pos(-delta);
            }
            else if (s_1 == "D") {
                Move_Pos(delta);
            }
        }
    }
    return Traversal_List(n);
}
