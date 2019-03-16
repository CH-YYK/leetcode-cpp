#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map{{0,-1}};
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int t = (k == 0) ? sum : (sum % k);
            if(map.count(t)) {
                if(i - map[t] > 1) return true;
            }
            else map[t] = i;
        }
        return false;
    }
};

int main() {
    vector<int> nums = {23,2,4,6,7};
    int k = 5;
    bool ans = Solution().checkSubarraySum(nums, k);
}