#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<int> comb; // 조합에 필요한 벡터
    string tmp = ""; // 조합된 문자열을 임시로 저장해줄 변수
    map<string, int> c_menu; // 조합된 메뉴를 저장할 맵
    string ord; // 손님이 시킨 메뉴를 임시로 저장할 변수
    
    for (const auto& o : orders) { // 손님 수 만큼 반복
        for (int idx = 0; idx < course.size(); idx++) { // 코스 메뉴에 사용될 메뉴 수만큼
                                                        // 코스 메뉴를 짜야한다.
            if (o.size() < course[idx]) { // 만약 손님이 주문한 메뉴의 수가 코스메뉴 수보다
                continue;                 // 작으면 실행되지 않도록 한다.
            }
            comb.clear();
            for (int i = 0; i < o.size(); i++) { 
                if (i < course[idx]) {
                    comb.push_back(1);
                }
                else {
                    comb.push_back(0);
                }
            }
            
            ord = o;
            sort(ord.begin(), ord.end()); // 메뉴는 오름차순으로 정렬하라고 하므로, 
                                          // 오름차순으로 정렬해준다.
            do {
                for (int i = 0; i < comb.size(); i++) {
                    if (comb[i] == 1) {
                        tmp += ord[i];
                    }
                }
    			if (c_menu.count(tmp)) { // 이미 key가 있다면 값을 1 증가시킨다.
    				c_menu[tmp] += 1;
                    tmp = "";
    			}
    			else {
    				c_menu.insert({ tmp, 1 });
    				tmp = "";
    			}
            } while (prev_permutation(comb.begin(), comb.end())); // 벡터가 내림차순.
        }
    }
    
    for (const auto& t : course) {
        int max = 0; // value의 최댓값을 저장할 변수
        for (const auto& k : c_menu) {
            if (k.first.length() == t) {
                if (max < k.second) {
                    max = k.second;
                }
            }
        }

        for (const auto& k : c_menu) {
            if (k.first.length() == t && max == k.second && max != 1) {
                answer.push_back(k.first); // 최댓값이 1이면 혼자 이용한 조합이므로 배제한다.
            }
        }
    }
    
    sort(answer.begin(), answer.end()); // 오름차순으로 정렬해준다.
    
    return answer;
}