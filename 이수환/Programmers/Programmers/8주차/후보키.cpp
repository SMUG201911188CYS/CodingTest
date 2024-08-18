#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string, bool> umap;

bool Uniqueness(vector<vector<string>>& relation, vector<int>& colVec){

    int rowSize = relation.size();
    // 문자열로 만들기
    vector<string> data(relation.size());
    for(int i = 0; i < rowSize; i++){
        for(int col : colVec){
            data[i] += relation[i][col];
        }   
    }

    // 비교
    for(int i = 0; i < rowSize-1; i++){
        for(int j = i+1; j < rowSize; j++){
            //cout << data[i] << ", " << data[j] << '\n';
            if(data[i] == data[j]){
                return false;
            }
        }
    }
    return true;
}

string VecToString(vector<int>& vec){
    string reStr = "";
    for(int num : vec){
        reStr += std::to_string(num);
    }
    //cout << "restr : " <<  reStr << '\n';
    return reStr;
}

bool Minimality(vector<vector<string>>& relation, vector<int> colVec){
    string colStr = VecToString(colVec);
    for(auto val : umap){
        string keyName = val.first;
        if(colStr.find(keyName) != string::npos){
            return false;
        }
    }
    
    cout << "colStr : " << colStr << '\n';
    for(auto val : umap){
        string keyName = val.first;
        cout << "keyName : " << keyName << '\n';
        int count = 0;
        for(char keyC : keyName){
            for(char colC : colStr){
                if(keyC == colC){
                    cout << "same " << '\n';
                    count++;
                    continue;
                }
            } 
        }
        if(count == keyName.length()){
            cout << "return false" << '\n';
            return false;
        }
    }
    
            cout << "return true" << '\n';
    return true;
}


int solution(vector<vector<string>> relation) {
    int answer = 0;
    int colSize = relation[0].size();
    
    queue<vector<int>> q;
    // 처음 탐색 값 넣기
    for(int i = 0; i < colSize; i++){
        q.push(vector<int>(1, i));
    }
    
    //bfs
    while(!q.empty()){
        vector<int> colVec = q.front();
        q.pop();
        
        if(colVec.size() > relation.size()) continue;
        
        // if 유일성 만족
        if(Uniqueness(relation, colVec)){
            // if 최소성 만족 
            if(Minimality(relation, colVec)){
                // answer count
                umap.insert({VecToString(colVec), true});
                answer++;
            }        
        }
        else{
            // queue에 넣기
            int tmp = colVec.back();
            for(int i = tmp+1; i < colSize; i++){
                vector<int> tmpVec(colVec);
                tmpVec.push_back(i);
                q.push(tmpVec);
            }
        }
    }
    
    for(auto val : umap){
        string keyName = val.first;
        cout << keyName << '\n';
    }
    return answer;
}