class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 因为是前缀子串，可以用string.find。如果是0，则说明找到
        // 配合反向思路，find最长的字符串，不断截短，直到找到。

        // 用第一个string作为基准
        string res = strs.empty() ? "":strs[0];
        for (string s:strs) {
            // 如果找得到，则返回下标0，找不到返回-1，截短最后一个字符进行下一轮find
            // 一次for循环比较两个str，如果没有公共则直接返回
            while(s.find(res) != 0) {
                res = res.substr(0, res.length() - 1);
                // 加个速：如果前面两个都没有公共前缀了，那么直接返回空
                if (res.empty()) {
                    return res;
                }
            }
        }
        return res;

    }
};