/*
You are given a sorted without any duplicate integer array, can you write code to tell me what is the Nth missing integer.

For example original array:[2,4,7,8,9,15], missing array: [3,5,6,10,11,12,13,14]. From 1point 3acres bbs
the 1st missing integer is 3,. 1point3acres
the 2nd missing integer is 5,. From 1point 3acres bbs
the 3rd missing integer is 6
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {

    // best way to be inclusive 
public:
    int findKth(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while(left + 1 < right) {
            int mid = (left + right) / 2;
            int missed_nums = nums[mid] - nums[left] - (mid - left);

            if(k > missed_nums) 
                left = mid, k-= missed_nums;
            else
                right = mid;
        }
        return nums[left] + k;
    }
};

int main() {
    vector<int> nums = {2, 4, 7, 8, 9, 15};
    int k = 2;
    int ans = Solution().findKth(nums, k);
    cout << "The answer is " << ans;
};