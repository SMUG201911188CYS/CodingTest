#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> files)
{
    struct FileName {
        string head;
        int num;
        string origin;
    };

    auto compare = [](const FileName& d1, const FileName& d2) 
        {
        if (d1.head != d2.head) return d1.head < d2.head;
        else if (d1.num != d2.num) return d1.num < d2.num;
        return false;
        };

    auto divide = [](string s) -> FileName 
        {
        string head, num, temp;
        FileName filename;

        for (int i = 0; i < s.length(); i++) 
        {
            if (!isdigit(s[i]) && num.empty()) temp += s[i];
            else 
            {
                if (head.empty()) 
                {
                    head = temp;
                    temp.clear();
                    num += s[i];
                }
                else num += s[i];
            }
        }

        filename.head = head;
        filename.num = stoi(num);
        filename.origin = s;
        return filename;
        };

    vector<FileName> v;

    for (string file : files)
    {
        v.push_back(divide(file));
    }

    for (int i = 0; i < v.size(); i++)
    {
        transform(v[i].head.begin(), v[i].head.end(), v[i].head.begin(), ::tolower);
    }

    stable_sort(v.begin(), v.end(), compare);

    vector<string> answer;
    for (int i = 0; i < v.size(); i++)
    {
        answer.push_back(v[i].origin);
    }
    return answer;
}
