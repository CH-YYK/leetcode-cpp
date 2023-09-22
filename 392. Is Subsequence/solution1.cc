#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // return if s is a subsequence of t.
        // -> if s can be created by deleting chars from t
        // 
        // using two pointers
        //   if any s[i] can have a match by a t[j]
        int i = 0;
        for(int j = 0; j < t.size(); ++j) {
            if(i < s.size() && s[i] == t[j]) 
                i++;
        }
        return i == s.size();
    }
};
