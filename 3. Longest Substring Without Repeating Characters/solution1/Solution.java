import java.util.HashMap;

class Solution {
  public int lengthOfLongestSubstring(String s) {
    HashMap<Character, Integer> charMap = new HashMap();
    int l = 0, maxLen = 1;
    for (int r = 0; r < s.length(); r++) {
      if (charMap.containsKey(s.charAt(r))) {
        maxLen = Math.max(maxLen, r - l);
        int nextL = charMap.get(s.charAt(r)) + 1;
        while (l < nextL) {
            charMap.remove(s.charAt(l));
            l++;
        }
      }
      charMap.put(s.charAt(r), r);
    }
    // Always check the last substring till the end.
    return s.length() == 0 ? 0 : Math.max(maxLen, s.length() - l);
  }
}