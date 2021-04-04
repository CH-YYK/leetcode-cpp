class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        res = 0
        for i in range(0, len(nums)-1):
            for j in range(i+1, len(nums)):
                if nums[i] + self.rev(nums[j]) == nums[j] + self.rev(nums[i]):
                    print(i, j)
                    res += 1
        return res

    def rev(self, num):
        res = 0
        lis = []
        while num:
            lis.append(num % 10)
            num //= 10

        for i in range(len(lis)-1, -1, -1):
            res += lis[i]
            res *= 10
        return res
