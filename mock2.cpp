#include <vector>
#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

class Solution {
    // brute force way
public:
    int findMinSumMax(vector<int>& nums) {
        int minSumMax = nums[0] * nums[0];
        for(int i = 0; i < nums.size(); i++) {
            int sum = nums[i];
            int min = nums[i];
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[j] == 0) break;
                sum += nums[j];
                if(nums[j] < min) min = nums[j];
                if(sum * min > minSumMax) minSumMax = sum * min;
            }
        }
        return minSumMax;
    }
};

int main() {
    int N;
    scanf("%d", &N);
    vector<int> nums;
    for(int i = 0; i < N; ++i){
        int n;
        scanf("%d", &n);
        nums.push_back(n);
    }
    // for(auto i: nums) cout << i << " ";
    int ans = Solution().findMinSumMax(nums);
    cout << ans << "\n";
	return 0;
}