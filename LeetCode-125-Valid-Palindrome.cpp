#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while(i <= j) {
            if(!isalpha(s[i]) && !isdigit(s[i])) i++;
            else if(!isalpha(s[j]) && !isdigit(s[j])) j--;
            else if(tolower(s[i]) != tolower(s[j]))
                return false;
            else i++, j--;
        }
        return true;
    }
};

int main() {
    string str = "0P";
    auto ans = Solution().isPalindrome(str);
    cout << ans << endl;
}