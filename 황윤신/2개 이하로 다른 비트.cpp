#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (int i = 0; i < numbers.size(); i++) {
        long long num = numbers[i];
        long long mask = 1;
        int bitpos = 0;

        //첫번째 0이 나오는 자리 발견
        while (true) {
            long long tmp = num & mask;
            tmp = tmp >> bitpos;

            if (tmp & 1) mask = mask << 1;
            else break;

            bitpos++;
        }

        //0을 1로 반전
        num = num | mask;

        //0 오른쪽 1을 0으로 반전
        if (bitpos != 0) {
            mask = mask >> 1;
            mask = ~mask;
            num = num & mask;
        }


        answer.push_back(num);
    }

    return answer;
}