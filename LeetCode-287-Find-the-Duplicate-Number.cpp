#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    // sorting though not allowed
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 1;
        while(i < nums.size()) {
            if(nums[i] == nums[i-1]) 
                return nums[i];
            i++;
        }
        return 0;
    }
};

class Solution2 {
    // binary search
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size()-1;
        while(low < high){
            int mid = (low + high) / 2;
            int count = 0;
            for(int i = 0; i < nums.size(); i++) 
                if(nums[i] <= mid) count++;
            if(count == mid) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};

class Solution3 {
    // change values wrt index,
    // regard the nums as indices, keep reversing numbers in the array
    // when a number is already reversed means that the index has emerged before
    // O(N), O(1) but has modified array.
public:
    int findDuplicate(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[abs(nums[i])] > 0) 
                nums[abs(nums[i])] *= -1;
            else
                return abs(nums[i]);
        }
        return 0;
    }
};

class Solution4 {
    // using XOR, XOR array and [1:n], when repeating number only has two duplicates.
public:
    int findDuplicate(vector<int> &nums) {
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++) res ^= nums[i];
        for(int i = 1; i < nums.size(); i++) res ^= i;
        return res;
    }
};


int main() {
    vector<int> nums({1, 3, 4, 2, 2});
    int ans = Solution4().findDuplicate(nums);
    cout << ans << "\n";
    return 0;
}