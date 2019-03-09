#include <vector>
#include <iostream>
using namespace std;

class Solution {
    // using XOR
public:
    int singleNumber(vector<int>& nums) {
        if(nums.empty()) return 0;
        int base = nums[0];
        for(int i = 1; i < nums.size(); i++) 
            base ^= nums[i];
        return base;
    }
};