#include <iostream>
#include <string>
#include "Solution.h"
#include "Solution2.h"
#include "Solution3.h"
#include "Solution4.h"
#include <vector>

int main() {
    std::string str1("bbbab");
    int ans = Solution2().longestPalindromeSubseq(str1);
    std::cout << "The answer is " << ans << "\n";
    /* for(auto row:memo) {
           for (auto col:row)
                std::cout << " " << col;
        std::cout << "\n";
    }
     */
    return 0;
}