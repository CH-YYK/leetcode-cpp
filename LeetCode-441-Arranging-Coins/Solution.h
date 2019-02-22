#include <math.h>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        long i = 0;
        while(i * (i+1)/2 <= n) i++;
        return (int)(i - 1);
    }
};