# encoding:utf-8
class Solution:
    def longestPalindrome(self, s: str) -> str:
        """
        暴力破解，O(n^3)  Time Limit Exceeded
        """
        m = ''
        str_length = len(s)
        if str_length == 1:
            return s

        for i in range(str_length):
            for j in range(str_length+1):
                if len(m) >= j-i:
                    continue
                elif s[i:j] == s[i:j][::-1]:
                    m = s[i:j]
                    continue

        return m



if __name__ == "__main__":
    solution = Solution()
    test_str = ["babad", "cbbd", "a", "ac"]
    for s in test_str:
        print(solution.longestPalindrome(s))
