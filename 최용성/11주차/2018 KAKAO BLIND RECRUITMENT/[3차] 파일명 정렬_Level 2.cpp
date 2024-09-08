#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct File {
    int index;
    string head;
    int number;

    File(int index, string head, int number) : index(index), head(head), number(number) {}
};

bool cmp(File a, File b)
{
    if (a.head == b.head)
    {
        if (a.number == b.number)
            return a.index <= b.index;

        return a.number <= b.number;
    }

    return a.head <= b.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;

    vector<File> Separate_Files;

    for (int i = 0; i < files.size(); i++)
    {
        string head_temp = "";
        string number_temp = "";
        int j = 0;
        for (j = 0; j < files[i].size(); j++)
        {
            if (files[i][j] >= '0' && files[i][j] <= '9')
                break;

            head_temp += tolower(files[i][j]);
        }

        for (; j < files[i].size(); j++)
        {
            if (files[i][j] < '0' && files[i][j] > '9')
                break;

            number_temp += files[i][j];
        }

        Separate_Files.push_back(File(i, head_temp, stoi(number_temp)));

        //cout << Separate_Files[i].index << " " << Separate_Files[i].head << " " << Separate_Files[i].number << '\n';
    }

    sort(Separate_Files.begin(), Separate_Files.end(), cmp);

    for (auto it : Separate_Files)
    {
        cout << it.index << ", " << it.head << ", " << it.number << '\n';

        answer.push_back(files[it.index]);
    }


    return answer;
}