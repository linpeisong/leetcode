
class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        // 普通解法：把次数，第一次出现的位置跟最后一次出现的位置保存下来
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            // map.count返回0和1表示存不存在
            if (mp.count(nums[i]))
            {
                mp[nums[i]][0]++;
                mp[nums[i]][2] = i;
            }
            else
            {
                mp[nums[i]] = {1, i, i};
            }
        }

        // 再对map做一次遍历
        int maxNum = 0, minLen = 0;
        for (auto &[_, vec] : mp)
        {
            if (maxNum < vec[0])
            {
                maxNum = vec[0];
                minLen = vec[2] - vec[1] + 1;
            }
            // 次数相同的情况下，取小值
            else if (maxNum == vec[0])
            {
                if (minLen > vec[2] - vec[1] + 1)
                {
                    minLen = vec[2] - vec[1] + 1;
                }
            }
        }
        return minLen;
    }
};

// 这里关键在于记录第一次出现的位置，用另外一个dict存距离，那么就可以做到遍历一次
class Solution2
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        int degree = 0, result = 0;
        unordered_map<int, int> count, first_pos;
        for (int i = 0; i < nums.size(); ++i)
        {
            // 保存第一次出现的位置
            if (!first_pos.count(nums[i]))
            {
                first_pos[nums[i]] = i;
            }
            // ++count的写法，一方面把不存在的nums[i]做计数，一方面作为次数去比较degree
            if (++count[nums[i]] > degree) {
                degree = count[nums[i]];
                result = i - first_pos[nums[i]] + 1;
            }
            else if (count[nums[i]] == degree) {
                result = min(result, i - first_pos[nums[i]] + 1);
            }
        }
        return result;
    }
};