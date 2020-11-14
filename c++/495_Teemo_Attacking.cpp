#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int size = timeSeries.size();
        if (0 == size)
        {
            return 0;
        }
        int total = duration;
        for (int i = 1; i < size; ++i)
        {
            total += min(timeSeries[i] - timeSeries[i - 1], duration);
        }
        return total;
    }

    int findPoisonedDuration_0(vector<int> &timeSeries, int duration)
    {
        if (timeSeries.empty())
            return 0;
        const int N = timeSeries.size();
        int totalTime = duration;
        for (int i = 1; i < N; ++i)
        {
            int gap = timeSeries[i] - timeSeries[i-1];
            int delta = gap - duration;
            int sensor = (delta & 0x80000000) >> 31;
            sensor = ~(sensor - 1);
            totalTime += (delta & sensor) + duration;
        }
        return totalTime;
    }
};
int main()
{
    Solution solution;
    vector<int> times = {1, 2, 3, 4, 5};
    int duration = 5;
    cout << solution.findPoisonedDuration_0(times, duration) << endl;
    return 0;
}
