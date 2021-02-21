class Solution {
public:
    int strStr(string haystack, string needle) {
        // 直接用find解决
        if (needle.size()==0) return 0;
        int pos = haystack.find(needle);
        return pos;
    }
};