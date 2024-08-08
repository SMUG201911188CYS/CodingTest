#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size(); // 초기 답을 원래 문자열의 길이로 설정
    
    // 문자열을 1부터 s.size() / 2 길이까지 단위로 자름
    for (int i=1; i<=s.size() / 2; i++) {
        int cnt = 1; // 현재 반복 중인 문자열의 개수
        string temp = ""; // 압축된 문자열을 저장할 임시 변수
        string compareStr = s.substr(0, i); // 비교할 첫 번째 문자열 추출
        
        // 문자열을 주어진 단위(i)로 잘라서 비교
        for (int j=i; j<s.size(); j+=i) {
            string currentStr = s.substr(j, i); // 현재 비교할 문자열 추출
            if (compareStr == currentStr) cnt++; // 이전 문자열과 같으면 카운트 증가
            else {
                // 카운트가 1보다 크면 압축된 형태로 추가
                if (cnt > 1) temp += to_string(cnt);
                temp += compareStr; // 현재 비교 문자열 추가
                compareStr = currentStr; // 비교 문자열 갱신
                cnt = 1; // 카운트 초기화
            }
        }
        
        // 마지막에 남은 문자열 처리
        if (cnt > 1) temp += to_string(cnt);
        temp += compareStr;
        
        // 현재 압축된 문자열의 길이와 비교하여 더 짧은 것을 선택
        answer = answer > temp.size() ? temp.size() : answer;
    }
    
    return answer; // 가장 짧은 압축 문자열의 길이 반환
}
