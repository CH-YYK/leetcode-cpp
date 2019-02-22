// Build palindrome and test
class Solution3 {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int Sum = 0, xCopy = x;
        while (x != 0) {
            Sum = 10 * Sum + x % 10;
            x /= 10;
        }
        return xCopy == Sum;
    }
};