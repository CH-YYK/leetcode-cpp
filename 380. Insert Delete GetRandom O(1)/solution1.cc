#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>

using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
        // 1. support random access for getRandom: array(elements)
        // 2. support O(1) insert and removal: {elements: index}
        // 
        // insert -> append to array -> update hashmap
        // remove -> replace with the last element -> pop element -> update mp
    }
    
    bool insert(int val) {
        if(mp.count(val)) 
            return false;
        else {
            mp[val] = arr.size();
            arr.push_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(mp.count(val)) {
            int lastind = arr.size() - 1;
            int oldind = mp[val];
            
            mp[arr[lastind]] = oldind;
            swap(arr[oldind], arr[lastind]);
            
            arr.pop_back();
            mp.erase(val);
            return true;
        } else 
            return false;
    }
    
    int getRandom() {
        int n = arr.size();
        // double perc = (double)rand() / RAND_MAX;
        // int ind = (n - 1) * perc;
        int base = RAND_MAX / n;
        auto it = arr.begin() + rand() / base;
        return *it;
    }
private:
    unordered_map<int,int> mp;
    vector<int> arr;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */