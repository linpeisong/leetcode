class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """

        is_small_zero = False
        if x < 0:
            num_list = list(str(x))[1:]
            is_small_zero = True
        else:
            num_list = list(str(x))

        num_list.reverse()
        if is_small_zero:
            result = int("".join(num_list)) * -1
        else:
            result = int("".join(num_list))

        import math
        if result < math.pow(2,31) * -1  or result > math.pow(2,31)-1:
            return 0
        else:
            return result

if __name__ == "__main__":
    s = Solution()
    x = -1234
    print(s.reverse(x))

