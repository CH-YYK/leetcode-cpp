#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int i = n-k, j = n-1;
        while(i <= j) swap(nums[i++], nums[j--]);
        i = 0, j = n-k-1;
        while(i<=j) swap(nums[i++], nums[j--]);
        i = 0, j = n - 1;
        while(i <= j) swap(nums[i++], nums[j--]);
    }
};