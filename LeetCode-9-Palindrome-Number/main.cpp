#include <iostream>
#include "Solution.h"
#include "Solution2.h"
#include "Solution3.h"

int main() {
    int qNum = 12321;
    bool ans = Solution3().isPalindrome(qNum);
    std::cout << ans;
    //if(ans == true) std::cout << "The answer is True";
    //else std::cout << "The answer is False";
    return 0;
}