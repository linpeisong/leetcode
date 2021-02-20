class Solution
{
public:
    bool isPalindrome(int x)
    {
        // 负数和0结尾（不包括0）的是false
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }

        // 除10取余，不需要全部反转判断相等。只要反转一半判断即可，并且也可以避免反转全部导致int溢出的问题
        int reverseNum = 0;
        // 反转一半的判断条件，可以是当反转得到的数比x还大的
        while (x > reverseNum)
        {
            reverseNum = reverseNum * 10 + x % 10;
            x /= 10;
        }

        // !!! 这里还有一个注意点，奇数位的数会多出来一位。比如12321，x = 12，reverseNum = 123，要除去最后的个位

        // 简写为一句return
        return (x == reverseNum || x == reverseNum / 10);
        /*
        if (x == reverseNum || x == reverseNum / 10)
        {
            return true;
        }
        else
        {
            return false;
        }
        */
    }
};
