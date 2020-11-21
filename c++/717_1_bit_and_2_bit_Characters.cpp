#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    /**
     * Approach #1: Increment Pointer 
     * if bits[i]==0 then 1bits +1
     * else 2 bits +2
     */
    bool isOneBitCharacter_0(vector<int> &bits)
    {
        int i = 0, size = bits.size();
        while (i < size - 1)
        {
            i += bits[i] + 1;
        }
        return i == size - 1;
    }
    /**
     * Approach #2: Greedy
     */
    bool isOneBitCharacter_1(vector<int> &bits)
    {
        int size = bits.size(), i = size - 2;
        while (i >= 0 && bits[i] > 0)
        {
            i--;
        }
        return (size - i) % 2 == 0;
    }
    bool isOneBitCharacter_2(vector<int> &bits)
    {
        int n = bits.size();
        for (int i = 0; i < n;)
        {
            if (i == n - 1 && bits[i] == 0)
                return true;
            if (bits[i] == 0)
            {
                i++;
                continue;
            }
            if (bits[i] == 1)
            {
                i += 2;
                continue;
            }
        }
        return false;
    }
};
int main(int argc, char const *argv[])
{

    system("pause");
    return 0;
}
