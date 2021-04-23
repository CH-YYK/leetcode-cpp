class Solution {
public:
  bool checkIfPangram(string sentence) {
    int res = 0;
    for (char c : sentence) {
      if (res & 1 << (c - 'a'))
        continue;
      else
        res |= 1 << (c - 'a');
    }
    return res + 1 == 1 << 26;
  }
};
