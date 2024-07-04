#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    vector<int> graph[1000001];
    int check_start_point[1000001] = {0,};
    int length = 0;
    int start_point = 0;
    int temp = 0;
    
    for(int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        
        if(edges[i][0] < edges[i][1])
        {
            if(length < edges[i][1])
                length = edges[i][1];
        }
        else
        {
            if(length < edges[i][0])
                length = edges[i][0];
        }
        
        check_start_point[edges[i][1]] = 1;
    }
    
    /*for(int i = 0; i < edges.size(); i++)
    {
        for(int j = 0; j < edges[i].size(); j++)
        {
            cout << edges[i] << " ";
        }
        cout << '\n'
    }*/
    
    for(int i= 1; i <= length; i++)
    {
        cout << i << " ";
        for(int j = 0; j < graph[i].size(); j++)
            cout << graph[i][j] << " ";
        cout << "\n";
    }
    
    for(int i= 1; i < length; i++)
    {
        if(graph[start_point].size() < graph[i].size() && check_start_point[i] == 0) // 시작점 찾기
            start_point = i;
    }
    
    answer.push_back(start_point);
    //cout << start_point;
    
    int rod = 0;
    int donut = 0;
    int eight = 0;
    
    for(int i = 0; i < graph[start_point].size(); i++)
    {
        int start = graph[start_point][i];
        int present = start;
        
        //cout << start << '\n';
        while(1)
        {
            //cout << present << '\n';
            if(graph[present].size() == 0) // 막대인지?
            {
                rod++;
                break;
            }
            if(graph[present].size() == 2) // 팔자인지?
            {
                eight++;
                break;
            }
            
            present = graph[present][0];
            
            if(present == start) // 도넛인지?
            {
                donut++;
                break;
            }
        }
    }
    
    //cout << donut << " " << rod << " " << eight;
    answer.push_back(donut);
    answer.push_back(rod);
    answer.push_back(eight);
    
    return answer;
}