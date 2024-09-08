#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*

2개의 경우의 수

1. 짝수
-> 짝수의 첫 번째 bit는 무조건 0임.
-> Ex) 4 -> 0000 0100, 10 -> 0000 0110 ...
-> 그렇기에, bit가 1~2개 다른 수 중에서 제일 작은 수 => 해당 수의 첫 번째 bit를 1로 바꾼 수.

2. 홀수
-> 홀수의 첫 번째 bit는 무조건 1임.
-> Ex) 5 -> 0000 0101, 13 -> 0000 1101 ...
-> 그렇기에, bit가 1~2개 다른 수 중에서 제일 작은 수 => 첫 번째 bit에서 부터 올라가 0이 되는 곳을 n이라고 하면, n - 1의 자리를 +1.
-> 즉, 올림 한 수.

---------------------------------------------------------

bit의 대한 주석

-> bit는 1부터 시작한다. (0000 0001);
-> 홀수 일 때, 0이 되는 곳을 찾기 위해 존재.
-> numbers의 정수와 & 연산을 통해, 이를 파악한다.
-> & 연산에서 0이 나오지 않는다면, bit를 shift 연산자를 통해 왼쪽 이동.
-> & 연산에서 0이 나온다면, bit를 shitf 연산자를 통해 오른쪽 이동.

Procedure

-> Ex) numbers의 정수를 7이라고 가정 (0000 0111);
-> bit는 1부터 시작해서, & 연산을 진행

-> case 1
    0000 0001 & 0000 0111 = 0000 0001

bit를 왼쪽으로 1 만큼 이동
 -> bit = 2, (0000 0010);

-> case 2
    0000 0010 & 0000 0111 = 0000 0010
    
...

-> case n
    0000 1000 & 0000 0111 = 0000 0000

-> n - 1을 찾기 위해 bit를 오른쪽으로 1 만큼 이동
-> bit = 4 (0000 0100)

numbers + bit = 11 (0000 1011)
    
*/

vector<long long> solution(vector<long long> numbers) {
    
    vector<long long> answer;
    
    for(int i = 0; i < numbers.size(); i++)
    {
        if(numbers[i] % 2 == 0)
        {
            answer.push_back(numbers[i] + 1);
        }
        else
        {
            long long bit = 1;
            while(true)
            {
                //cout << (numbers[i] & bit) << '\n';
                if((numbers[i] & bit) == 0)
                    break;
                bit = (bit << 1);
            }
            
            bit = (bit >> 1);
            
            answer.push_back(numbers[i] + bit);
            //cout << bit << '\n';
        }
    }
    
    
    
    
    
    
    return answer;
}