Finding substring without repeating characters

Sliding window approach:
1. Maintain a CharMap to track the uniqueness of the chars in Substring.
2. When a char duplicate, moving the l to the position exactly after the duped character.
3. All of the chars in the map are dumped from the CharMap.