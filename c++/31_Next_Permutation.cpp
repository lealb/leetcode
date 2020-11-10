#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    /**
     * finding first decreasing element from the right to left =>index i
     * finding number just greater the nums[i] from the index i to right =>index j
     * swap(nums[i-1],nums[j-1])
     * reverse[i+1:]
     */
    void nextPermutation(vector<int> &nums)
    {
        const int n = nums.size();
        int i, j;
        for (i = n - 1; i >= 1 && nums[i - 1] >= nums[i]; --i)
            ;
        if (i > 0)
        {
            for (j = i; j <= n - 1 && nums[j] > nums[i - 1]; ++j)
                ;
            swap(nums[i - 1], nums[j - 1]);
        }
        reverse(nums.begin() + i, nums.end());
    }

    void reverse(vector<int> &nums, int start)
    {
        int end = nums.size() - 1;

        while (start < end)
        {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
    void nextPermutation_1(vector<int> &nums)
    {
        int id1 = -1;
        int id2 = -1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                id1 = i;
                break;
            }
        }
        for (int i = nums.size() - 1; i >= 0 && id1 >= 0; i--)
        {
            if (nums[i] > nums[id1])
            {
                id2 = i;
                break;
            }
        }
        if (id1 >= 0 && id2 >= 0)
        {
            swap(nums[id1], nums[id2]);
        }
        // for(int i=0;i<nums.size();i++){
        //     cout<<nums[i]<<" ";
        // }
        // cout<<endl;
        reverse(nums, id1 + 1);
    }

    int bsearch(vector<int> nums, int l, int r, int key)
    {
        int index = -1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= key)
                r = mid - 1;
            else
            {
                l = mid + 1;
                if (index == -1 || nums[index] >= nums[mid])
                    index = mid;
            }
        }
        return index;
    }

    void reverse(vector<int> &nums, int l, int r)
    {
        while (l < r)
        {
            swap(&nums[l++], &nums[r--]);
        }
    }

    void swap(int *a, int *b)
    {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }

    void nextPermutation_2(vector<int> &nums)
    {

        int n = nums.size();

        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;

        if (i < 0)
            sort(nums.begin(), nums.end());
        else
        {
            int index = bsearch(nums, i + 1, n - 1, nums[i]);
            int tmp = nums[index];
            nums[index] = nums[i];
            nums[i] = tmp;
            reverse(nums, i + 1, n - 1);
        }
    }
};

int main(int argc, char const *argv[])
{

    system("pause");
    return 0;
}
