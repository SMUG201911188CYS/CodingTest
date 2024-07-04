// 참고: https://howudong.tistory.com/348

#include <string>
#include <vector>

using namespace std;

void backtracking(int,int); // 함수 정의

void simulation();

int len; // 입력 n

// 각 점수의 정댑 배열을 0으로 초기화
vector<int> peach;
vector<int> answer = {0,0,0,0,0,0,0,0,0,0,0};
vector<int> lion = {0,0,0,0,0,0,0,0,0,0,0};
int maxScore = 0; // 최대점수

// 백트래킹을 통해 나올 수 있는 모든 경우의 수를 구한뒤
// 바로 점수 계산을 시작한다.
void backtracking(int start, int cnt){
    if(cnt == len){
        simulation();
        return;
    }
    
    for(int i = start; i <= 10; i++){
        
        lion[i]++;
        backtracking(i,cnt+1);
        lion[i]--;
    }
}

// 점수 계산 함수
void simulation(){
    int lScore = 0; // 라이언 점수
    int pScore = 0; // 어피치 점수
    
    // 둘 다 0일때를 제외하고는 라이언이 커야지만 점수를 얻는다.
    for(int i = 0; i <= 10; i++){
        if(lion[i] == 0 && peach[i] == 0) continue;
        
        if(lion[i] > peach[i]) lScore += 10-i;
        else pScore += 10-i;
    }
    int result = lScore - pScore; // 두 사람의 격차
    
    // 라이언이 이기고, 새로운 점수가 기존 점수보다 크거나 같을 때
    if(result >= maxScore && lScore > pScore){
    	
        // 점수가 같을 때는 제일 낮은 점수의 개수 비교
        if(result == maxScore){
            for(int i = 10; i >= 0; i--){
                if(lion[i] > answer[i]){
                    answer = lion;
                    return;
                }
              	  // 가장 낮은 점수가 기존의 정답 배열이 더 클 때
                else if(lion[i] < answer[i]) return;
            }
        }
        // 새로 구한 최종 점수가 더 클때
        else{
            answer = lion;
        }
        
        maxScore = result; // 점수 갱신
    }
}
vector<int> solution(int n, vector<int> info) {
    len = n;
    peach = info;
    backtracking(0,0);
    
    // 최종 점수가 0점이라면 실패
    if(maxScore == 0) {
        answer.clear();
        answer.push_back(-1);
    }
    return answer;
}