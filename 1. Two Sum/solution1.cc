#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); ++i) {
            if(mp.count(target - nums[i]))
                return {mp[target - nums[i]], i};
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> ans = Solution().twoSum(nums, target);
    return 0;
}