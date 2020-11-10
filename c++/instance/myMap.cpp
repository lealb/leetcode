#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    // init map
    unordered_map<string, vector<string>> res;
    res.insert({"a", {}});
    vector<string> v;
    v.push_back("wer");
    res["a"] = vector<string>({"A"});
     res["a"] = vector<string>({"B"});
    for (auto it = res.begin(); it != res.end(); ++it)
    {
        cout << " " << it->first << ":" << endl;
        for (int i = 0; i < it->second.size(); i++)
        {
            cout << it->second[i]<<" ";
        }
    }
    cout << endl;
    return 0;
}
