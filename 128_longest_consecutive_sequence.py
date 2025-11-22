class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        num_set = set(nums)
        longest = 0

        for n in num_set:
            # start of a sequence → only if (n-1) doesn't exist
            if n - 1 not in num_set:
                current = n
                length = 1

                # count forward sequence
                while current + 1 in num_set:
                    current += 1
                    length += 1

                longest = max(longest, length)

        return longest
