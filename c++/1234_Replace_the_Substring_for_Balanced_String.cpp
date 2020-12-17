#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/**
 * @brief 
 * 1 <= s.length <= 10^5
 * s.length is a multiple of 4
 * s contains only 'Q', 'W', 'E' and 'R'.
 * 
 */
class Solution
{
public:
    /**
     * @brief Map
     * 
     * @param s 
     * @return int 
     */
    int balancedString(string s)
    {
        if (s.empty())
            return 0;
        int n = s.size();
        int k = n / 4;
        unordered_map<char, int> need;
        // need is a map to record the letters which appears more than n/4 times.
        for (int i = 0; i < n; i++)
        {
            need[s[i]]++;
        }
        for (auto &m : need)
        {
            need[m.first] -= k;
        }

        int needCount = 0;
        for (auto m : need)
        {
            if (m.second > 0)
                needCount++;
        }

        if (needCount == 0)
            return 0;

        unordered_map<char, int> window;
        int left = 0, right = 0;
        int matchCount = 0;
        int res = n;
        while (right < n)
        {
            // right pointer moving to right
            char c = s[right];
            right++;
            if (need[c] > 0)
            {
                window[c]++;
                if (need[c] == window[c])
                {
                    matchCount++;
                }
            }
            // left pointer moving to right
            while (left < right && matchCount == needCount)
            {
                res = min(res, right - left);
                char d = s[left];
                left++;
                if (need[d] > 0)
                {
                    window[d]--;
                    if (need[d] > window[d])
                    {
                        matchCount--;
                    }
                }
            }
        }
        return res;
    }
    int balancedString_1(string s)
    {
        std::vector<int> char_vec(128, 0);
        int n = s.size();
        int k = n / 4;
        int res = s.size();
        for (auto c : s)
            char_vec[c]++;
        int i = 0;
        for (int j = 0; j < s.size(); j++)
        {
            char_vec[s[j]]--;
            while (i <= j + 1 && char_vec['Q'] <= k && char_vec['W'] <= k && char_vec['E'] <= k && char_vec['R'] <= k)
            {
                res = std::min(j - i + 1, res);
                char_vec[s[i++]]++;
            }
        }
        return res;
    }
    int balancedString_2(string s)
    {
        int sz2 = s.size();
        int mx2 = sz2 / 4;
        int arr[90] = {0};
        int en = 0;
        int mn = INT_MAX;
        for (char ch : s)
            arr[ch]++;
        if (arr['Q'] == arr['W'] && arr['W'] == arr['E'] && arr['E'] == arr['R'])
            return 0;
        for (int i = 0; i < sz2; ++i)
        {
            while (en < sz2 && (arr['Q'] > mx2 || arr['W'] > mx2 || arr['E'] > mx2 || arr['R'] > mx2))
            {
                arr[s[en]]--;
                en++;
            }
            if (arr['Q'] <= mx2 && arr['W'] <= mx2 && arr['E'] <= mx2 && arr['R'] <= mx2)
            {
                mn = min(mn, en - i);
            }
            arr[s[i]]++;
        }
        return mn;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "WWEQERQWQWWRWWERQWEQ";
    cout << solution.balancedString(s) << endl;
    system("pause");
    return 0;
}
