#include <iostream>
#include <vector>
#include "Solution.h"

int main() {
    std::vector<int> nums = {1, 1, 1, 0, 1, 1, 0, 1};
    int ans = Solution().findMaxConsecutiveOnes(nums);
    std::cout << ans << "\n";
    return 0;
}