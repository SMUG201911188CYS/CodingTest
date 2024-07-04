#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> dice_temp;
int index;
int cnt = 0;
vector<int> a[253];
vector<int> b[253];
vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
int win_count = 0;
vector<int> result;

void arrSum(vector<int> & sumList, int n, int check, int sum, bool isA)
{
    if(check == index)
    {
        //cout << "sum : " << sum << '\n';
        sumList.push_back(sum);
        return;
    }
    
    for(int i = 0; i < 6; i++)
    {
        if(isA)
        {
            sum += dice_temp[a[n][check]-1][i];
            //cout << "sum : " << sum << ", dice : "<< dice_temp[a[n][check]-1][i] << ", check : " << check << '\n';
            arrSum(sumList, n, check+1, sum, isA);
            sum -= dice_temp[a[n][check]-1][i];
        }
        else
        {
            sum += dice_temp[b[n][check]-1][i];
            //cout << "sum : " << sum << ", dice : "<< dice_temp[a[n][check]-1][i] << ", check : " << check << '\n';
            arrSum(sumList, n, check+1, sum, isA);
            sum -= dice_temp[b[n][check]-1][i];
        }
    }
}

void find_combination()
{
    vector<bool> comb(dice_temp.size(), false);
        
    for(int i = 0; i < index; i++)
        comb[i] = true;
    do {
        for (int i = 0; i < dice_temp.size(); ++i) {
            if(comb[i])
            {
                a[cnt].push_back(arr[i]);
            }
            else
            {
                b[cnt].push_back(arr[i]);
            }
        }
        cnt++;
    } while (prev_permutation(comb.begin(), comb.end()));
}

void cal_sum(vector<int> a_list, vector<int> b_list, vector<int> n)
{
    int ap = 0;
    int bp = 0;
    int a_win = 0;
    
    while(ap < a_list.size() && bp < b_list.size())
    {
        if(a_list[ap] > b_list[bp])
        {
            bp++;
        }
        else
        {
            a_win += bp;
            ap++;
        }
    }
    cout << "ap = " << ap << ", bp = " << bp << ", win = " << a_win << '\n';
    if(bp == b_list.size())
    {
        a_win += bp*(a_list.size() - ap);
         // bp가 b_list의 size와 같은 경우, 현재 ap의 위치부터 끝 까지 bp에 대해 이겼다는 경우의 수이기에
    }
    cout << a_win << '\n';
    
    if(a_win > win_count)
    {
        win_count = a_win;
        result = n;
    }
}

vector<int> solution(vector<vector<int>> dice) {
    dice_temp = dice;
    vector<int> answer;
    index = dice.size() / 2;
    
    find_combination();
    
    for(int i = 0; i < cnt; i++)
    {
        cout << "A : ";
        for(int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "B : ";
        for(int j = 0; j < b[i].size(); j++)
        {
            cout << b[i][j] << " ";
        }
        cout << '\n';
    
        /*for(int i = 0; i < dice.size(); i++)
        {
            for(int j = 0; j < dice[i].size(); j++)
                cout << dice[i][j] << " ";
                cout << '\n';
        }
        
        for(int j = 0; j < 6; j++){
            cout << "A :" << dice[a[i][0]-1][j];
            cout << " B : " << dice[b[i][0]-1][j];
            cout << '\n';
        }*/
        
        vector<int> a_list;
        vector<int> b_list;
        
        arrSum(a_list, i, 0, 0, true);
        arrSum(b_list, i, 0, 0, false);
            
        sort(a_list.begin(), a_list.end());
        sort(b_list.begin(), b_list.end());
            
        cal_sum(a_list, b_list, a[i]);
        for(int n = 0; n < a_list.size(); n++)
        {
            cout << a_list[n] << " ";
        }
        cout << '\n';
            
        for(int n = 0; n < b_list.size(); n++)
        {
            cout << b_list[n] << " ";
        }
        cout << '\n';
        
    }
    answer = result;
    
    return answer;
}