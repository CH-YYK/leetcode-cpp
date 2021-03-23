class Solution {
public:
  int countPairs(vector<int> &nums, int low, int high) {
    int res = 0;
    for (int i = 0; i < nums.size(); ++i)
      for (int j = i + 1; j < nums.size(); ++j)
        if (low <= (nums[i] ^ nums[j]) && (nums[i] ^ nums[j]) <= high)
          res++;
    return res;
  }
};
