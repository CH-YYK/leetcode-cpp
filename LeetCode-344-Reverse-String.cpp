#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size()-1;
        while(i <= j) 
            swap(&s[i++], &s[j--]);
    }

    void swap(char *a, char *b) {
        // pointer a, pointers b
        char tmp = *a;
        *a = *b;
        *b = tmp;
    }
};