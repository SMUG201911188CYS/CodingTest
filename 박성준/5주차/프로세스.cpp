#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    // max_element를 사용하여 priorities 내에서 가장 큰 값을 가져오기
    int max = *max_element(priorities.begin(), priorities.end());
    
    while(true)
    {
        // priorities.size()까지 검색
        // max 값이 바뀌어도 i의 값은 1씩 증가하며 검색 (C, D, E, F, A, B 순서 가능)
        for(int i = 0; i < priorities.size(); ++i)
            if(priorities[i] == max) // 현재 위치(i)가 max값이라면?
            {
                ++answer; // 실행 순서 1 증가
                priorities[i] = -1; // 해당 위치는 사용 완료
                max = *max_element(priorities.begin(), priorities.end()); // 다음 max값 검색(같은 max일 수 있음)

                // i가 현재 위치라면 리턴
                if(i == location)    
                    return answer;
            }
    }
    
    return answer;
}