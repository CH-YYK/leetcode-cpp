#include <string>

using namespace std;

class Solution2 {
public:
    bool isSubsequence(string s, string t) {
        int i_s = 0;
        for (char i_t : t) {
            if (i_s == s.size()) return true;
            if (s[i_s] == i_t) i_s++;
        }
        return i_s == s.size();
    }
};