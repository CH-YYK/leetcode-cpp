class Solution:
    def maxNiceDivisors(self, primeFactors: int) -> int:
        return max([i for i in range(1, primeFactors)], key=lambda x: self.decode(primeFactors, i))
        return max([self.decode(primeFactors, i) for i in range(1, primeFactors+1)]) % (10**9 + 7)

    def decode(self, num, n):
        if num == 0:
            return 1
        return self.decode(num - num // n, n - 1) * num // n
