#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    /**
     * @brief 用哈希表来控制左指针和右指针移动
     * 
     * @param tree 
     * @return int 
     */
    int totalFruit(vector<int> &tree)
    {
        int i = 0, j = 0, max_res = 0;
        unordered_map<int, int> map;
        for (i = 0; i < tree.size(); i++)
        {
            map[tree[i]]++;
            while (map.size() > 2)
            {
                max_res = max(max_res, i - j);
                map[tree[j]]--;
                if (map[tree[j]] == 0)
                    map.erase(tree[j]);
                j++;
            }
        }
        max_res = max(max_res, i - j);
        return max_res;
    }
    int totalFruit_1(const vector<int> &t)
    {
        const int sz = t.size();
        int f_idx = 0;
        int s_idx = -1;
        int len = 0;
        int max = 0;
        for (int i = 0; i < sz; ++i)
        {
            if (t[i] == t[f_idx])
            {
                f_idx = i;
            }
            else if (s_idx == -1)
            {
                s_idx = i;
            }
            else if (t[i] == t[s_idx])
            {
                s_idx = i;
            }
            else
            {
                if (s_idx > f_idx)
                {
                    len = s_idx - f_idx;
                    f_idx = s_idx;
                }
                else
                {
                    len = f_idx - s_idx;
                }
                s_idx = i;
            }
            ++len;

            if (len > max)
                max = len;
        }

        return max;
    }
};
int main(int argc, char const *argv[])
{

    system("pause");
    return 0;
}
