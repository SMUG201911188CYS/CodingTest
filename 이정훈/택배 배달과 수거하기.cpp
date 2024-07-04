#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    while (!deliveries.empty() && deliveries.back() == 0) deliveries.pop_back();
    while (!pickups.empty() && pickups.back() == 0) pickups.pop_back();

    while (!deliveries.empty() || !pickups.empty())
    {
        answer += deliveries.size() > pickups.size() ? deliveries.size() * 2 : pickups.size() * 2;

        int cur_deliv = 0;
        int cur_pickup = 0;

        while (!deliveries.empty() && cur_deliv < cap)
        {
            if (cur_deliv + deliveries.back() <= cap)
            {
                cur_deliv += deliveries.back();
                deliveries.pop_back();
            }
            else
            {
                deliveries[deliveries.size() - 1] -= cap - cur_deliv;
                cur_deliv = cap;
            }
        }

        while (!pickups.empty() && cur_pickup < cap)
        {
            if (cur_pickup + pickups.back() <= cap)
            {
                cur_pickup += pickups.back();
                pickups.pop_back();
            }
            else
            {
                pickups[pickups.size() - 1] -= cap - cur_pickup;
                cur_pickup = cap;
            }
        }

        while (!deliveries.empty() && deliveries.back() == 0) deliveries.pop_back();
        while (!pickups.empty() && pickups.back() == 0) pickups.pop_back();
    }

    return answer;
}