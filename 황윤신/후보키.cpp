#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int cardinality = 0; //Ʃ���� ��
int degree = 0; //�Ӽ��� ��
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

    //����ũ���� �ĺ�
    vector<string> testKeys = keys;
    //����ũ �ϸ� ����Ű 1�� �ϼ�
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
    cardinality = relation_.size(); //���� �� ���� (Ʃ�� ����)
    degree = relation_[0].size(); //���� �� ���� (�Ӽ� ����)

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