#include <vector>

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        // Use vectors
        std::vector<int> res;

        // retrieve all digits in integer
        while(x > 0){
            res.push_back(x % 10);
            x /= 10;
        }

        // test palindrome
        int i = 0, j = res.size()-1;
        while(i < j){
            if(res[i] != res[j]) return false;
            else i++; j--;
        }
        return true;
    }
};