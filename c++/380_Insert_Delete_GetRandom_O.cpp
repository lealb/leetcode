#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class RandomizedSet
{

    // has the numbers to store
    vector<int> num;
    // has index of the numbers stored
    unordered_map<int, int> num_index;

public:
    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {

        // add number in our vector and store
        // its position in

        if (num_index.find(val) != num_index.end())
        {
            return false;
        }

        num.push_back(val);
        num_index[val] = num.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {

        // we will remove the element from map and from vector
        // as well, but we can only remove from vector when it
        // the element to be removed is at the end

        // so, we will move the last element to the place of the
        // element to be removed and then  delete the last value
        // of the vector

        if (num_index.find(val) == num_index.end())
        {
            return false;
        }

        int last = num.back();
        int to_be_removed = num_index[val];

        num[to_be_removed] = last;
        num_index[last] = to_be_removed;
        num_index.erase(val);
        num.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        return num[rand() % num.size()];
    }
};
class RandomizedSetOther
{
private:
    vector<int> values;
    unordered_map<int, int> position;

public:
    /** Initialize your data structure here. */
    RandomizedSetOther()
    {
    }
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (position.find(val) != position.end())
        {
            return false;
        }
        values.push_back(val);
        position[val] = values.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        auto pos = position.find(val);
        if (pos == position.end())
        {
            return false;
        }
        swap(values[values.size() - 1], values[pos->second]);
        position[values[pos->second]] = pos->second;
        values.pop_back();
        position.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        return values[rand() % values.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
int main(int argc, char const *argv[])
{
    RandomizedSet randomizedSet;
    randomizedSet.insert(1);   // Inserts 1 to the set. Returns true as 1 was inserted successfully.
    randomizedSet.remove(2);   // Returns false as 2 does not exist in the set.
    randomizedSet.insert(2);   // Inserts 2 to the set, returns true. Set now contains [1,2].
    randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
    randomizedSet.remove(1);   // Removes 1 from the set, returns true. Set now contains [2].
    randomizedSet.insert(2);   // 2 was already in the set, so return false.
    randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.

    system("pause");
    return 0;
}
