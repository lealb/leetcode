#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string reformatDate(string date)
    {
        string d, m, y;
        int tmp_m, tmp_d;
        vector<string> month = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        istringstream iss(date);
        iss >> d >> m >> y;
        tmp_d = stoi(d);
        tmp_m = distance(begin(month), find(begin(month), end(month), m)) + 1;
        d = tmp_d < 10 ? "0" + to_string(tmp_d) : to_string(tmp_d);
        m = tmp_m < 10 ? "0" + to_string(tmp_m) : to_string(tmp_m);
        return y + "-" + m + "-" + d;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.reformatDate("20th Oct 2052") << endl;
    system("pause");
    return 0;
}
