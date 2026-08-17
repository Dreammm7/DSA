class Solution:
    def minimumSize(self, nums: list[int], maxOperations: int) -> int:
        low, high = 1, max(nums)
        
        def can_achieve_penalty(target_size):
            operations = 0
            for balls in nums:
                if balls > target_size:
                    operations += (balls - 1) // target_size
            return operations <= maxOperations

        while low < high:
            mid = (low + high) // 2
            if can_achieve_penalty(mid):
                high = mid
            else:
                low = mid + 1
                
        return low
      