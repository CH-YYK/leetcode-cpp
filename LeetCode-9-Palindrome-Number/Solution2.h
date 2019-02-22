#include <vector>
#include <math.h>

class Solution2 {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int n = 0, xCopy = x;

        // retrieve the number of digits in x
        while(xCopy > 0){
            xCopy /= 10;
            n++;
        }

        // test palindrome
        // n-1 vs 1, n-2 vs 2.
        int left, right;
        while(x > 0){
            left = x / (int)pow(10, n-1);
            right = x % 10;
            if(left != right) return false;
            else{
                x %= (int)pow(10, n-1);
                x /= 10;
                n -= 2;
            }
        }
        return true;
    }
};