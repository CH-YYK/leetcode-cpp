#include <iostream>
#include <vector>
#include "Solution.h"
#include "Solution2.h"

int main() {
    std::vector<int> nums{1, 2, 3, 4, 5};
    for(int i:nums) std::cout << " " << i;
    std::cout << "\n";

    int ans = Solution2().binarySearch(nums, 5);
    std::cout << "Answer is " << ans << std::endl;
    return 0;
}