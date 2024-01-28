#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>

using namespace std;

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        // find the period between a and b
        // suppose the result is x
        // total number: (x/a + x/b - x/L) is the total amounts of numbers under x
        // find the x that make the expression above <= n as close as possible
        // 
        // Using Binary Search O(nlogn)
        int kMod = 1e9 + 7;
        long L = a / __gcd(a, b) * b;
        long lo = 0;
        long hi = n * min(a, b);
        while(lo < hi) {
            long mi = lo + (hi - lo) / 2;
            if(mi / a + mi / b - mi / L < n) {
                lo = mi + 1;
            } else 
                hi = mi;
        }
        return lo % kMod;
    }
};