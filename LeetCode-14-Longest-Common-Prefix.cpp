#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if(strs.size() == 0) return res;
        for(int c = 0; c < strs[0].size(); c++) {
            char ch = strs[0][c];
            for(int i = 0; i < strs.size(); i++) {
                if(strs[i].size() > c && strs[i][c] == ch) continue;
                else return res;
            }
            res += ch;
        }
        return res;
    }
};