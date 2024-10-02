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

        //ù��° 0�� ������ �ڸ� �߰�
        while (true) {
            long long tmp = num & mask;
            tmp = tmp >> bitpos;

            if (tmp & 1) mask = mask << 1;
            else break;

            bitpos++;
        }

        //0�� 1�� ����
        num = num | mask;

        //0 ������ 1�� 0���� ����
        if (bitpos != 0) {
            mask = mask >> 1;
            mask = ~mask;
            num = num & mask;
        }


        answer.push_back(num);
    }

    return answer;
}