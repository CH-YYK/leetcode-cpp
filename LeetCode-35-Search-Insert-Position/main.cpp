#include <iostream>
#include "Solution.h"

int main() {
    std::vector<int> nums = {1, 2, 5, 6};
    int target = 5;
    int ans = Solution().searchInsert(nums, target);
    printf("The answer is : %d", ans);
    return 0;
}