#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool CheckDistance(char Operator, int between, int distance){
    if(Operator == '='){
        return between == distance;
    }else if(Operator == '>'){
        return between > distance;
    }else if(Operator == '<'){
        return between < distance;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    string s = "ACFJMNRT";
    do{
        int flag = true;
        for(int i = 0; i < n; i++){
            char c1 = data[i][0];
            char c2 = data[i][2];
            char Operator = data[i][3];
            int distance = data[i][4] - '0';

            int between = s.find(c1)-s.find(c2);
            if( !CheckDistance(Operator,abs(between)-1,distance)){
                flag = false;
                break;
            }
        }
        if(flag){answer++;}
    }
    while(next_permutation(s.begin(),s.end()));
    return answer;
}