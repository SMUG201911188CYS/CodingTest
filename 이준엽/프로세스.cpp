#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int solution(vector<int> p, int loc) {
    int answer = 0;
    int start = 0;
    int j = 0;
    vector<int> sv = p;
    vector<int> av;
    
    sort(sv.begin(),sv.end(),greater<int>());
    //for(auto i : sv) cout << i << endl;
    for(int i = 0; i<sv.size();i++){
        j = start;
        while(true){
            if(p[j]==sv[i]){
                av.push_back(j);
                cout <<  "av.push_back(" << j  << ") " ;
                j++;
                
                start = j%(p.size());
                cout << j <<" and start is " << start << endl;
                //cout <<  "av.push_back(" << j  << ")" << endl;
                break;
            }else{
                j = ++j%p.size();
                
                cout << "didn`t find " << sv[i] << " and j is " << j  << endl; 
                
            }
        }
    }
    for(auto i : sv) cout << i << endl;
    cout << endl;
    for(auto i : av) cout << i << endl;
    cout << endl;
    
   
    for(int i = 0; i<av.size();i++){
        if(loc == av[i]){
            answer = i+1;
        }
    }

    return answer;
}