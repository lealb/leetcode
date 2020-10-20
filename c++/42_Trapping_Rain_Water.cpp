#include <iostream>
#include <vector>

using namespace std;
/**
 * n == height.length
 * 0 <= n <= 3 * 10^4
 * 0 <= height[i] <= 10^5
 */
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int heightLen = height.size();
        int res = 0;
        if (0 == heightLen)
        {
            return res;
        }
        // 0,1,0,2,1,0,1,3,2,1,2,1
        // 4,2,0,3,2,5
        for (int i = 1; i < heightLen - 1; i++)
        {
            if (height[i] < height[i - 1])
            {
                if (height[i]<height[i+1])
                {
                    res+=1;
                }
                
            }else{
                i++;
            }
        }
    }
};
int main(int argc, char const *argv[])
{

    system("pause");
    return 0;
}
