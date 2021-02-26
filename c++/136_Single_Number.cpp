#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    /**
     * @brief Approach 1: List operation
     * T:O(N^2),S:O(N)
     * @param nums 
     * @return int 
     */
    int singleNumber(vector<int> &nums)
    {
        vector<int> noDuplicateList;
        for (auto num : nums)
        {
            auto it = find(noDuplicateList.begin(), noDuplicateList.end(), num);
            if (it == noDuplicateList.end())
            {
                noDuplicateList.push_back(num);
            }
            else
            {
                noDuplicateList.erase(it);
                // earse(noDuplicateList.begin(), noDuplicateList.end(), num);
            }
        }
        return noDuplicateList[0];
    }

    /**
     * @brief Hash Table
     * O(n)
     * @param nums 
     * @return int 
     */
    int singleNumber_1(vector<int> &nums)
    {
        unordered_map<int, int> resMap;
        for (auto num : nums)
        {
            auto it = resMap.find(num);
            if (it == resMap.end())
            {
                resMap.insert({num, 1});
            }
            else
            {
                resMap.erase(it);
            }
        }
        return resMap.begin()->first;
    }

    /**
     * @brief Approach 3: Bit Manipulation
     * 2∗(a+b+c)−(a+a+b+b+c)=c
     * a⊕0=a
     * a⊕a=0
     * a⊕b⊕a=(a⊕a)⊕b=0⊕b=b
     * @param nums 
     * @return int 
     */
    int singleNumber_2(vector<int> &nums)
    {
        int a = 0;
        for (auto num : nums)
        {
            a ^= num;
        }
        return a;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> list = {4, 3, 4, 1, 2, 1, 2};
    cout << solution.singleNumber_2(list) << endl;
    system("pause");
    return 0;
}
