#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    /**
     * Approach 1: Categorize by Sorted String
     * Time Complexity: O(NKlogK), where N is the length of strs, 
     * and K is the maximum length of a string in strs. 
     * The outer loop has complexity O(N) as we iterate through each string. 
     * Then, we sort each string in O(KlogK) time.
     * Space Complexity: O(NK), the total information content stored in ans
     */
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> ans;
        if (0 == strs.size())
        {
            return {};
        }
        for (auto s : strs)
        {
            string value = s;
            sort(s.begin(), s.end());
            // if (ans.find(s) == ans.end())
            // {
            //     ans.insert({s, {}});
            // }
            // ans.at(s).push_back(value);
            ans[s].push_back(value);
        }
        // https://thispointer.com/how-to-copy-all-values-from-a-map-to-a-vector-in-c/
        for (auto it = ans.begin(); it != ans.end(); ++it)
        {
            res.push_back(it->second);
        }
        return res;
    }

    /**
     * Approach 2: Categorize by Count
     * Time Complexity: O(NK), where N is the length of strs, 
     * and K is the maximum length of a string in strs. 
     * Counting each string is linear in the size of the string, and we count every string.
     * Space Complexity: O(NK), the total information content stored in ans
     */
    vector<vector<string>> groupAnagrams_1(vector<string> &strs)
    {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> ans;
        if (0 == strs.size())
        {
            return {};
        }
        array<int, 26> count;
        for (auto &&s : strs)
        {
            // key
            count.fill(0);
            for (auto &&c : s)
            {
                count[c - 'a']++;
            }
            string key = "#";
            for (int i = 0; i < 26; i++)
            {
                key += to_string(count[i]);
            }
            // cout << "key: " << key << endl;
            ans[key].push_back(s);
        }
        for (auto v : ans)
        {
            res.push_back(v.second);
        }
        return res;
    }

    int p[26];
    vector<vector<string>> groupAnagrams_3(vector<string> &strs)
    {
        init();

        unordered_map<int, vector<string>> m;

        for (string &s : strs)
        {
            m[getHash(s)].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto to : m)
            ans.push_back(to.second);
        return ans;
    }
    void init()
    {
        int cnt = 0;
        int n = 2;
        while (cnt < 26)
        {
            if (isPrime(n))
            {
                p[cnt] = n;
                cnt++;
            }
            n++;
        }
    }

    bool isPrime(int n)
    {
        for (int i = 2; i <= sqrt(n); ++i)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    int getHash(string &s)
    {
        long long h = 1;
        long long mod = 1e9 + 7;
        for (char c : s)
        {
            h *= 1ll * p[c - 'a'];
            h %= mod;
        }
        return h;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution solution = Solution();
    vector<vector<string>> res = solution.groupAnagrams_1(strs);
    for (int i = 0; i < res.size(); i++)
    {
        for (auto r : res[i])
        {
            cout << r << " ";
        }
        cout << endl;
    }
    return 0;
}
