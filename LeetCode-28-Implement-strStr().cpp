#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        int m = haystack.size(), n = needle.size();
        for(int i = 0; i <= m-n; i++) {
            if(haystack.substr(i, n) == needle) return i;
        }
        return -1;
    }
};

int main() {
    string res = "fdfdfdf";
    cout << res.substr(0, 3);
    return 0;
}