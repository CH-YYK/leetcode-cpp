#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

/* Use monotune stack
 */
class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> s;
    int n = nums2.size();
    unordered_map<int, int> map;
    vector<int> res;

    for(int i = n-1; i >= 0; --i) {
      if(s.empty()) s.push(nums2[i]);
      else {
        while(!s.empty() && nums2[i] >= s.top())
          s.pop();
        if(!s.empty()) map[nums2[i]] = s.top();
        s.push(nums2[i]);
      }
    }

    for(int i : nums1)
      if(map.count(i)) res.push_back(map[i]);
      else res.push_back(-1);
    return res;
  }
};
