#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <algorithm>


using namespace std;

vector<string> _info;
vector<string> _query;
vector<string> qVec[100001];
vector<int> answer;
unordered_map<string, vector<int>> info_map;
int result;
    

/*void set_info()
{
    for(int i = 0; i < _info.size(); i++)
    {
        string temp = _info[i];
        stringstream slice(temp);
        string a, b, c, d, e;
        slice >> a >> b >> c >> d >> e;
        
        applicant[i].push_back(a);
        applicant[i].push_back(b);
        applicant[i].push_back(c);
        applicant[i].push_back(d);
        applicant[i].push_back(e);
    }
    
    for(int i = 0; i < language.size(); i++)
    {
        cout << language[i] << " " << job[i] << " " << career[i] << " " << food[i] << " " << score[i] << '\n';
    }
}

void set_query()
{
    for(int i = 0; i < _query.size(); i++)
    {
        string temp = _query[i];
        stringstream slice(temp);
        string a, b, c, d, e, f, g, h;
        slice >> a >> b >> c >> d >> e >> f >> g >> h;
        
        qVec[i].push_back(a);
        qVec[i].push_back(c);
        qVec[i].push_back(e);
        qVec[i].push_back(g);
        qVec[i].push_back(h);
    }
    
    for(int i = 0; i < _query.size(); i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << qVec[i][j] << " ";
        }
        cout << '\n';
    }
}

void find_result(int check, vector<string> q, vector<string> i, int index)
{
    
    if(check == 4)
    {
        if(stoi(q[check]) <= stoi(i[check]))
        {
            //cout << "q score : " << q[check] << ", i score : " << i[check] << '\n';
            result++;
            return;
        }
        else{
            return;
        }
    }
    
    //cout << "q : " << q[check] << ", i : " << i[check] << '\n';
    
    if(q[check] == "-")
        find_result(check + 1, q, i, index);
    
    if(q[check] == i[check])
        find_result(check + 1, q, i, index);
}


*/

void set_init(vector<vector<string>> temp)
{
    string a, b, c, d;
    
    for(int i = 0; i < 2; i++)
    {
        a = temp[0][i];
        for(int j = 0; j < 2; j++)
        {
            b = temp[1][j];
            for(int k = 0; k < 2; k++)
            {
                c = temp[2][k];
                for(int q = 0; q < 2; q++)
                {
                    d = temp[3][q];
                    
                    info_map[a + b + c + d].push_back(stoi(temp[4][0]));
                }
            }
        }
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    _info = info;
    _query = query;
    
    vector<vector<string>> temp(5, vector<string>(2, "-"));
    
    for(int i = 0; i < info.size(); i++)
    {
        istringstream slice(info[i]);
        slice >> temp[0][0] >> temp[1][0] >> temp[2][0] >> temp[3][0] >> temp[4][0];
        set_init(temp);
    }
    
    
    for(auto iter = info_map.begin(); iter != info_map.end(); iter++)
    {
        sort(iter->second.begin(), iter->second.end());
    }
    
    /*for(auto iter = info_map.begin(); iter != info_map.end(); iter++)
    {
        for(auto i = iter->second.begin(); i != iter->second.end(); i++)
        {
            cout << *i << " ";
        }
        cout << '\n';
    }*/
    
    for(int i = 0; i < query.size(); i++)
    {
        string score;
        istringstream slice(query[i]);
        
        slice >> temp[0][0] >> temp[4][0] >> temp[1][0] >> temp[4][0] >> temp[2][0] >> temp[4][0] >> temp[3][0] >> score;
        vector<int> check_query = info_map[temp[0][0] + temp[1][0] + temp[2][0] + temp[3][0]];
        
        //cout << temp[0][0] + temp[1][0] + temp[2][0] + temp[3][0] << '\n';
        if(check_query.empty())
        {
            answer.push_back(0);
            continue;
        }
        int result = lower_bound(check_query.begin(), check_query.end(), stoi(score)) - check_query.begin();
        answer.push_back(check_query.size() - result);
        //cout << result << '\n';
    }
    
    
    return answer;
}