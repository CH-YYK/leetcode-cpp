#include <iostream>
#include "Solution.h"
#include <vector>

int main() {
    std::vector<int> nums = {1, 2, 3, 3, 4};
    int ans = Solution().removeDuplicates(nums);
    printf("The answer is : %d", ans);
    return 0;
}