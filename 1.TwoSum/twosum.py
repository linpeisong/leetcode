class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        is_valid = False
        for i in xrange(len(nums)):
            num1 = nums[i]
            for j in xrange(len(nums)):
                if j <= i:
                    pass
                else:
                    num2 = nums[j]
                    if num1 + num2 == target:
                        is_valid = True
                        break

            if is_valid:
                return [i, j]


if __name__ == "__main__":
    s = Solution()
    nums = [3,2,4]
    target = 6
    print(s.twoSum(nums, target))

