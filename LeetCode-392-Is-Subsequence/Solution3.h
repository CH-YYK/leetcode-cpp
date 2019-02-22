class Solution3 {
public:
    bool isSubsequence(string s, string t) {
        int i_s = 0, m = (int)s.size(), n = (int)t.size();
        for (int i_t = 0; i_s < m && i_t < n; i_t++) {
            if(s[i_s] == t[i_t]) i_s++;
        }
        return i_s == s.size();
    }
};