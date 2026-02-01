class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        z = 0
        while z < n and nums[z] < 0:
            z += 1
        res = []
        l, r = z - 1, z
        while l >= 0 and r < n:
            if abs(nums[l]) <= nums[r]:
                res.append(nums[l] * nums[l])
                l -= 1
            else:
                res.append(nums[r] * nums[r])
                r += 1

        while l >= 0:
            res.append(nums[l] * nums[l])
            l -= 1
        while r < n:
            res.append(nums[r] * nums[r])
            r += 1
        return res
