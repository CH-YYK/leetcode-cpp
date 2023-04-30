// Recursion solution without memory

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        return this->Helper(s, 0, (int)s.size()-1);
    }

private:
    int Helper(string s, int i, int j) {
        if(i > j) return 0;
        if(i == j) return 1;
        if(s[i] == s[j]) return 2 + this->Helper(s, i+1, j-1);
        else{
            int l1 = this->Helper(s, i+1, j);
            int l2 = this->Helper(s, i, j-1);
            return l1 > l2 ? l1:l2;
        }
    }
};