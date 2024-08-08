#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int present;
    Node * next;
    Node * prev;
    
    Node(int present, Node * next, Node * prev) : present(present), next(next), prev(prev) {}
};

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'O');
    
    vector<string> name = {"무지", "콘", "어피치", "제이지", "프로도", "네오", "튜브", "라이언"};
    stack<Node*> dp;
    
    vector<Node*> list(n);
    
    Node * current;
    Node * temp = new Node(0, NULL, NULL);
    
    
    for(int i = 1; i < n; i++)
    {
        temp->next = new Node(i, NULL, temp);
        temp = temp->next;
        if(i == k)
            current = temp;
    }
    
    for(int i = 0 ; i < cmd.size(); i++)
    {
        //cout << "current : " << current->present << ", " << name[current->present] <<'\n';
        string temp = cmd[i];
        
        if(temp[0] == 'D')
        {
            for(int k = 0; k < stoi(temp.substr(2, temp.size() - 1)); k++)
                current = current->next;
        }
        else if(temp[0] == 'U')
        {
            for(int k = 0; k < stoi(temp.substr(2, temp.size() - 1)); k++)
                current = current->prev;
        }
        else if(temp[0] == 'C')
        {
            dp.push(current);
            
            if(current->prev != NULL)
                current->prev->next = current->next;
            if(current->next != NULL)
                current->next->prev = current->prev;
            if(current->next == NULL)
                current = current->prev;
            else
                current = current->next;
        }
        else
        {
            Node * popTemp = dp.top();
            dp.pop();
            
            if(popTemp->prev != NULL)
                popTemp->prev->next = popTemp;
            if(popTemp->next != NULL)
                popTemp->next->prev = popTemp;
        }
    }
    
    while(!dp.empty())
    {
        answer[dp.top()->present] = 'X';
        dp.pop();
    }
    
    return answer;
}