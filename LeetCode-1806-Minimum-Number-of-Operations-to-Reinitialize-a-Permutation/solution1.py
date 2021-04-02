class Solution:
    def reinitializePermutation(self, n: int) -> int:
        step = 0
        perm = list(range(n))
        arr = perm[:]
        for i in range(1000):
            back = True
            for j in range(n-1, -1, -1):
                if j % 2 == 0:
                  arr[j] = perm[j//2]
                elif j % 2 == 1:
                  arr[j] = perm[(n+ j - 1) // 2]
                back = back and (arr[j] == j)
            print(arr)
            if back:
                return i + 1
            perm = arr[:]
