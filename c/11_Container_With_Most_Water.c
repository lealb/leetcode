#include <windows.h>
#include <stdio.h>
#include <windef.h>
#define MAX(a, b) (a > b) ? (a) : (b)
#define MIN(a, b) (a < b) ? (a) : (b) // 为何有问题？
/**
 * 暴力解法
 * Time complexity : O(n^2)Calculating area for all n(n−1)/2 height pairs.
 * Space complexity : O(1). Constant extra space is used.
 */
int maxArea(int *height, int heightSize)
{
    int maxArea = 0;
    for (int i = 0; i < heightSize; i++)
    {
        for (int j = i + 1; j < heightSize; j++)
        {
            maxArea = max(maxArea, min(height[i], height[j]) * (j - i));
        }
    }
    return maxArea;
}
/**
 * Approach 2: Two Pointer Approach
 * Time complexity : O(n)O(n). Single pass.
 * Space complexity : O(1)O(1). Constant space is used.
 */
int maxArea_1(int *height, int heightSize)
{
    int maxArea = 0, left = 0, right = heightSize - 1;
    while (left < right)
    {
        maxArea = max(maxArea, min(height[left], height[right]) * (right - left));
        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return maxArea;
}

int main(int argc, char const *argv[])
{
    int testHeight[9] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    printf("%d", maxArea(testHeight, 9));
    return 0;
}
