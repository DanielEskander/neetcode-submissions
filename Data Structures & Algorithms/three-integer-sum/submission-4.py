class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3:
            return []

        nums.sort()
        res = []
        for i in range(len(nums) - 2):
            if nums[i] > 0:
                break
            if i > 0 and nums[i] == nums[i-1]:
                continue
            target = nums[i] * -1
            j = i + 1
            k = len(nums) - 1
            while j < k:
                if nums[j] + nums[k] == target:
                    res.append([nums[i], nums[j], nums[k]])
                    k -= 1
                    j += 1
                    while j < k and nums[j] == nums[j-1]:
                        j += 1
                elif nums[j] + nums[k] < target:
                    j += 1
                else:
                    k -= 1
        return res
