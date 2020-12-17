#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
    int l = lower, r = upper;
    vector<string> res;

    for(int num : nums) {
      if(l < num) res.push_back(format(l, num-1));
      l = num + 1;
    }
    if(l <= r) 
      res.push_back(format(l, r));
    return res;
  }
private:
  string format(int l, int r) {
    if(l == r) return to_string(l);
    return to_string(l) + "->" + to_string(r);
  }
};

