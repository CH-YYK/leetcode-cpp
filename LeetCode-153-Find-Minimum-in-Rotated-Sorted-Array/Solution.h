#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) return NULL;
        if(nums.size() == 1) return nums.front();

        for(int i = 1; i < nums.size(); i++)
            if(nums[i] < nums[i-1]) return nums[i];
        return nums.front();
    }
};