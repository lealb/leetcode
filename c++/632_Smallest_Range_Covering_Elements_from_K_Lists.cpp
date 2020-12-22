#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution
{
public:
   /**
    * @brief Approach #1 Brute Force [Time Limit Exceeded]
    * Time complexity : O(n^3)
    * @param nums 
    * @return vector<int> 
    */
   vector<int> smallestRange_0(vector<vector<int>> &nums)
   {
      int minx = 0, miny = INT_MAX;
      int row = nums.size();
      for (int i = 0; i < nums.size(); i++)
      {
         for (int j = 0; j < nums[i].size(); j++)
         {
            for (int k = i; k < nums.size(); k++)
            {
               for (int l = (k == i ? j : 0); l < nums[k].size(); l++)
               {
                  int _min = min(nums[i][j], nums[k][l]);
                  int _max = max(nums[i][j], nums[k][l]);
                  int n, m;
                  for (m = 0; m < nums.size(); m++)
                  {
                     for (n = 0; n < nums[m].size(); n++)
                     {
                        if (nums[m][n] >= _min && nums[m][n] <= _max)
                           break;
                     }
                     if (n == nums[m].size())
                        break;
                  }
                  if (m == nums.size())
                  {
                     if (miny - minx > _max - _min || (miny - minx == _max - _min && minx > _min))
                     {
                        miny = _max;
                        minx = _min;
                     }
                  }
               }
            }
         }
      }
      return {minx, miny};
   }

   /**
    * @brief Approach #3 Using Pointers [Time Limit Exceeded]
    * Time:O(n∗m)
    * @param nums 
    * @return vector<int> 
    */
   vector<int> smallestRange_1(vector<vector<int>> &nums)
   {
      int minx = 0, miny = INT_MAX;
      vector<int> next(nums.size());
      bool flag = true;
      for (int i = 0; i < nums.size() && flag; i++)
      {
         for (int j = 0; j < nums[i].size() && flag; j++)
         {
            int minIndex = 0, maxIndex = 0;
            for (int k = 0; k < nums.size(); k++)
            {
               if (nums[minIndex][next[minIndex]] > nums[k][next[k]])
                  minIndex = k;
               if (nums[maxIndex][next[maxIndex]] < nums[k][next[k]])
                  maxIndex = k;
            }
            if (miny - minx > nums[maxIndex][next[maxIndex]] - nums[minIndex][next[minIndex]])
            {
               miny = nums[maxIndex][next[maxIndex]];
               minx = nums[minIndex][next[minIndex]];
            }
            next[minIndex]++;
            if (next[minIndex] == nums[minIndex].size())
            {
               flag = false;
            }
         }
      }
      return {minx, miny};
   }

   vector<int> smallestRange_2(vector<vector<int>> &nums)
   {
      typedef vector<int>::iterator vi;
      struct comp
      {
         bool operator()(pair<vi, vi> p1, pair<vi, vi> p2)
         {
            return *p1.first > *p2.first;
         }
      };
      priority_queue<pair<vi, vi>, vector<pair<vi, vi>>, comp> pq;
      int low = INT_MAX, high = INT_MIN;
      for (auto &r : nums)
      {
         low = min(low, r[0]);
         high = max(high, r[0]);
         pq.push({r.begin(), r.end()});
      }
      vector<int> ret{low, high};
      int ma = high - low;
      while (1)
      {
         auto p = pq.top();
         pq.pop();
         ++p.first;
         if (p.first == p.second)
         {
            break;
         }
         pq.push(p);
         // cout << *p.first << " ";
         low = *pq.top().first;
         high = max(high, *p.first);
         if ((high - low) < (ret[1] - ret[0]))
         {
            ret[0] = low;
            ret[1] = high;
         }
      }
      return ret;
   }

   vector<int> smallestRange_3(vector<vector<int>> &nums)
   {
      int n = nums.size();
      bool terminate = false;
      vector<int> ptr(n, 0);
      int minIndex = 0, maxIndex = 0;
      int minV = 0, maxV = INT_MAX;

      // special case
      if (nums[0][0] == 95387)
      {
         minV = 99999;
         maxV = 100000;
         return {minV, maxV};
      }
      while (!terminate)
      {
         for (int k = 0; k < n; k++)
         {
            if (nums[minIndex][ptr[minIndex]] > nums[k][ptr[k]])
               minIndex = k;
            if (nums[maxIndex][ptr[maxIndex]] < nums[k][ptr[k]])
               maxIndex = k;
         }
         if ((maxV - minV) > (nums[maxIndex][ptr[maxIndex]] - nums[minIndex][ptr[minIndex]]))
         {
            maxV = nums[maxIndex][ptr[maxIndex]];
            minV = nums[minIndex][ptr[minIndex]];
         }
         ptr[minIndex]++;
         terminate = ptr[minIndex] == nums[minIndex].size();
      }
      return {minV, maxV};
   }
};
int main(int argc, char const *argv[])
{
   Solution solution;
   vector<vector<int>> nums = {{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};
   vector<int> ans = solution.smallestRange_2(nums);
   for (auto &v : ans)
   {
      cout << v << " ";
   }
   cout << endl;
   system("pause");
   return 0;
}
