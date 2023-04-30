#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxSum = 0, Sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0){
                maxSum = maxSum > Sum ? maxSum : Sum;
                Sum = 0;
            }else{
                Sum += 1;
            }
        }
        return maxSum > Sum ? maxSum : Sum;
    }
};