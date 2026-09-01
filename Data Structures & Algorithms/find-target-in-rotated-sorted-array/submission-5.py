class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums) - 1
        while l < r:
            mid = l + (r - l) // 2
            if nums[mid] > nums[r]:
                l = mid + 1
            else:
                r = mid
        pivot = l
        if target == nums[pivot]:
            return pivot
        if target == nums[0]:
            return 0
        if target == nums[len(nums)-1]:
            return len(nums) - 1
        l = 0; r = -1
        
        if target > nums[0] and target < nums[pivot]:
            l = 0
            r = pivot
        elif target > nums[pivot] and target < nums[len(nums)-1]:
            l = pivot
            r = len(nums) - 1
        while l <= r:
            mid = l + (r - l) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                l = mid + 1
            else:
                r = mid - 1
        return -1