#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

#define elem int

using namespace std;

typedef struct Node{
    int num;
    // 활성화 여부
    bool bIsActive;
    // 테이블 위 노드
    struct Node* up;
    // 테이블 아래 노드
    struct Node* down;
    struct Node* linkDown;
}Node;

// 현재 가리키는 노드
struct Node* cursorNode;

// 테이블의 시작 노드
struct Node* root;

// 초기 시작 노드
struct Node* start;

stack<struct Node*> deleteNodeStack;

void InitNode(Node* node, int num){
    node->num = num;
    node->bIsActive = true;
    node->up = nullptr;
    node->down = nullptr;
    node->linkDown = nullptr;
}

void CmdUp(int num){
    for(int i = 0; i < num; i++){
        //if(cursorNode->up != nullptr)
            cursorNode = cursorNode->up;
    }
}

void CmdDown(int num){
    for(int i = 0; i < num; i++){
        //if(cursorNode->down != nullptr)
            cursorNode = cursorNode->down;
    }
}

void CmdDelete(){
    Node* deleteNode = cursorNode;
    
    if(deleteNode->up == nullptr){
    // 제일 위 제거
        cursorNode = cursorNode->down;
        cursorNode->up = nullptr;
        root = cursorNode;
    }else if(deleteNode->down == nullptr){
    // 제일 아래 제거    
        cursorNode = cursorNode->up;
        cursorNode->down = nullptr;
    }
    else{
        cursorNode->up->down = cursorNode->down;
        cursorNode->down->up = cursorNode->up;
        cursorNode = cursorNode->down;
    }
    
    deleteNode->bIsActive = false;
    deleteNodeStack.push(deleteNode);
}

void CmdRollback(){
    Node* rollbackNode = deleteNodeStack.top();
    deleteNodeStack.pop();
    rollbackNode->bIsActive = true;
    
    if(rollbackNode->up != nullptr){
        rollbackNode->up->down = rollbackNode;
    }
    if(rollbackNode->down != nullptr){
        rollbackNode->down->up = rollbackNode;
    }
}

void CmdInput(string& input){
    
    char inputCmd = input[0];
    int num = 0;
    if(input.length()  > 2){
        num = stoi(input.substr(2));
    }
    switch(input[0]){
        case 'U':
            CmdUp(num);
            break;
        case 'D':
            CmdDown(num);
            break;
        case 'C':
            CmdDelete();
            break;
        case 'Z':
            CmdRollback();
            break;
        default:
            break;
    }
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    
    Node* newNode = new Node();
    InitNode(newNode, 0);
    root = newNode;
    
    Node* preNode = newNode;
    cursorNode = newNode;
    start = newNode;
    for(int i = 1; i < n; i++){
        Node* newNode = new Node();
        InitNode(newNode, i);
        preNode->down = newNode;
        preNode->linkDown = newNode;
        newNode->up = preNode;
        preNode = newNode;
        
        if(i == k){
            cursorNode = newNode;
        }
    }
    
    
    int cmdIndex = 0;
    for(auto input : cmd){
        CmdInput(input);
    }
    
    for(auto curNode = start; curNode != nullptr; curNode = curNode->linkDown){
        if(curNode->bIsActive)
            answer.append("O");
        else
            answer.append("X");
    }
    
    return answer;
}