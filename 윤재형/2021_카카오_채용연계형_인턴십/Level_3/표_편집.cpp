#include <string>
#include <vector>

using namespace std;

struct Node{
    int val = -1;
    int prev = -1;
    int next = -1;
};

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    struct Node node[n];
    vector<Node> deleted;
    
    for(int i = 0; i < n; i++){
        answer += "O";
        node[i].val = i;
        if(i > 0)
            node[i].prev = i - 1;
        if(i < n - 1)
            node[i].next = i + 1;
    }
    
    for(auto c : cmd)
        switch(c[0]){
            case 'U':{
                int move = stoi(c.substr(2));
                while(move--)
                    k = node[k].prev;
                break;
            }
            case 'D':{
                int move = stoi(c.substr(2));
                while(move--)
                    k = node[k].next;
                break;
            }
            case 'C':{
                int next = node[k].next;
                int prev = node[k].prev;
                deleted.push_back(node[k]);
                if(prev > -1)
                    node[prev].next = next;
                if(next > -1)
                    node[next].prev = prev;
                k = next > -1 ? next : prev;
                break;
            }
            case 'Z':{
                Node tmp = deleted.back();
                int val = tmp.val;
                int next = tmp.next;
                int prev = tmp.prev;
                if(prev > -1)
                    node[prev].next = val;
                if(next > -1)
                    node[next].prev = val;
                deleted.pop_back();
                break;
            }
        }
    
    while(!deleted.empty()){
        int top = deleted.back().val;
        deleted.pop_back();
        answer[top] = 'X';
    }
    
    return answer;
}
