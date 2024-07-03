#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<pair<int, int>>> calc_emoticons(vector<pair<int, int>> emoticons, int size) {
    vector<vector<pair<int, int>>> sub_answer;

    if (size == 0) {
        sub_answer.push_back(emoticons);
        return sub_answer;
    }

    pair<int, int> prev_price = emoticons[size - 1];

    for (int i = 0; i < 4; i++) {
        emoticons[size - 1].first = 10 * (i + 1);
        emoticons[size - 1].second
            = emoticons[size - 1].second - emoticons[size - 1].second * 0.1 * (i + 1);
        for (auto prices : calc_emoticons(emoticons, size - 1))
            sub_answer.push_back(prices);

        emoticons[size - 1] = prev_price;
    }

    return sub_answer;
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer = { 0, 0 };

    vector<vector<pair<int, int>>> prices_set;
    vector<pair<int, int>> sale_emoticons;

    for (auto price : emoticons)
        sale_emoticons.push_back(make_pair(0, price));


    prices_set = calc_emoticons(sale_emoticons, emoticons.size());

    for (auto prices : prices_set) {
        vector<int> sub_answer = { 0, 0 };
        for (auto user : users) {
            int sum = 0;
            for (auto price : prices) {
                if (price.first >= user[0]) {
                    sum += price.second;
                    if (sum >= user[1]) break;
                }
            }

            if (sum >= user[1])
                sub_answer[0]++;
            else
                sub_answer[1] += sum;
        }

        if (sub_answer[0] > answer[0])
            answer = sub_answer;
        else if (sub_answer[0] == answer[0] && sub_answer[1] > answer[1])
            answer = sub_answer;
    }

    return answer;
}