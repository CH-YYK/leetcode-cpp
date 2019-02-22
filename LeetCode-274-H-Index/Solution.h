#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;
        sort(citations.begin(), citations.end(), greater<>());
        for(int i = 0; i < citations.size(); i++){
            if(citations[i] < i+1) return i;
        }
        return (int)citations.size();
   }
};