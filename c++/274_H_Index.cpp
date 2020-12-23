#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        vector<int> arr(n + 1);
        for (int i = 0; i < n; i++)
        {
            if (citations[i] > n)
                arr[n]++;
            else
                arr[citations[i]]++;
        }
        int sum = 0;
        for (int i = n; i >= 0; i--)
        {
            sum += arr[i];
            if (sum >= i)
                return i;
        }
        return 0;
    }
    int hIndex_1(vector<int> &citations)
    {
        if (citations.empty())
        {
            return 0;
        }
        int n = citations.size();
        vector<int> hash(n + 1, 0);
        for (auto p : citations)
        {
            p >= n ? hash[n]++ : hash[p]++;
        }
        for (auto &h : hash)
        {
            cout << h << " ";
        }
        cout << endl;
        int paper = 0;
        for (int i = n; i >= 0; i--)
        {
            paper += hash[i];
            if (paper >= i)
                return i;
        }
        return 0;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> citations = {3, 0, 6, 1, 5};
    cout << solution.hIndex_1(citations) << endl;
    system("pause");
    return 0;
}
