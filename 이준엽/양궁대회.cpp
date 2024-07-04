#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> make_binary(int num){
    vector<int> b;
    b.push_back(num/1024);
    num %=1024;
    
    b.push_back(num/512);
    num %=512;
    

    b.push_back(num/256);
    num %=256;
  
    
    b.push_back(num/128);
    num %=128;

    b.push_back(num/64);
    num %=64;
  
    b.push_back(num/32);
    num %=32;
  
    b.push_back(num/16);
    num %=16;
  
    b.push_back(num/8);
    num %=8;
   
    b.push_back(num/4);
    num %=4;
 
    b.push_back(num/2);
    num %=2;
  
    b.push_back(num);

    return b;
    
}
vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<int> apeach;
    vector<int> arrow = info;
    int max = -55;
    for(int i = 0; i < arrow.size(); i++){
        arrow[i]++; //라이언이 점수를 얻기위한 최소한의 화살 갯수
        if(info[i]!=0){apeach.push_back(1);}
        else{apeach.push_back(0);}
    }
   

    for(int i = 1; i < 2048; i++){
        int ap = 0;
        int li = 0;
        vector<int> s = make_binary(i);
       

        int arrows = 0;
        for(int j=0;j<11;j++){
            if(s[j]==1){s[j]=arrow[j]; arrows+=arrow[j]; li += 10-j;}
        }
        if(arrows>n){continue;}else if(arrows < n){s[10] += n-arrows;}
        for(int j=0;j<11;j++){
            if(s[j]==0 && apeach[j]==1){ap += 10-j;}
        }
        if(max < (li-ap)){
            answer = s;
        }else if(max = (li-ap)){
            for(int j = 10; j>0;j--){
                if(answer[j] < s[j]){
                    answer = s;
                    break;
                }
            }
        }
        
    }
    return answer;
}



