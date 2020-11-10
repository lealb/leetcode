#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    /**
     * Approach 1: Horizontal scanning
     * Time complexity : O(S), where S is the sum of all characters in all strings.
     * In the worst case all nn strings are the same. The algorithm compares the string S1
     *  with the other strings [S2...Sn] 
     * There are S character comparisons, where S is the sum of all characters in the input array.
     * Space complexity : O(1). We only used constant extra space.
     */
    string longestCommonPrefix_0(vector<string> &strs)
    {
        int strsSize = strs.size();
        if (0 == strsSize)
        {
            return "";
        }
        string prefix(strs[0]);
        for (int i = 0; i < strsSize; i++)
        {
            // 没有考虑到["c","acc","ccc"]
            while (0 != strs[i].find(prefix))
            {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty())
                {
                    return "";
                }
            }
        }
        return prefix;
    }

    /**
         * Approach 2: Vertical scanning
         * Time complexity : O(S), where S is the sum of all characters in all strings.
         * In the worst case there will be nn equal strings with length mm and 
         * the algorithm performs S=m⋅n character comparisons. 
         * Even though the worst case is still the same as Approach 1, 
         * in the best case there are at most n*minLenn comparisons where minLenis 
         * the length of the shortest string in the array.
         * Space complexity : O(1). We only used constant extra space.
         */
    string longestCommonPrefix_1(vector<string> &strs)
    {
        if (0 == strs.size())
        {
            return "";
        }
        for (int i = 0; i < strs[0].length(); i++)
        {
            // 取第一个字符
            for (int j = 1; j < strs.size(); j++)
            {
                if (i == strs[j].length() || strs[j][i] != strs[0][i])
                {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }

    /**
     * Approach 3: Divide and conquer
     * Time complexity: O(S) where S is the number of all characters in the array
     * In the worst case we have n equal strings with length m, 
     * Space complexity: O(m*log n) [n as strings,m as length]
     */
    string longestCommonPrefix_3(vector<string> &strs)
    {
        int strsLength = strs.size();
        if (0 == strsLength)
        {
            return "";
        }
        return longestCommonPrefix_3(strs, 0, strsLength - 1);
    }
    string longestCommonPrefix_3(vector<string> &strs, int left, int right)
    {
        if (left == right)
        {
            return strs[left];
        }
        int mid = (left + right) / 2;
        string lcpLeft = longestCommonPrefix_3(strs, left, mid);
        string lcpRight = longestCommonPrefix_3(strs, mid + 1, right);
        return commonPrefix(lcpLeft, lcpRight);
    }
    string commonPrefix(string left, string right)
    {
        int minLength = min(left.length(), right.length());
        for (int i = 0; i < minLength; i++)
        {
            if (left[i] != right[i])
            {
                return left.substr(0, i);
            }
        }
        return left.substr(0, minLength);
    }

    /**
     * Approach 4: Binary search
     * Time complexity: O(S* log(m)) where S is the sum of all characters in all strings.
     * Space complexity : O(1)
     */
    string longestCommonPrefix_4(vector<string> &strs)
    {
        if (0 == strs.size())
        {
            return "";
        }
        // get the shortest string
        int minLength = strs[0].length();
        for (string str : strs)
        {
            int temp = str.length();
            minLength = min(minLength, temp);
        }
        int low = 1;
        int high = minLength;
        while (low <= high)
        {
            int middle = (low + high) / 2;
            if (isCommonPrefix(strs, middle))
            {
                low = middle + 1;
            }
            else
            {
                high = middle - 1;
            }
        }
        return strs[0].substr(0, (low + high) / 2);
    }
    bool isCommonPrefix(vector<string> &strs, int len)
    {
        string str1 = strs[0].substr(0, len);
        for (int i = 0; i < strs.size(); i++)
        {
            if (strs[i].find(str1) != 0)
            {
                return false;
            }
        }
        return true;
    }

    /**
     * Further Thoughts / Follow up
     * unfinshed [TODO]
     */
};

class TrieNode
{
private:
    TrieNode *links;
    int R = 26;
    bool isEnd;
    int size;

public:
    TrieNode()
    {
        links = new TrieNode[R];
    }
    TrieNode get(char ch)
    {
        return links[ch - 'a'];
    }
    void put(char ch, TrieNode node)
    {
        links[ch - 'a'] = node;
        size++;
    }
    int getLinks()
    {
        return size;
    }
    //assume methods containsKey, isEnd, get, put are implemented as it is described
    //in  https://leetcode.com/articles/implement-trie-prefix-tree/)
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
    bool getIsEnd()
    {
        return isEnd;
    }
};
class Trie
{
private:
    TrieNode root;

public:
    Trie()
    {
        root = TrieNode();
    }
    string searchLongestPrefix(string word)
    {
        TrieNode node = root;
        vector<string> prefix;
        for (int i = 0; i < word.length(); i++)
        {
            char currLetter = word[i];
            if (node.containsKey(currLetter) && 1 == node.getLinks() && !node.getIsEnd())
            {
                /* code */
            }
        }
    }
};
int main(int argc, char const *argv[])
{
    Solution solution = Solution();
    vector<string> strs = {"flower", "flow", "flight"};
    cout << solution.longestCommonPrefix_4(strs) << endl;
    // cout << solution.commonPrefix("flowsdfsd", "flow") << endl;
    return 0;
}
