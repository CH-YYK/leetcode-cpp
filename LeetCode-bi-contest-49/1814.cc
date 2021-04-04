#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int countNicePairs(vector<int> &nums) {
    // unordered_map<int, unordered_set<int>> hashtable;
    map<vector<int>, unordered_set<int>> hashtable;
    int res = 0;
    for(int& num : nums) {
      vector<int> hash_ = hash(num);
      auto it = hashtable.lower_bound(hash_);
      if(it != hashtable.end()) {
        if(it->first.size() == hash_.size() && it->first == hash_) {
          res += it->second.size();
          it->second.insert(num);
        } else if(all_zeros(it->first) && all_zeros(hash_)) {
          res += it->second.size();
          it->second.insert(num);
        }
      } else
        hashtable[hash_].insert(hash_);
    }
    return res;
  }
private:
  vector<int> hash(int n) {  // convert num to its key (a,b,c,d) -> (a-d, b-c)
    vector<int> buff;
    vector<int> res;
    while(n) {
      buff.push_back(n % 10);
      n /= 10;
    }
    int l = 0, r = buff.size() - 1;
    while(l <= r) {
      res.push_back(buff[l] - buff[r]);
      ++l, --r;
    }
    return res;
  }

  bool all_zeros(vector<int>& nums) {
    bool is_zeros = true;
    for(int& num : nums) is_zeros &= num == 0;
    return is_zeros;
  }
};
