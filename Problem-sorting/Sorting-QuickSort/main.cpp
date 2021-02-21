#include <iostream>
#include "Solution.h"
#include <string>
#include "Solution2.h"

int main() {
    std::vector<int> nums{2,3,4,5,1,34,5};
    for(int i:nums) std::cout << i << " ";
    std::cout << "\n";

    Solution2().quickSort(nums);
    for(int i:nums) std::cout << i << " ";
    std::cout << "\n";
    return 0;
}