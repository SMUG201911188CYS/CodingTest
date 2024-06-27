#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

// 코스요리 메뉴는 최소 2가지 이상의 단품 메뉴
// 최소 2명 이상의 손님으로 부터 주문된 단품메뉴 조합에 대해서만 코스요리 메뉴 후보에 포함

map<vector<char>, int> result;

void Combination(vector<char>& orderStr, vector<char> str, int depth) {
    for (int i = depth; i < orderStr.size(); i++) {
        vector<char>curStr(str);
        curStr.push_back(orderStr[i]);

        sort(curStr.begin(), curStr.end());

        if (result.find(curStr) == result.end()) {
            result.insert(pair<vector<char>, int>(curStr, 1));
        }
        else {
            result[curStr]++;
        }
        Combination(orderStr, curStr, i + 1);
    }
}

bool compare(const pair<vector<char>, int>& a, const pair<vector<char>, int>& b) {
    return a.second > b.second;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    // course 숫자에 맞는 result를 만들어야 한다.

    // 각 order에서 만들 수 있는 2개 이상의 코스 요리를 만들고 더해가는 식으로
    vector<vector<char>> strVec;
    for (string order : orders) {
        vector<char> orderStr;
        for (int i = 0; i < order.length(); i++) {
            orderStr.push_back(order[i]);
        }
        strVec.push_back(orderStr);

        result.insert(pair<vector<char>, int>(orderStr, 0));


        vector<char> str;
        Combination(orderStr, str, 0);
    }

    vector<pair<vector<char>, int>>resultVec(result.begin(), result.end());

    sort(resultVec.begin(), resultVec.end(), compare);

    vector<int> resultLength(21, 2);
    for (const auto& item : resultVec) {
        for (int num : course) {
            if (num == item.first.size() && item.second >= resultLength[num]) {
                string str = string(item.first.begin(), item.first.end());
                //cout << str << " : " << item.second << '\n';
                resultLength[num] = item.second;
                answer.push_back(str);
                break;
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}