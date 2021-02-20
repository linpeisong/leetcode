
// 暴力遍历，时间复杂度O(n2)
class Solution1
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

// 用hash表，降不匹配的存起来。则只需要遍历一次
class Solution1
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unorder_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end())
            {
                return {it->second, i};
            }
            else
            {
                hashtable[nums[i]] = i;
            }
        }
        return {};
    }
};
