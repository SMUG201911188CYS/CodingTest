#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<string, pair<string, int>> a, pair<string, pair<string, int>> b)
{
    if(a.first == b.first)
    {
        if(a.second.first == b.second.first)
            return a.second.second < b.second.second;
        return stoi(a.second.first) < stoi(b.second.first);
    }
    else
        return a.first < b.first;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    string head = "", number = "";
    int idx = 0;
    bool h = false, n = false;
    vector<pair<string, pair<string, int>>> v;
    
    for(string s : files)
    {
        pair<string, int> p;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(h == false)
            {
                if(s[i] >= '0' && s[i] <= '9')
                {
                    h = true;
                    number += s[i];
                }    
                else
                    head += tolower(s[i]);
            }
            else if(h && n == false)
            {
                if(s[i] >= '0' && s[i] <= '9')
                    number += s[i];
                else
                    break;
            }       
        }
        p = make_pair(number, idx++);
        v.push_back(make_pair(head, p));
        head = number = "";
        h = n = false;
    }
    
    stable_sort(v.begin(), v.end(), cmp);
    
    for(auto i : v)
        answer.push_back(files[i.second.second]);
    
    return answer;
}
