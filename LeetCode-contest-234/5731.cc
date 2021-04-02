class Solution {
public:
  int numDifferentIntegers(string word) {
    unordered_set<long> s;
    word += 'a';
    long num = 0;
    char prev = 'a';
    for (char c : word) {
      if (isdigit(c)) {
        num = 10 * num + (c - '0');
      } else {
        if (num == 0 && prev == '0')
          s.insert(0);
        else if (num != 0)
          s.insert(num);
        num = 0;
      }
      prev = c;
    }
    return s.size();
  }
};
