#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 1. Find the Max k that make nums[k] < nums[k+1],
        //    if there's no such k, reverse the whole vector
        // 2. Find Max l that make nums[l] > nums[k];
        // 3. Swap values at k and l;
        // 4. reverse the rest of nums at nums[k+1:];

        int k = (int)nums.size() - 1;
        while(k > 0 && nums[k] <= nums[k-1]) k--;
        if(k == 0) reverse(nums.begin(), nums.end());
        else{
            k--;
            int l = (int)nums.size() - 1;
            while(l > k && nums[l] <= nums[k]) l--;
            swap(nums[k], nums[l]);
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};