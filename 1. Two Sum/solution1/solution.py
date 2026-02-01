class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        resMap = {}
        for i in range(0, nums.size()):
            if target - nums[i] in resMap:
                return [resMap[target - nums[i]], i]
            resMap[nums[i]] = i
        return [0, 0]