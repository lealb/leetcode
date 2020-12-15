#include <iostream>
#include <vector>
#include <unordered_map>
#include <string_view.h>
#include <queue>
using namespace std;
/**
 * @brief 
 * 1 <= s.length <= 104
 * s consists of lower-case English letters
 * 1 <= words.length <= 5000
 * 1 <= words[i].length <= 30
 * words[i] consists of lower-case English letters.
 */
class Solution
{
public:
    /**
     * @brief Two pointers
     * 
     * @param s 
     * @param words 
     * @return vector<int> 
     */
    vector<int> findSubstring_0(string s, vector<string> &words)
    {
        vector<int> result;
        if (words.empty())
        {
            return result;
        }
        unordered_map<string, int> counts, record;
        for (string word : words)
        {
            counts[word]++;
        }
        int len = words[0].size(), num = words.size(), sl = s.size();
        for (int i = 0; i < len; ++i)
        {
            int left = i, sum = 0;
            record.clear();
            for (int j = i; j <= sl - len; j += len)
            {
                string word = s.substr(j, len);
                if (counts.count(word))
                {
                    record[word]++;
                    sum++;
                    while (record[word] > counts[word])
                    {
                        //remove the most left word
                        record[s.substr(left, len)]--;
                        left += len;
                        sum--;
                    }
                    if (sum == num)
                    {
                        result.push_back(left);
                    }
                }
                else
                {
                    record.clear();
                    sum = 0;
                    left = j + len;
                }
            }
        }
        return result;
    }

    vector<int> findSubstring_1(string s1, vector<string> &words)
    {
        std::vector<int> result;
        size_t len = words.front().size();
        size_t total_len = len * words.size();

        if (s1.size() < total_len)
        {
            return result;
        }

        std::string_view s(s1.c_str(), s1.size());

        std::unordered_map<std::string_view, int> map;
        for (auto const &w : words)
        {
            map[w]++;
        }

        std::queue<std::string_view> queue;
        for (size_t i = 0; i < len; ++i)
        {
            int left = words.size();
            for (size_t j = i; j <= s.size() - len; j += len)
            {
                std::string_view view = s.substr(j, len);
                auto found = map.find(view);
                if (found != map.end())
                {
                    //found one
                    queue.emplace(view);
                    --found->second;
                    --left;
                    if (found->second < 0)
                    {
                        do
                        {
                            ++left;
                            ++map[queue.front()];
                            queue.pop();
                        } while (found->second < 0);
                    }
                    else if (found->second == 0 && left == 0)
                    {
                        result.emplace_back(j + len - total_len);
                        ++left;
                        ++map[queue.front()];
                        queue.pop();
                    }
                }
                else
                {
                    left = words.size();
                    while (!queue.empty())
                    {
                        ++map[queue.front()];
                        queue.pop();
                    }
                }
            }
            while (!queue.empty())
            {
                ++map[queue.front()];
                queue.pop();
            }
        }

        return result;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    vector<int> res = solution.findSubstring_0(s, words);
    for (auto r : res)
    {
        cout << r << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
