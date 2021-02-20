#!/usr/bin/python2.7
# -*- coding: utf-8 -*-

class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0

        rear_index = 0
        front_index = 1
        while front_index < len(nums):
            # 这里会出现rear_index=front_index 的情况，这个时候把front_index往后挪一位即可
            if nums[front_index] == nums[rear_index]:
                front_index+=1
            else:
                # 指针加1之后，替换到num
                rear_index+=1
                nums[rear_index] = nums[front_index]
                # 减少遍历次数
                if rear_index == front_index:
                    front_index+=1

        return rear_index + 1


if __name__ == "__main__":
    s = Solution()
    l = [0,0,1,1,1,2,2,3,3,4]
    print(s.removeDuplicates(l))
