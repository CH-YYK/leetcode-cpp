#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // recursive solution with reference to string as argument
        return helper_recur(s, t, 0, 0);
    }

    bool helper_recur(string &s, string &t, int index_s, int index_t){
        if(index_t == t.size() && index_s < s.size()) return false;
        if(index_s == s.size()) return true;
        if(s[index_s] == t[index_t])
            return helper_recur(s, t, index_s + 1, index_t + 1);
        else
            return helper_recur(s, t, index_s, index_t + 1);
    }
};