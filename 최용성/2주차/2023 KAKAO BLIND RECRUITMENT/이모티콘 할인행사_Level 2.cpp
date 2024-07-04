#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> _users;
vector<int> _emoticons;
vector<int> discount_price[7];
int discount[4] = {40, 30, 20 ,10};
int emoticon_length;
int user_length;
vector<int> answer(2, 0);

void find_result(vector<pair<int, int>> list, int cnt)
{
    if(cnt == emoticon_length)
    {
        int total_price = 0;
        int total_plus = 0;
        
        for(int i = 0; i < user_length; i++)
        {   
            int temp = 0;
            for(int j = 0; j < emoticon_length; j++)
            {
                if(list[j].first >= _users[i][0])
                {
                    //cout << list[j].first << ", " << _users[i][0] << '\n';
                    temp += list[j].second;
                }
            }
            
            if(temp >= _users[i][1])
            {
                total_plus++;
            }
            else
            {
                total_price += temp;
            }
        }
        
        //cout << total_price << ", " << total_plus << '\n';
        if(answer[0] < total_plus)
        {
            answer[0] = total_plus;
            answer[1] = total_price;
            //cout << "1. tplus : " << total_plus << ", tprice : " << total_price << '\n';
        }
        else if (answer[0] == total_plus && answer[1] < total_price)
        {
            //cout << "2. tprice : " << total_price << '\n';
            answer[1] = total_price;
        }
        
        return;
    }
    
    for(int i = 0; i < 4; i++)
    {
        list[cnt].second = _emoticons[cnt] - (_emoticons[cnt] * discount[i] / 100);
        list[cnt].first = discount[i];
        find_result(list, cnt+1);
    }
}


vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<pair<int, int>> list(7, {0, 0});
    
    _users = users;
    _emoticons = emoticons;
    
    user_length = users.size();
    emoticon_length = emoticons.size();
    
    find_result(list, 0);
    /*for(int i = 0; i < emoticon_length; i++)
    {
        cout << i+1 << "번째 할인 가격 : ";
        for(int j = 0; j < 4; j++)
        {
            cout << discount_price[i][j] << " ";
        }
        cout << '\n';
    }*/
    
    
    return answer;
}