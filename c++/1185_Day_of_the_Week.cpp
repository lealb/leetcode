#include <iostream>
#include <vector>

using namespace std;
/**
 * 1971-2020
 * 1971-1-1 Fri
 */
class Solution
{
public:
    bool isLeapYear(int year)
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
    string dayOfTheWeek(int day, int month, int year)
    {
        vector<string> weeks = {"Thursday", "Friday", "Saturday", "Sunday", "Monday",
                                "Tuesday", "Wednesday"};
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
        if (isLeapYear(year) && month > 2)
        {
            days[2]++;
        }
        int daysOfYear = day;
        for (int i = 0; i < month - 1; ++i)
        {
            daysOfYear += days[i];
        }
        int yearDays = (year - 1971) * 365;
        for (int i = 1971; i < year; ++i)
        {
            yearDays += isLeapYear(i) ? 1 : 0;
        }

        cout << yearDays << " " << daysOfYear << endl;
        return weeks[(daysOfYear + yearDays) % 7];
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.dayOfTheWeek(18, 11, 2020) << endl;
    // cout << solution.isLeapYear(1971) << endl;
    system("pause");
    return 0;
}
