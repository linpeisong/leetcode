class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 这里时间复杂度肯定是m+n，都要遍历一次
        // 从后到前遍历nums1，空间负责度下降为1
        int p1 = m - 1, p2 = n - 1, tail = m + n - 1;
        int cur;

        //索引都使用先赋值，再--的方式
        while (0 <= p1 || 0 <= p2) {
            // nums1已经遍历完，cur直接赋值num2，p2--即可
            if (p1 == -1) {
                cur = nums2[p2--];
            }
            else if (p2 == -1) {
                cur = nums1[p1--];
            }
            // 从后往前遍历，赋值大值
            else if (nums1[p1] < nums2[p2]) {
                cur = nums2[p1--];
            }
            else {
                cur = nums1[p2--];
            }
            // 赋值之后tail--往前挪一位
            nums1[tail--] = cur;
        }

    }
};