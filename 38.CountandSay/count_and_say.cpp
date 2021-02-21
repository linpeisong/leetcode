class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        if (n == 2) return "11";

        // 思路就是遍历跟计数
        // 用递归
        string previous = countAndSay(n - 1);
        string result = "";
        int count = 1;
        for (int i = 0; i < previous.length(); i++){
            // 这里可以用 i+1，string最后一位是\0，不会判等所以count不会+1，下标停留在前面一位
            if (previous[i] == previous[i+1]) {
                count++;
            }
            else 
            {
                result += to_string(count) + previous[i];
                count = 1;
            }
        }
        return result;
    }
};