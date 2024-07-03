#include <string>
#include <vector>
#include <stack>

using namespace std;

int calc_score(vector<int>& info, vector<int>& result) {
    int apeach = 0;
    int ryan = 0;
    
    for(int i = 0; i < info.size(); i++) {
        if(result[i] > info[i]) {
            ryan += 10 - i;
        } else {
            if(info[i] != 0)
                apeach += 10 - i;
        }
    }
    return ryan > apeach ? ryan-apeach : -1;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer = {-1};
    int max_score = 0;
    
    stack<pair<pair<vector<int>, int>, int>> s;
    
    for(int i = 0; i <= n; i++) {
        vector<int> temp(11);
        temp[0] = i;
        
        s.push(make_pair(make_pair(temp, i), 0));
    }
    
    while(!s.empty()) {
        pair<pair<vector<int>, int>, int> elem = s.top(); s.pop();

        if(elem.second == 10) {
            if(elem.first.second == n) {
                int score = calc_score(info, elem.first.first);
                if(score > max_score) {
                    max_score = score;
                    answer = elem.first.first;
                } else if(score != -1 && score == max_score) {
                    for(int i = 10; i >= 0; i--) {
                        if(answer[i] > elem.first.first[i]) {
                            break;
                        } else if(elem.first.first[i] > answer[i]) {
                            answer = elem.first.first;
                            break;
                        }
                    }
                }
            }
            continue;
        }
        
        elem.second += 1;
        
        for(int i = 0; i <= n - elem.first.second; i++) {
            elem.first.first[elem.second] = i;
            int temp = elem.first.second;
            elem.first.second += i;
            s.push(elem);
            elem.first.second = temp;
        }
    }
    
    return answer;
}