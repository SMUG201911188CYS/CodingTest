#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> result;
int resultSum = 0;
int count = 0;
int resultLastNum = 11;
void Check(vector<int> apeachInfo, vector<int> lionInfo, int apeachSum, int lionSum, int total, int use) {
    if (apeachSum < lionSum && resultSum <= lionSum - apeachSum) {
        int lionLastNum = 0;
        for (int i = 10; i >= 0; i--) {
            if (lionLastNum == 0 && lionInfo[i] > 0) {
                lionLastNum = i;
            }
        }

        bool flag = false;
        if (resultSum == lionSum) {
            for (int i = 10; i >= 0; i--) {
                if (lionInfo[i] > 0 && (lionInfo[i] == result[i])) {
                    continue;
                }
                else if (lionInfo[i] > 0) {
                    break;
                }
                else if (result[i] > 0) {
                    flag = true;
                    break;
                }
            }
        }

        if (!flag) {
            resultLastNum = lionLastNum;
            resultSum = lionSum - apeachSum;
            result = lionInfo;
            if (total - use > 0) {
                result[10] = total - use;
            }
        }
    }
    for (int i = 0; i <= 10; i++) {
        if (apeachInfo[i] != -1 && total - use >= apeachInfo[i] + 1) {

            int apeachScore = apeachSum;
            if (apeachInfo[i] > 0) {
                apeachScore -= (10 - i);
            }

            vector<int> newLionInfo(lionInfo);
            vector<int> newApeachInfo(apeachInfo);
            newLionInfo[i] = apeachInfo[i] + 1;
            newApeachInfo[i] = -1;

            Check(newApeachInfo, newLionInfo, apeachScore, lionSum + (10 - i), total, use + apeachInfo[i] + 1);
        }
    }

}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;

    int sum = 0;
    for (int i = 0; i <= 10; i++) {
        if (info[i] > 0) {
            sum += 10 - i;
        }
    }

    // 발사 수, 점수 판
    vector<int> lionInfo(11, 0);
    Check(info, lionInfo, sum, 0, n, 0);

    sum = 0;
    for (auto num : result) {
        cout << num << ", ";
        sum += num;
    }
    cout << '\n';

    cout << resultSum << '\n';
    if (resultSum == 0)
        return vector<int>(1, -1);
    return result;
}