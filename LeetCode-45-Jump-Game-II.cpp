#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        return helper(nums, 0);
    }

    int helper(vector<int>& nums, int i) {
        if(i >= nums.size() - 1) return 0;
        vector<int> res;
        for(int j = 0; j <= nums[i]; j++)
            res.push_back(helper(nums, i + nums[i]));
        if(!res.empty()) 
            return 1 + *min(res.begin(), res.end());
        else return INT_MAX;
    }   
};

class Solution2 {
public:
    int jump(vector<int>& nums) {
        unordered_map<int, int> memo;
        return helper(nums, 0, memo);
    }

    int helper(vector<int>& nums, int i, unordered_map<int, int>& memo) {
        if(i >= nums.size() - 1) return 0;
        if(memo.count(i)) return memo[i];
        vector<int> res;
        for(int j = 1; j <= nums[i]; j++) res.push_back(helper(nums, i+j, memo));
        if(!res.empty()) return 1 + *min(res.begin(), res.end());
        else return INT_MAX;
    }
};

class Solution3 {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        for(int j = nums.size()-2; j >= 0; j--){
            if(j + nums[j] >= nums.size()-1) dp[j] = 1;
            else{
                vector<int> res(nums.begin() + j + 1, nums.begin() + j + nums[j] + 1);
                int minVal = *min(res.begin(), res.end());
                dp[j] = !res.empty() && minVal < INT_MAX ? minVal + 1 : INT_MAX;
            }
        }
        return dp[0];
    }
};


int main() {
    vector<int> nums = {1,2,34};
    int minVal = *min(nums.begin(), nums.end());
    cout << minVal << "\n";
    return 0;
}
