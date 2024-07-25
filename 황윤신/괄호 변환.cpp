#include <string>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

string go(string ipt) {
    cout << ipt << '\n';

    //1. �Է��� �� ���ڿ��� ���, �� ���ڿ��� ��ȯ
    if (ipt == "") return ipt;

    //2. ���ڿ� w�� �� "�������� ��ȣ ���ڿ�" u, v�� �и�
    string u = "";
    string v = "";
    stack<char> s;

    //ó�� �� ��ȣ�� ���� ('('���� ')'������ ��� ����)
    int num = 0;
    int num_2 = 0;

    for (int i = 0; i < ipt.length(); i++) {
        char c = ipt[i];
        u += c;

        if (ipt[0] == c) {
            s.push(c);
            num++;
        }
        else {
            if (c == ')' && !s.empty()) s.pop();
            num_2++;
        }

        if (num == num_2) {
            v = ipt.substr(i + 1);
            break;
        }
    }

    //3. ���ڿ� u�� "�ùٸ� ��ȣ ���ڿ�" �̶�� ���ڿ� v�� ���� 1�ܰ���� �ٽ� ����
    if (s.empty()) {
        // 3-1. ������ ��� ���ڿ��� u�� �̾� ���� �� ��ȯ 
        return u + go(v);

    }
    else {
        //4. ���ڿ� u�� "�ùٸ� ��ȣ ���ڿ�"�� �ƴ϶�� �Ʒ� ������ ���� 
           // 4-1. �� ���ڿ��� ù ��° ���ڷ� '('�� ���� 
           // 4-2. ���ڿ� v�� ���� 1�ܰ���� ��������� ������ ��� ���ڿ��� �̾� ����
           // 4-3. ')'�� �ٽ� ����
        string str = "(" + go(v) + ")";

        // 4-4. u�� ù ��°�� ������ ���ڸ� �����ϰ�, ������ ���ڿ��� ��ȣ ������ ����� �ڿ� ����
        string str_2 = u.substr(1, u.length() - 2);
        for (int i = 0; i < str_2.length(); i++) {
            if (str_2[i] == '(') str_2[i] = ')';
            else str_2[i] = '(';
        }

        // 4-5. ������ ���ڿ��� ��ȯ
        return str + str_2;


    }
}


string solution(string p) {
    stack<char> s;
    for (char ch : p) {
        if (ch == '(')s.push(ch);
        else if (!s.empty() && ch == ')') s.pop();
    }


    //���� p�� �̹� "�ùٸ� ��ȣ ���ڿ�"�̶�� �״�� return
    if (s.empty()) return p;
    else return go(p);

}


int main(int argc, char** argv) {
    string p = "()))((()";
    cout << solution(p);
}