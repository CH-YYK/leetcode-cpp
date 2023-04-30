#include <string>
#include <vector>

using namespace std;

struct stringCompare {
    bool operator()(string &lhs, string &rhs){
        return stol(lhs + rhs) > stol(lhs + rhs);
    }
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> nums_str;
        for(int i:nums) nums_str.push_back(to_string(i));
        sort(nums_str.begin(), nums_str.end(), stringCompare());

        string res;
        for(int i = 0; i < nums_str.size()-1; i++){
            if(res.size() == 0 && nums_str[i] == "0") continue;
            else res += nums_str[i];
        }
        res += nums_str.back();
        return res;
    }
};