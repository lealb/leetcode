import bisect


class Solution:
    def intToRoman(self, num: int) -> str:
        Map = {1: "I", 4: "IV", 5: "V", 9: "IX", 10: "X", 40: "XL", 50: "L",
               90: "XC", 100: "C", 400: "CD", 500: "D", 900: "CM", 1000: "M"}
        lis = list(Map.keys())
        number = ""
        while num != 0:
            find = (bisect.bisect(lis, num))-1
            number += Map[lis[find]]
            num -= lis[find]
        return number


if __name__ == "__main__":
    solution = Solution()
    testData = [1, 3, 4, 58, 1994, 2020]
    for i in testData:
        print(solution.intToRoman(i))
