#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 999999;
    int length = s.length();
    int count = 1;
    string temp = "";
    
    if(s.length() == 1)
        answer = 1;
    
    for(int i = 1; i <= length / 2 ; i++)
    {
        string split_str1 = s.substr(0, i);
        
        //cout << "str1 : " << split_str1 << '\n';
        for(int j = i; j <= length; j += i)
        {
            string split_str2 = s.substr(j, i);
            //cout << "str2 : " << split_str2 << '\n';
            if(split_str2.compare(split_str1) == 0)
                count++;
            else
            {
                if(count > 1)
                {
                    temp += to_string(count) + split_str1;
                }
                else
                {
                    temp += split_str1;
                }
                count = 1;
                split_str1 = s.substr(j, i);
                //cout << "else, str1 : " << split_str1 << '\n';
                
                if(j + i > length)
                    temp += split_str1;
            }
        }
        
        if(answer > temp.length())
            answer = temp.length();
        
        //cout << "result : " << temp << '\n';
        temp = "";
    }
    
    
    return answer;
}