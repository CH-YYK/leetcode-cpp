// Hello, this is a CPP leetcode snippet.

#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <functional>
#include <climits>
#include <set>
#include <map>
#include <sstream>

using namespace std;

/*		
ios_base::sync_with_stdio(0); 
cin.tie(NULL);
*/

class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        // find L, suppose D1 < D2
        // numbers can be categorized into 4 groups
        // 1. multiplier of LCM(D1, D2), dropped, G1
        // 2. multiplier of D1 not D2, in S2, G2
        // 3. multiplier of D2 not D1, in S1, G3
        // 4. not multiplier of both D1 and D2, freely placed, G4
        //
        // G4 = L - G1 - G2 - G
        // taget: find L, such that 
        // 
        // L - G1 >= C1 + C2 
        // G2  + G3 + G4 >= C1 + C2
        long lcm = (long)divisor1 / __gcd(divisor1, divisor2) * divisor2;
        long l = 1, r = INT_MAX;

        while(l < r) {
        	long m = (l + r) / 2;
        	long G1 = 0, G2 = 0, G3 = 0, G4 = 0;
        	// find number of LCM
        	G1 = m / lcm;
        	G2 = m / divisor1 - G1;
        	G3 = m / divisor2 - G1;
            G4 = m - (G1 + G2 + G3);

            long S1 = min(G3 + G4, (long)uniqueCnt1);
            long S2 = G2 + G4 - max((long)uniqueCnt1 - G3, 0l);
            // check-2
            if(S2 >= uniqueCnt2 && S1 >= uniqueCnt1)
            	r = m;
            else l = m + 1;
        }
        return l;
    }
};