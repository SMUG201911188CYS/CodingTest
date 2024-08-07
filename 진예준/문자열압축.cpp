#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.length();

    // 1개 단위(step) 부터 압축 단위를 늘려가며 확인
    for (int step = 1; step <= s.length() / 2; ++step)
    {
        string compressed = "";
        string prev = s.substr(0, step);
        int count = 1;

        // 단위 (step) 크기만큼 증가시키며 이전 문자열과 비교
        for (int j = step; j < s.length(); j += step)
        {
            // 이전 상태와 동일하다면 압축 홧수 (count) 증가
            if (prev == s.substr(j, step))
            {
                count++;
            }

            // 다른 문자열이 나왔다면 (더이상 압축을 못하는 경우라면)
            else
            {
                if (count >= 2) {
                    compressed += to_string(count) + prev;
                }
                else {
                    compressed += prev;
                }
                // 다시 상태 초기화
                prev = s.substr(j, step);
                count = 1;
            }
        }

        // 남아 있는 문자열에 대해서 처리
        if (count >= 2)
        {
            compressed += to_string(count) + prev;
        }
        else
        {
            compressed += prev;
        }

        // 만들어지는 압축 문자열이 가장 짧은 것이 정답
        answer = min(answer, static_cast<int>(compressed.length()));
    }

    return answer;
}

