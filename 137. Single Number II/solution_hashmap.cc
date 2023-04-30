#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    unordered_map<int,int> m;
    for(int num : nums) 
      m[num]++;
    for(auto& p : m)
      if(p.second == 1) return p.first;
    return -1;
  }
};
