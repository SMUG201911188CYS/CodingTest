#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Detail{
    string head;
    int num;
    string tail;
};

vector<string> answer;

bool cmp(const Detail& d1, const Detail& d2){
    if(d1.head != d2.head) return d1.head < d2.head;
    else if(d1.num != d2.num) return d1.num < d2.num;
    return false;
}

Detail divide(string s){
    string head, num, temp;
    Detail detail;
    for(int i = 0; i<s.length();i++){
        if(!isdigit(s[i])&&num.empty()) temp+=s[i];
        else{
            if(head.empty()){
                head = temp;
                temp.clear();
                num += s[i];
            }
            else num += s[i];
        }
    }
    detail.head = head;
    detail.num = stoi(num);
    detail.tail = s;
    return detail;
}

vector<string> solution(vector<string> files) {
    vector<Detail> v;
    for(string file : files){
        v.push_back(divide(file));
    }
    
    for(int i=0; i < v.size();i++) transform(v[i].head.begin(),v[i].head.end(), v[i].head.begin(),::tolower);
    
    stable_sort(v.begin(),v.end(),cmp);
    for(int i = 0; i<v.size();i++) answer.push_back(v[i].tail);
    return answer;
}