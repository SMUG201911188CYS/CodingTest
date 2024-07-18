#include <string>
#include <vector>
#include <iostream>

using namespace std;

int compare_min(int a, int b)
{
    if(a > b)
        return b;
    else
        return a;
}

vector<vector<int>> CreateVector(int rows, int columns)
{
    vector<vector<int>> vec(columns, vector<int>(rows, 0));
    int temp = 1;
    
    for(int i = 1; i <= columns; i++)
    {
        for(int j = 1; j <= rows; j++)
        {
            vec[i - 1][j - 1] = (i-1) * columns + j;
        }
    }
    return vec;
}

void PrintVector(int rows, int columns, vector<vector<int>> vec)
{
    for(int i = 0; i < columns; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            cout.width(3);
            cout << std::right << vec[i][j] << " ";
        }
            cout << '\n';
    }
    cout <<'\n';
}

int RotateVector(int rows, int columns, vector<vector<int>> & vec, vector<int> query)
{
    pair<int, int> start = make_pair(query[0]-1, query[1]-1);
    pair<int, int> end = make_pair(query[2]-1, query[3]-1);
    
    int x1 = start.first;
    int x2 = end.first;
    int y1 = start.second;
    int y2 = end.second;
    int temp_x[4];
    int temp_y[4];
    
    bool x_done = false;
    bool y_done = false;

    int min[2];
    int result = 0;
    
    temp_y[2] = vec[start.first][start.second];
    temp_y[3] = vec[end.first][end.second];
    temp_x[2] = vec[start.first][end.second];
    temp_x[3] = vec[end.first][start.second];

    min[0] = compare_min(temp_x[2], temp_x[3]);
    min[1] = compare_min(temp_y[2], temp_y[3]);
    result = compare_min(min[0],min[1]);
    
    while(!x_done || !y_done)
    {
        min[0] = compare_min(temp_x[2], temp_x[3]);
        min[1] = compare_min(temp_y[2], temp_y[3]);
        result = compare_min(result,min[0]);
        result = compare_min(result,min[1]);
        
        if(!x_done)
        {
            if(y1 < end.second)
            {
                y1 += 1;
                y2 -= 1;
                
                temp_y[0] = vec[start.first][y1];
                temp_y[1] = vec[end.first][y2];
                
                vec[start.first][y1] = temp_y[2];
                vec[end.first][y2] = temp_y[3];

                temp_y[2] = temp_y[0];
                temp_y[3] = temp_y[1];
                
            }
            else if(y1 == end.second)
            {
                vec[start.first + 1][end.second] = temp_y[2];
                vec[end.first - 1][start.second] = temp_y[3];
                x_done = true;
            }
        }
        
        if(!y_done)
        {
            if(x1 < end.first)
            {
                x1 += 1;
                x2 -= 1;
                
                temp_x[0] = vec[x1][end.second];
                temp_x[1] = vec[x2][start.second];
                
                vec[x1][end.second] = temp_x[2];
                vec[x2][start.second] = temp_x[3];

                temp_x[2] = temp_x[0];
                temp_x[3] = temp_x[1];
            }
            else if(x1 == end.first)
            {
                y_done = true;
            }
        }
        
    }

    return result;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> vec;
    
    vec = CreateVector(rows, columns);
    //PrintVector(rows, columns, vec);
    for(int i = 0; i < queries.size(); i++)
    {
        PrintVector(rows, columns, vec);
        
        vector<int> temp = queries[i];
        
        answer.push_back(RotateVector(rows, columns, vec, queries[i]));
        PrintVector(rows, columns, vec);
        cout << answer[i];
    }
    
    return answer;
}

int main()
{
    vector<string> data;
    vector<vector<int>> queries(1, vector<int>(4, 0));

    queries[0][0] = 2;
    queries[0][1] = 2;
    queries[0][2] = 5;
    queries[0][3] = 3;
    
    solution(6, 6, queries);

    //cout << temp;
    return 0;
}