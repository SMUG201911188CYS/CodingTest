#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    int idx1 = 0;
    int idx2 = 0;
    int qSize = queue1.size();
    int selected;
    long sum1=0;
    long sum2 = 0;
    for(int i = 0; i < qSize; i++){
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    if((sum1+sum2)%2 == 1)return -1;
    while(answer <= qSize * 4){
        if(sum1 == sum2){return answer;}
        else if(sum1 < sum2){
            selected = idx2 < qSize ? queue2[idx2] : queue1[idx2-qSize]; 
            sum1 += selected;
            sum2 -= selected;
            idx2++;
            answer++;
        }else{
            selected = idx1 < qSize ? queue1[idx1] : queue2[idx1-qSize];
            sum1 -= selected;
            sum2 += selected;
            idx1++;
            answer++;
        }
    }
    
    return -1;
}