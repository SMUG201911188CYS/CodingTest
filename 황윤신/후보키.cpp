#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
int cardinality = 0; //튜플의 수 (행의 수)
int degree = 0; //속성의 수 (열의 수)
vector<vector<string>> relation_; //릴레이션
vector<vector<int>> candidateCom; //유일키 조합

void PrintVec(vector<string> keys) {
    for (string s : keys) cout << s << ' ';
    cout << '\n';
}

void PrintVec(vector<int> keys) {
    for (int s : keys) cout << s << ' ';
    cout << '\n';
}

bool IsUnique(vector<string>& keys, int pos) {
    for (int i = 0; i < cardinality; i++) {
        s.insert(keys[i]);
    }
    return s.size() == cardinality;
}

bool IsMinimality(vector<int>& nowCom) {
    for (int i = 0; i < candidateCom.size(); i++) {
        bool flag = false;
        for (int j = 0; j < candidateCom[i].size(); j++) {
            if (find(nowCom.begin(), nowCom.end(), candidateCom[i][j]) == nowCom.end()) {
                flag = true;
                break;
            }
        }
        if (flag == false)return false;
    }
    return true;
}

void AppendKey(vector<string>& keys, int pos)
{
    for (int i = 0; i < cardinality; i++) {
        keys[i] += relation_[i][pos];
    }
}

int GetCandiateKeyNum(int targetLen, int depth, int start, vector<string> keys, vector<int> nowCom)
{
    int ret = 0;
    //키 덧붙이기
    AppendKey(keys, start);
    nowCom.push_back(start);
    //현재 만든 조합 갯수가 targetLen과 같으면
    //유일성과 최소성 판정하기
    if (depth == targetLen) {
        //PrintVec(keys);
        if (IsUnique(keys, start) && IsMinimality(nowCom)) {
            candidateCom.push_back(nowCom);
            return 1;
        }
        else return ret;
    }
    for (int i = start + 1; i < degree; i++) {
        ret += GetCandiateKeyNum(targetLen, depth + 1, i, keys, nowCom);
    }
    return ret;
}

int solution(vector<vector<string>> v) {
    relation_ = v;
    cardinality = relation_.size(); //세로 줄 개수 (튜플 개수)
    degree = relation_[0].size(); //가로 줄 개수 (속성 개수)
    string s = "";
    vector<int> nowCom; //현재 만든 키 조합 
    vector<string> keys(cardinality, s);

    int ret = 0;
    //몇개 선택할지 정하기
    for (int i = 0; i < degree; i++) {
        //몇번째 부터 시작할지 정하기
        for (int j = 0; j < degree; j++) {
            ret += GetCandiateKeyNum(i + 1, 1, j, keys, nowCom);
        }
    }
    return ret;
}

int main(int argc, char** argv) {
    vector<vector<string>> v = { {"100","ryan","music","2"},
    {"200","apeach","math","2"},
    {"300","tube","computer","3"},
    {"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"} };
    cout << solution(v);
}