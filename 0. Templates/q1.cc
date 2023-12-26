#include <vector>
#include <string>

using namespace std;

int countNumWays(string& s, int k) {
    int n = s.size();
    int ans = 0;
    for(int i = 0; i < n - k; ++i) {
        string ptn = s.substr(i, k);
        string revptn = ptn;
        reverse(revptn.begin(), revptn.end());
        if(revptn < ptn) ans++;
    }
    return ans;
}