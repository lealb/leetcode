#include <iostream>
#include <vector>
#include <unordered_map>
#include <time.h>
using namespace std;
class RandomizedCollection
{
    unordered_multimap<int, int> valmap;
    vector<unordered_multimap<int, int>::iterator> itvec;

public:
    /** Initialize your data structure here. */
    RandomizedCollection()
    {
        srand(time(0));
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val)
    {
        auto it = valmap.insert(pair<int, int>{val, itvec.size()});
        itvec.push_back(it);
        return true;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val)
    {
        auto it = valmap.find(val);
        if (it == valmap.end())
        {
            return false;
        }

        int i = it->second;
        swap(itvec[i], itvec[itvec.size() - 1]); // swap i with the last element
        itvec[i]->second = i;
        itvec.pop_back(); // pop_back() takes O(1) in average
        valmap.erase(it);

        return true;
    }

    /** Get a random element from the collection. */
    int getRandom()
    {
        return (itvec[rand() % itvec.size()])->first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
int main(int argc, char const *argv[])
{
    // Init an empty collection
    RandomizedCollection collection;
    // Inserts 1 to the collection. Returns true as the collection did not contain 1.
    cout << collection.insert(100) << endl;
    // Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
    cout << collection.insert(100) << endl;
    // Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
    cout << collection.insert(200) << endl;
    // getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
    cout << collection.getRandom() << endl;
    // Removes 1 from the collection, returns true. Collection now contains [1,2].
    cout << collection.remove(100) << endl;
    // getRandom should return 1 and 2 both equally likely.
    cout << collection.getRandom() << endl;
    system("pause");
    return 0;
}
