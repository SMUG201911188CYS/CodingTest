#include <string>
#include <vector>
#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;
    vector<vector<int>> procession; //행렬

    //행렬 만들기
    int count = 1;
    for (int i = 0; i < rows; i++)
    {
        vector<int> line;
        for (int j = 0; j < columns; j++)
        {
            line.push_back(count++);
        }
        procession.push_back(line);
    }

    //행렬 옮기기
    for (auto query : queries)
    {

        //computin index
        for (int i = 0; i < 4; i++) { query[i] = query[i] - 1; }

        int temp = procession[query[0]][query[3]];
        int min_number = temp;

        for (int i = query[3] - 1; i >= query[1]; i--)
        {
            min_number = min(min_number, procession[query[0]][i]);
            procession[query[0]][i + 1] = procession[query[0]][i];
        }

        for (int i = query[0] + 1; i <= query[2]; i++)
        {
            min_number = min(min_number, procession[i][query[1]]);
            procession[i - 1][query[1]] = procession[i][query[1]];
        }

        for (int i = query[1] + 1; i <= query[3]; i++)
        {
            min_number = min(min_number, procession[query[2]][i]);
            procession[query[2]][i - 1] = procession[query[2]][i];
        }

        for (int i = query[2] - 1; i >= query[0]; i--)
        {
            min_number = min(min_number, procession[i][query[3]]);
            procession[i + 1][query[3]] = procession[i][query[3]];
        }

        procession[query[0] + 1][query[3]] = temp;
        min_number = min(min_number, temp);

        answer.push_back(min_number);
    }
    return answer;
}
