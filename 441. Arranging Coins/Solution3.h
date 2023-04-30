#include <math.h>

using namespace std;

class Solution3 {
public:
    int arrangeCoins(int n) {
        return (int)floor((sqrt(8 * (double)n + 1) - 1) / 2);
    }
};