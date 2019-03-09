#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int l = p.size();
        vector<int> res;
        vector<int> sString(26, 0);
        vector<int> pString(26, 0);
        for(char &i : p) 
            pString[i - 'a']++;
        
        for(int i = 0; i < s.size(); i++) {
            if(i >= l) sString[s[i-l] - 'a']--;
            sString[s[i]-'a']++;
            if(sString == pString) res.push_back(i-l+1);
        }
        return res;
    }
};