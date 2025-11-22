class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        window = set()

        for i in range(len(nums)):
            # Keep window size ≤ k
            if i > k:
                window.remove(nums[i - k - 1])

            # If duplicate exists in window, return True
            if nums[i] in window:
                return True

            window.add(nums[i])

        return False
