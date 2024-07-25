#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int cardinality = 0; //튜플의 수
int degree = 0; //속성의 수
vector<vector<string>> relation_;
vector<vector<string>> s;

void printVec(vector<string> keys) {
    for (string s : keys) cout << s << ' ';
    cout << '\n';
}

bool isUnique(vector<string>& keys, int pos) {
    set<string> s;
    for (int i = 0; i < cardinality; i++) {
        keys[i] += relation_[i][pos];
        s.insert(keys[i]);
    }

    return s.size() == cardinality;
}

int GetCandiateKeyNum(int start, vector<string> keys)
{
    int ret = 0;

    //유니크한지 식별
    vector<string> testKeys = keys;
    //유니크 하면 유일키 1개 완성
    if (isUnique(testKeys, start)) {
        s.push_back(testKeys);
        return 1;
    }



    for (int i = start + 1; i < degree; i++) {
        ret += GetCandiateKeyNum(i, testKeys);
    }


    return ret;
}


int solution(vector<vector<string>> relation) {
    relation_ = relation;
    cardinality = relation_.size(); //세로 줄 개수 (튜플 개수)
    degree = relation_[0].size(); //가로 줄 개수 (속성 개수)

    string s = "";
    vector<string> keys(cardinality, s);

    int ret = 0;
    for (int i = 0; i < degree; i++) {
        ret += GetCandiateKeyNum(i, keys);
    }

    return ret;
}

int main(int argc, char** argv) {
    //vector<vector<string>> r = {{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}};
    vector<vector<string>> r = { {"100","ryan","music","1"},{"100","ryan","music","2"},{"100","ryan","music","3"} };
    //cout << r.size() << ' ' << r[0].size();
    cout << solution(r);

    for (int i = 0; i < s.size(); i++) printVec(s[i]);
}