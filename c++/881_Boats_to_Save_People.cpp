#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    /**
     * @brief Sorted
     * O(NlogN)
     * @param people 
     * @param limit 
     * @return int 
     */
    int numRescueBoats(vector<int> &people, int limit)
    {
        int left = 0, right = people.size() - 1;
        int ans = 0;
        sort(people.begin(), people.end());
        while (left <= right)
        {
            if (limit >= people[left] + people[right])
            {
                left++;
                // cout << "(" << people[i] << "," << people[i + 1] << ")" << endl;
            }
            right--;
            ans++;
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    // 5,1,4,2 6
    vector<int> people = {5, 1, 4, 2};
    int limit = 6;
    cout << solution.numRescueBoats(people, limit) << endl;
    system("pause");
    return 0;
}
