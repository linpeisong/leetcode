class Solution
{
public:
    // 用除法取模来反转数字
    int reverse(int x)
    {
        int result = 0;
        while (x != 0)
        {
            // 个位数
            int pop_num = x % 10;
            x = x / 10;

            // [−2^31,  2^31 − 1]，题目要求int32最大整数。2147483648，则正数个位要小于7，负数个位要大于-8
            // 如果已经超过INT_MAX/10，则加上后面的pop_num位之后肯定超。或者如果目前等于INT_MAX/10，则需要小于INT_MAX % 10的个位数
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop_num > INT_MAX % 10))
                return 0;
            //负数的情况
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop_num < INT_MIN % 10))
                return 0;
            result = result * 10 + pop_num;
        }
        return result;
    }
};
