#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        if (n == 0)
        {
            return 0;
        }
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (citations[mid] == n - mid)
            {
                return citations[mid];
            }
            else if (citations[mid] > n - mid)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return n - l;
    }
};
int main(int argc, char const *argv[])
{

    system("pause");
    return 0;
}
