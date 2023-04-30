/* Minimum operations to make nums1 and nums2 equal
 *
 * Greedily thinking:
 *    - make the smaller sum increase as fast as possible
 *    - make the larger sum decrease as fast as possible
 *
 */

class Solution {
public:
  int minOperations(vector<int>& nums1, vector<int>& nums2) {
    int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
    int sum2 = accumulate(nums2.begin(), nums2.end(), 0);

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    if(sum1 < sum2)
      return helper(nums1, nums2, sum2 - sum1);
    else
      return helper(nums2, nums1, sum1 - sum2);
  }
private:
  int helper(vector<int>& snums, vector<int>& lnums, int diff) {
    int cnt = 0;
    auto sb = snums.begin(), se = snums.end();
    auto lb = lnums.rbegin(), le = lnums.rend();

    while((lb != le || sb != se) && diff > 0) {
      if(lb != le && sb != se)
        if(6 - *sb > *lb - 1)
          diff -= min(6-*sb++, diff);
        else
          diff -= min(*lb++ - 1, diff);
      else if(sb != se)
        diff -= min(diff, 6 - *sb++);
      else if(lb != le)
        diff -= min(diff, *lb++ - 1);
      ++cnt;
    }
    return diff == 0 ? cnt : -1;
  }
};
