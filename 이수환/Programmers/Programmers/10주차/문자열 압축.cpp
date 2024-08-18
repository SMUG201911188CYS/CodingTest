#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.length();
    
    // 1~s.length
    int size = 1;
    while(size < s.length()){
        int index = size;
        string countingStr = "";
        
        // count
        int count = 1;
        string originStr = s.substr(0, index);
        //cout << originStr <<"================"<<'\n';
        while(index < s.length()){
            string newStr = s.substr(index, size);
            //cout << "newStr : " << newStr<<'\n';
            if(newStr != originStr){
                if(count > 1)
                    countingStr += to_string(count);
                countingStr += originStr;
                originStr = newStr;
                count = 1;
            }
            else{
                count++;
            }
            index += size;
        }
        if(count > 1)
            countingStr += to_string(count);
        countingStr += originStr;
        
        //cout << countingStr << '\n';
        
        size++;
        
        if(answer > countingStr.length())
            answer = countingStr.length();
    }
    
    return answer;
}