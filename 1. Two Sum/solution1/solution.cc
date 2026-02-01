#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> resMap;
    for (int i = 0; i < nums.size(); ++i) {
      if (resMap.count(target - nums[i])) {
        return {resMap[target - nums[i]], i};
      }
      resMap[nums[i]] = i;
    }
    return {0, 0};
  }
};