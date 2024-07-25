#include <string>
#include <vector>

using namespace std;

bool checkOl(string p)
{
    int openParCount = 0; //'('
    int closeParCount = 0; //')'
    for (int i = 0; i < p.length(); i++)
    {
        if (p[i] == '(') openParCount++;
        if (p[i] == ')') closeParCount++;

        if (closeParCount > openParCount) return false;
    }
    return true;

}

string changing(string u)
{
    string temp_u = "";
    temp_u += "(";

    for (int i = 1; i < u.length() - 1; i++)
    {
        if (u[i] == '(') temp_u += ")";
        else temp_u += "(";
    }
    temp_u += ")";

    return temp_u;
}

string Parenthesis(string p)
{
    string answer = "";
    if (p == "") return "";
    if (checkOl(p)) return p;

    string u = "";
    string v = "";

    int len = p.length();
    int left = 0, right = 0;
    for (int i = 0; i < len; i++)
    {
        if (p[i] == '(') left++;
        else if (p[i] == ')') right++;

        if (left == right) {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }
    if (checkOl(u))
    {
        answer = u + Parenthesis(v);
        return answer;
    }

    else
    {
        answer = "(";
        answer = answer + Parenthesis(v);
        answer = answer + ')';
        u.erase(0, 1);
        u.erase(u.length() - 1, 1);
        for (int i = 0; i < u.length(); i++)
        {
            if (u[i] == '(') answer = answer + ')';
            else if (u[i] == ')') answer = answer + '(';
        }
        return answer;
    }

}

string solution(string p) {
    return Parenthesis(p);
}