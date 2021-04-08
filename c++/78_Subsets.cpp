#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution
{
public:
    /**
     * @brief bits
     *  other ways dfs back
     * @param nums 
     * @return vector<vector<int>> 
    */
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        // 将空集加入集合
        ans.push_back({});

        // 含有n个元素的集合有2^n个子集（因为一个元素要不然在子集中，要不然不在子集中，共两种可能性）
        int subSize = pow(2, nums.size());

        int count = 1; // 现在ans中共有一个子集——空集

        // 重点是count的值，count的取值范围是[0, 2^n)
        // 比如当n=3，nums = {1, 2, 3}的时候,count的取值范围是[0, 8)，
        // 对应于二进制表示就是000、001、010、011、100、101、110、111
        // 将上述表示与子集分别对应起来,即二进制最高位对应于集合中的第一个元素1，最低位对应于3
        // 比如 000 -> {} 、 101 ->{1,3}

        // 再来看中间的与运算，当count=3=011B时(B表示二进制)
        // 只有i=0(1左移0位，对应于t=001B)和i=1(1左移1位，对应于t=010B)时
        // 与count(3=011B)取与运算，结果才不为0，刚好在temp中添加了nums[0]和nums[1]
        while (count < subSize)
        {
            vector<int> temp;
            for (int i = 0; i < nums.size(); i++)
            {
                int t = 1 << i; // 1 左移 i 位,左移0位->001,左移1位->010,左移两位->100……
                if (t & count)
                {
                    temp.push_back(nums[i]);
                }
            }
            ans.push_back(temp);
            count++;
        }
        return ans;
    }

    /**
     * @brief iter
     * 
     * @param nums 
     * @return vector<vector<int>> 
     */
    vector<vector<int>> subsets_1(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();

        // 1 << n 就是子集的个数
        for (int i = 0; i < (1 << n); i++)
        {
            temp.clear(); // 清空temp中的元素
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
    vector<vector<int>> subsets_2(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        ans.push_back(temp); // 将空集加入集合
        for (int t : nums)
        { 
            // 遍历数组元素
            int n = ans.size();
            for (int i = 0; i < n; i++)
            { 
                // 将第一层for循环遍历到的元素分别加入ans的每一个已有子集中
                temp = ans[i];
                temp.push_back(t);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> ans = solution.subsets(nums);
    for (auto a : ans)
    {
        cout << "[";
        for (auto v : a)
        {
            cout << v << " ";
        }
        cout << "],";
    }
    cout << endl;
    system("pause");
    return 0;
}
