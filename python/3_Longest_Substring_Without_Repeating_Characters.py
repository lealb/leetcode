# encoding :utf-8

# 暴力解法
class Solution:
    def isUnique(self, test_str: str) -> bool:
        # write your code here
        a = list(test_str)  # 转化成列表
        n = len(a)
        for i in range(n):
            # 判断单个字符串a[i]出现次数
            if test_str.count(a[i]) != 1:
                return False
                # break
        return True

    def lengthOfLongestSubstring(self, s: str) -> int:
        """
        Time Limit Exceeded
        """
        if s == "":
            return 0
        if len(s) == 1:
            return 1
        str_length = len(s)
        res = 0
        for i in range(str_length):
            for j in range(i+1, str_length+1):
                # len(set(s[i:j])) == len(s[i:j])
                if self.isUnique(s[i:j]):
                    res = max(res, j-i)
        return res

    def lengthOfLongestSubstring_1(self, s: str) -> int:
        """
        Runtime: 68 ms	Memory Usage:14.2 MB
        """
        if s == "":
            return 0
        s_length = len(s)
        if s_length == 1:
            return 1
        ans, i, j = 0, 0, 0
        res_set = set()
        while i < s_length and j < s_length:
            if s[j] not in res_set:
                res_set.add(s[j])
                j += 1
                ans = max(ans, j-i)
            else:
                res_set.remove(s[i])
                i += 1
        return ans

    def lengthOfLongestSubstring_2(self, s: str) -> int:
        if s == "":
            return 0
        s_length = len(s)
        if s_length == 1:
            return 1
        ans, i = 0, 0
        res_map = {}
        for j in range(s_length):
            if s[j] in res_map:
                i = max(res_map.get(s[j]), i)
            ans = max(ans, j-i+1)
            res_map[s[j]] = j+1
        return ans


if __name__ == "__main__":
    solution = Solution()
    test_str = ["abcabcbb", "bbbbb", "pwwkew", "", " ", "er"]
    for s in test_str:
        print(s+": "+str(solution.lengthOfLongestSubstring(s)))
