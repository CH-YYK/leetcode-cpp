#include <math.h>

using namespace std;

class Solution2 {
public:
    int arrangeCoins(int n) {
        if(n <= 1) return n;
        long l = 1, r = (long)n+1;
        while(l < r) {
            long m = (l+r) / 2 + 1;
            if(m * (m + 1) / 2 == n)
                return (int)m;
            else if(m * (m+1) / 2 < n)
                l = m;
            else
                r = m-1;
        }
        return (int)l;
    }
};