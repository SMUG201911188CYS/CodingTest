#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int p_sum[1002][1002] = {0, };
    
    for(auto it : skill)
    {
        int val;
        
        if(it[0] == 1)
            val = -1 * it[5];
        else
            val = it[5];
        
        p_sum[it[1]][it[2]] += val;
        p_sum[it[3] + 1][it[4] + 1] += val;
        p_sum[it[1]][it[4] + 1] += -val;
        p_sum[it[3] + 1][it[2]] += -val;
        
        // (x1, y1) ~ (x2, y2), value == n;
        // (x1, y1) += n
        // (x2 + 1, y2 + 1) += n
        // (x1, y2 + 1) -= n
        // (x2 + 1, y1) -= n
        
    }
    /*for(int i = 0; i < board.size() + 1; i++)
    {
        for(int j = 0; j < board[0].size() + 1; j++)
        {
            cout << std::setw(4) << p_sum[i][j];
        }
        
        cout <<'\n';
    }
    
    cout << '\n';
    */
    
    for(int i = 0; i < board[0].size() + 1; i++)
    {
        for(int j = 0; j < board.size(); j++)
        {
            p_sum[j + 1][i] += p_sum[j][i];
        }
    }
    
    for(int i = 0; i < board.size() + 1; i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            p_sum[i][j + 1] += p_sum[i][j];
        }
    }
    
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[i].size(); j++)
        {
            board[i][j] += p_sum[i][j];
            
            if(board[i][j] > 0)
                answer++;
        }
    }
    
    /*for(int i = 0; i < board.size() + 1; i++)
    {
        for(int j = 0; j < board[0].size() + 1; j++)
        {
            cout << std::setw(4) << p_sum[i][j];
        }
        
        cout <<'\n';
    }
    
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            cout << std::setw(4) << board[i][j];
        }
        
        cout <<'\n';
    }*/
    
        
    return answer;
}