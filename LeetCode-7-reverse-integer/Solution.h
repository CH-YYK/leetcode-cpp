#include <math.h>

class Solution {
public:
    int reverse(int x) {
        long int sum = 0;
        double lower = -pow(2, 31), upper = pow(2, 31)-1;
        while(x != 0) {
            sum = sum * 10 + x % 10;
            x /= 10;
        }

        if(sum < -pow(2, 31) || sum > pow(2, 31) - 1) return 0;
        else return (int) sum;
    }
};