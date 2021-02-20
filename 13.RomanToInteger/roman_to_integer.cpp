class Solution1
{
public:
    int romanToInt(string s)
    {
        map<char, int> luomab = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};

        int result = 0;
        int temp = 0;
        for (int i = 0; i < s.length(); i++) {
            int num = luomab[s[i]];
            if (num >= temp) {
                result += num;
            }
            else {
                result = result + num - 2 * temp;
            }
            temp = num;
        }
        return result;
    }
};

class Solution2
{
public:
    int romanToInt(string s)
    {
        int result = 0;
        map<char, int> luomab = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}}; //初始化哈希表
        for (int i = 0; i < s.length(); i++)
        {
            // 因为string最后一位是\0，取到空值。map默认范围一个int 0，因此不会越界、报错。
            if (luomab[s[i]] < luomab[s[i + 1]])
                result -= luomab[s[i]];
            else
            {
                result += luomab[s[i]];
            }
        }
        return result;
    }
};