class Solution:
    def numDifferentIntegers(self, word: str) -> int:
        word += 'a'
        s = set()
        num = 0
        prev = ''
        for c in word:
            if c.isdigit():
                num = 10 * num + int(c)
            else:
                if num == 0 and prev == '0':
                    s.add(0)
                elif num != 0:
                    s.add(num)
                num = 0
            prev = c
        return len(s)
