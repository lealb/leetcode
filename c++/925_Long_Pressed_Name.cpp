#include <iostream>
#include <vector>

using namespace std;
/**
 * @brief 
 * 1 <= name.length <= 1000
 * 1 <= typed.length <= 1000
 * name and typed contain only lowercase English letters.
 */
class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        int left = 0, right = typed.size() - 1;
        int i = 0, j = name.size();
        while (left <= right)
        {
            if (i <= j - 1 && name[i] == typed[left])
            {
                i++;
                left++;
            }
            else if (left > 0 && name[i] != typed[left] && typed[left - 1] == typed[left])
            {
                left++;
            }
            else
            {
                return false;
            }
        }
        return i == j;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    string name = "alex", typed = "aaleex";
    cout << solution.isLongPressedName(name, typed) << endl;
    system("pause");
    return 0;
}
