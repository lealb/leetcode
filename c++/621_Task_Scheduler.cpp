#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int leastInterval_0(vector<char> &tasks, int n)
    {
        int taskCount = tasks.size();
        vector<int> count(26, 0);
        int maxFreq = 0;
        for (int i = 0; i < taskCount; i++)
        {
            count[tasks[i] - 'A']++;
            maxFreq = max(count[tasks[i] - 'A'], maxFreq);
        }
        //For maxFreq-1 occurences of most frequent character minTime is required.
        int minTime = (maxFreq - 1) * (n + 1);
        for (int i = 0; i < 26; i++)
        {
            if (count[i] == maxFreq)
            {
                minTime++;
            }
        }
        //Observation that if taskCount>minTime then taskCount is the answer
        return max(minTime, taskCount);
    }
    int leastInterval_1(vector<char> &tasks, int n)
    {
        int counter[26] = {0};
        for (char c : tasks)
        {
            counter[c - 'A']++;
        }

        sort(counter, counter + 26);
        int maxCnt = counter[25] - 1;
        int slots = maxCnt * n;

        for (int i = 26 - 2; i >= 0; i--)
        {
            slots -= min(counter[i], maxCnt);
        }

        return slots > 0 ? slots + tasks.size() : tasks.size();
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<char> tasks = {'A','A','A','A','A','A','B','C','D','E','F','G'};
    cout << solution.leastInterval_0(tasks, 2) << endl;
    system("pause");
    return 0;
}
