#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <regex>
#include <algorithm>

using namespace std;

struct MusicInfo {
    
    int during_time;
    string name;
    string melody;
    
    MusicInfo(int During_time, string Name, string Melody) : during_time(During_time), name(Name), melody(Melody)  {}
};

string solution(string m, vector<string> musicinfos) {

    string sharp[7] = {"C#", "D#", "E#", "F#", "G#", "A#", "B#"};
    string replace_sharp[7] = {"c", "d", "e", "f", "g", "a", "b"};
    
    for(int i = 0; i < 7; i++)
    {
        m = regex_replace(m, regex(sharp[i]), replace_sharp[i]);
    }
    
    vector<MusicInfo> list;
    
    for(int i = 0, j = 0; i < musicinfos.size(); i++, j = 0)
    {
        istringstream split_str(musicinfos[i]);
        string arr_temp[4];
        //string temp = "";
        int count = 0;
        
        while(getline(split_str, arr_temp[j], ','))
        {
            j++;
        }
        
        for(int i = 0; i < 7; i++)
        {
            arr_temp[3] = regex_replace(arr_temp[3], regex(sharp[i]), replace_sharp[i]);
        }
        
        int start = stoi(arr_temp[0].substr(0, 2)) * 60 + stoi(arr_temp[0].substr(3, 2));
        int end = stoi(arr_temp[1].substr(0, 2)) * 60 + stoi(arr_temp[1].substr(3, 2));
        int during = end - start; 
        
        string temp;
        
        for(int k = 0; k <= during; k++)
        {
            if(count > arr_temp[3].length() - 1)
                count = 0;
            
            temp += arr_temp[3][count];
            count++;
        }
        
        MusicInfo m_temp(during, arr_temp[2], temp);
        list.push_back(m_temp);
    }

    int maxDuring = 0;
    string answer = "(None)";
    
    for(auto it : list)
    {
        if(it.melody.find(m) != it.melody.npos && maxDuring < it.during_time)
        {
            answer = it.name;
            maxDuring = it.during_time;
        }
        
    }
    
    return answer;
}