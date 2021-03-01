#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int dayOfYear(string date)
    {
        //get y-m-d
        int year = stoi(date.substr(0, 4)), month = stoi(date.substr(5, 7)), day = stoi(date.substr(8, 10));
        // cout << year << " " << month << " " << day;
        //get days
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        {
            days[1] += 1;
        }
        int resDays = day;
        for (int i = 0; i < month - 1; ++i)
        {
            resDays += days[i];
        }
        return resDays;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.dayOfYear("2019-02-10") << endl;
    system("pause");
    return 0;
}
