#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool is_valid_permutation(const vector<char>& perm, const vector<string>& data) {
    for (const string& condition : data) {
        char a = condition[0];
        char b = condition[2];
        char op = condition[3];
        int dist = condition[4] - '0';

        auto pos_a = find(perm.begin(), perm.end(), a);
        auto pos_b = find(perm.begin(), perm.end(), b);
        int actual_dist = abs(distance(pos_a, pos_b)) - 1;

        if (op == '=' && actual_dist != dist) return false;
        if (op == '<' && actual_dist >= dist) return false;
        if (op == '>' && actual_dist <= dist) return false;
    }
    return true;
}

int solution(int n, vector<string> data) {
    vector<char> friends = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    int count = 0;

    do {
        if (is_valid_permutation(friends, data)) {
            count++;
        }
    } while (next_permutation(friends.begin(), friends.end()));

    return count;
}

int main() {
    int n = 2;
    vector<string> data = {"N~F=0", "R~T>2"};
    
    cout << "Number of valid permutations: " << solution(n, data) << endl;
    
    return 0;
}