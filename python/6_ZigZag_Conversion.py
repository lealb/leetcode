# encoding utf-8
"""
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
"""


class Solution:
    def convert(self, s: str, numRows: int) -> str:
        str_lenth = len(s)
        if 1 == str_lenth or numRows >= str_lenth:
            return s
        # 定义一个存储每行字符的数组，下标为行
        res = [[] for _ in range(numRows)]
        curr_row = 0
        is_down = -1
        for c in s:
            res[curr_row] += c
            is_down *= -1 if 0 == curr_row or curr_row == numRows-1 else 1
            curr_row += is_down
        print(res)
        for i in range(len(res)):
            res[i] = ''.join(res[i])
        return ''.join(res)

    def convert_1(self, s: str, numRows: int) -> str:
        '''
        zig zag means going all the way down and coming all the way up
        A       G
        |     / |
        B    F  H
        |   /   |
        C  E    i
        | /
        D

        1. add a letter in each row as we go down 
        2. and once we reach the 
        3. add a letter in each row as we go up
        4. and once reaching top repeat 1,2,3 until end of string
        '''
        str_lenth = len(s)
        if 1 == str_lenth or numRows >= str_lenth:
            return s
        matrix = [[] for _ in range(numRows)]

        i, k = 0, 0
        while k < str_lenth:
            while i < numRows and k < str_lenth:
                matrix[i].append(s[k])
                k += 1
                i += 1
            i -= 2
            while i > 0 and k < str_lenth:
                matrix[i].append(s[k])
                k += 1
                i -= 1
        return ''.join([''.join(row) for row in matrix])


if __name__ == "__main__":
    solution = Solution()
    print(solution.convert_1("PAYPALISHIRING", 3)) # PAHNAPLSIIGYIR
    print(solution.convert_1("PAYPALISHIRING", 4)) # PINALSIGYAHRPI
