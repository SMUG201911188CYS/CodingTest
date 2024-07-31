#include <string>
#include <vector>
#include <stack>

using namespace std;

//우리의 표의 값이 되어줄 친구
//링크드 리스트!
class Node
{
public:
    int index;
    Node* prev;
    Node* next;

    //생성자
    Node(int _index, Node* _prev) : index(_index), prev(_prev), next(nullptr) {}
};

string solution(int n, int k, vector<string> cmd)
{

    // 링크드 리스트 이니셜라이징
    Node* head = new Node(0, nullptr);
    Node* prevNode = head;
    Node* select;

    for (int i = 1; i < n; ++i)
    {
        Node* countNode = new Node(i, prevNode);
        prevNode->next = countNode;
        prevNode = countNode;

        if (i == k)
            select = countNode;
    }

    stack<Node*> trashBin;

    //람다식을 사용하여 위로 이동
    auto moveSelectedNode = [](Node*& select, int count, bool isPrev)
        {
            for (int i = 0; i < count; ++i)
            {
                if (isPrev && select->prev != nullptr)
                {
                    //선택한 헤더를 전으로 이동
                    select = select->prev;
                }
                else if (!isPrev && select->next != nullptr)
                {
                    //선택한 헤더를 후로 이동
                    select = select->next;
                }
            }
        };

    //람다식을 사용하여 지우는 함수 만들기
    //[&]를 하용하여 외부 변수를 참조로 사용할 수 있음
    //[=]를 쓰면 모두 값으로, [&]를 사용하면 모두참조로 사용
    // [&select]를 사용해서 select 변수만 참조 가능 
    auto deleteNode = [&](Node*& select)
        {
            Node* prev = select->prev;
            Node* next = select->next;

            trashBin.push(select);

            select = (next != nullptr) ? next : prev;

            if (prev != nullptr) prev->next = next;
            if (next != nullptr) next->prev = prev;
        };

    //trashBin을 이용하여 되돌리는 람다식 제작
    auto recoverNode = [&]()
        {
            Node* targetNode = trashBin.top();
            trashBin.pop();

            Node* prev = targetNode->prev;
            Node* next = targetNode->next;

            if (prev != nullptr) prev->next = targetNode;
            if (next != nullptr) next->prev = targetNode;
        };

    //커맨드 실행
    for (const string& c : cmd)
    {
        switch (c[0])
        {
            int x;
        case 'U':
            x = stoi(c.substr(2));
            moveSelectedNode(select, x, true);
            break;
        case 'D':
            x = stoi(c.substr(2));
            moveSelectedNode(select, x, false);
            break;
        case 'C':
            deleteNode(select);
            break;
        case 'Z':
            recoverNode();
            break;
        default:
            break;
        }

    }

    //표 비교
    vector<char> result(n, 'O');
    while (!trashBin.empty())
    {
        Node* node = trashBin.top();
        trashBin.pop();
        //쓰레기통에 있는 행을 X로
        result[node->index] = 'X';
    }

    string resStr(result.begin(), result.end());
    return resStr;
}