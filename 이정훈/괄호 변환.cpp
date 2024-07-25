#include <string>
#include <vector>
#include <stack>

using namespace std;

bool correction(string p) {
    vector<char> s;

    for (auto char_p : p) {
        s.push_back(char_p);

        int ssize = s.size();
        if (ssize > 1) {
            if (s[ssize - 2] == '(' && s[ssize - 1] == ')') {
                s.pop_back(); s.pop_back();
            }
        }
    }

    if (s.size() == 0)
        return true;

    return false;
}

string separation(string p) {
    string u, v;
    int open = 0, closed = 0;

    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(')
            open++;
        else if (p[i] == ')')
            closed++;

        if (open == closed)
            break;
    }

    for (int i = 0; i < open + closed; i++)
        u += p[i];
    for (int i = open + closed; i < p.size(); i++)
        v += p[i];

    if (!v.empty())
        v = separation(v);

    if (!correction(u)) {
        string new_u = '(' + v + ')';

        for (int i = 1; i < u.size() - 1; i++) {
            if (u[i] == '(')
                new_u += ')';
            else
                new_u += '(';
        }

        u = new_u;

        return u;
    }

    return u + v;
}

string solution(string p) {
    return separation(p);
}