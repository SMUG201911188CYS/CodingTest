#include <string>
#include <vector>
#include <iostream>

using namespace std;

int size_X = 0;
int size_Y = 0;

int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};

int dfs(bool turn, vector<vector<int>> board, vector<pair<int, int>> location)
{
    int current_X = location[turn].first;
    int current_Y = location[turn].second;
    //cout << current_X << " " << current_Y << " " << turn <<'\n';
    
    if(board[current_X][current_Y] == 0)
    {
        return 0;
    }
    
    int result = 0;
    
    //cout << "Current : " << current_X << ", " << current_Y << '\n';
    for(int i = 0; i < 4; i++)
    {
        int next_X = current_X + x[i];
        int next_Y = current_Y + y[i];
        //cout << "Next : " << next_X << ", " << next_Y << '\n';   

        if(next_X < 0 || next_X >= size_X || next_Y < 0 || next_Y >= size_Y)
        {
            //cout << "Out Range" << '\n';
            continue;
        }
        if(board[next_X][next_Y] == 0)
        {
            //cout << "Can't Move" << '\n';
            continue;
        }
        
        board[current_X][current_Y] = 0;
        location[turn].first = next_X; location[turn].second = next_Y;
        int depth = dfs(!turn, board, location) + 1;
        location[turn].first = current_X; location[turn].second = current_Y;
        board[current_X][current_Y] = 1;
        
        if(depth % 2 == 1 && result % 2 == 0)
            result = depth;
        else if(depth % 2 == 0 && result % 2 == 0)
            result = max(result, depth);
        else if(depth % 2 == 1 && result % 2 == 1)
            result = min(result, depth);
    }
    
    return result;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int answer = -1;
    
    size_X = board.size();
    size_Y = board[0].size();
    
    vector<pair<int, int>> location;
    
    location.push_back(make_pair(aloc[0], aloc[1]));
    location.push_back(make_pair(bloc[0], bloc[1]));
    
    answer = dfs(false, board, location);
    
    return answer;
}