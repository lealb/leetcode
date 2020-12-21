#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int sSize = s.size(), tSize = t.size();
        if (sSize == 0 || tSize == 0)
        {
            return "";
        }
        // Dictionary which keeps a count of all the unique characters in t.
        unordered_map<char, int> dictT;
        for (int i = 0; i < tSize; i++)
        {
            dictT.insert({i, (dictT.find(i) != dictT.end() ? dictT.at(i) : 0) + 1});
        }
        // Number of unique characters in t, which need to be present in the desired window.
        int required = dictT.size();
        // Left and Right pointer
        int l = 0, r = 0;

        // formed is used to keep track of how many unique characters in t
        // are present in the current window in its desired frequency.
        // e.g. if t is "AABC" then the window must have two A's, one B and one C.
        // Thus formed would be = 3 when all these conditions are met.
        int formed = 0;

        // Dictionary which keeps a count of all the unique characters in the current window.
        unordered_map<char, int> windowCounts;
        // ans list of the form (window length, left, right)
        vector<int> ans = {-1, 0, 0};
        while (r < sSize)
        {
            // Add one character from the right to the window
            windowCounts.insert({r, (windowCounts.find(r) != windowCounts.end() ? windowCounts.at(r) : 0) + 1});
            // If the frequency of the current character added equals to the
            // desired count in t then increment the formed count by 1.
            if (dictT.find(r) != dictT.end() && windowCounts.at(r) == dictT.at(r))
            {
                formed++;
            }
            // Try and contract the window till the point where it ceases to be 'desirable'.
            while (l <= r && formed == required)
            {
                char c = l;
                // Save the smallest window until now.
                if (ans[0] == -1 || r - l + 1 < ans[0])
                {
                    ans[0] = r - l + 1;
                    ans[1] = l;
                    ans[2] = r;
                }

                // The character at the position pointed by the
                // `Left` pointer is no longer a part of the window.
                windowCounts.insert({c, windowCounts.at(c) - 1});
                if (dictT.find(c) != dictT.end() && windowCounts.at(c) < dictT.at(c))
                {
                    formed--;
                }
                // Move the left pointer ahead, this would help to look for a new window.
                l++;
            }
            // Keep expanding the window once we are done contracting.
            r++;
        }
        return ans[0] == -1 ? "" : s.substr(ans[1], ans[2] + 1);
    }
    string minWindow_1(string s, string t)
    {
        int sLen = s.length();
        int tLen = t.length();

        vector<int> freqT(256, 0);
        vector<int> freqS(256, 0);
        for (int i = 0; i < tLen; i++)
            freqT[t[i]]++;

        int winLeft = 0;            //Current window will always be [winLeft,i]
        int ans = INT_MAX, ansLeft; //Track smallest window
        int count = 0;              //For tracking number of characters encountered of string t in string s

        for (int i = 0; i < sLen; i++)
        {
            if (freqT[s[i]] > 0 && freqT[s[i]] > freqS[s[i]])
                count++;
            freqS[s[i]]++;
            if (count == tLen)
            {
                /*
				All characters required are in current window
                Now , try to minimize window by removing extra character at the start of window
                */

                while (winLeft < i && //Extra frequency or zero frequency characters
                       (freqT[s[winLeft]] < freqS[s[winLeft]] || freqT[s[winLeft]] == 0))
                {

                    if (freqT[s[winLeft]] < freqS[s[winLeft]])
                        freqS[s[winLeft]]--;
                    winLeft++;
                }
                if (ans > (i - winLeft + 1))
                {
                    ans = (i - winLeft + 1);
                    ansLeft = winLeft;
                }
            }
        }
        if (ans == INT_MAX)
            return "";
        return s.substr(ansLeft, ans);
    }
    string minWindow_2(string s, string t)
    {
        if (s.empty() || t.empty())
            return "";
        vector<int> map(128, 0);
        for (auto c : t)
            map[c]++;
        int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
        while (end < s.size())
        {
            if (map[s[end++]]-- > 0)
                counter--; //in t
            while (counter == 0)
            { //valid
                if (end - begin < d)
                    d = end - (head = begin);
                if (map[s[begin++]]++ == 0)
                    counter++; //make it invalid
            }
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "ADOBECODEBANC", t = "ABC";
    cout << solution.minWindow_2(s, t) << endl;
    system("pause");
    return 0;
}
