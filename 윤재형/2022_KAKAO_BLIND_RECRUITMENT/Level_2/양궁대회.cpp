#include <string>
#include <vector>

using namespace std;

vector<int> answer(1, -1);
int maxdiff = 0;

int calc(vector<int> r_info, vector<int> a_info){
    int r_score = 0;
    int a_score = 0;
    
    for(int i = 0; i < 11; ++i){
        if(r_info[i] > a_info[i]) r_score += 10 - i;
        else if(a_info[i] > 0) a_score += 10 - i;
    }
    
    return r_score - a_score;
}

void dfs(int cnt, int n, int idx, vector<int> apeach, vector<int> ryan){
    if(cnt == n){
        int diff = calc(ryan, apeach);
        if(diff > maxdiff){
            maxdiff = diff;
            answer = ryan;
        }else if(diff == maxdiff){
            for(int i = 10; i >= 0; --i){
                if(answer[i] > ryan[i])return;
                else if(answer[i] < ryan[i]){
                    answer = ryan;
                    break;
                }
            }
        }
        return;
    }
    
    for(int i = idx; i < 11; ++i){
        int arw = apeach[i] + 1;
        if(arw > (n - cnt)) arw = n - cnt;
        ryan[i] = arw;
        dfs(cnt + arw, n, i + 1, apeach, ryan);
        ryan[i] = 0;
    }
    
    return;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> ryan(11, 0);
    dfs(0, n, 0, info, ryan);
    
    return answer;
}
