class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {

        if (nums.size() == 0) return 0;

        int rear_index = 0, front_index = 0;

        while (front_index < nums.size()) {
            // 这里是反向思考，考虑不想等的情况下尾指针的移动，并且需要做覆盖
            if (nums[front_index] != val) {
                // 这里不相等的情况下覆盖，考虑一种front_index=rear_index因此不受影响
                nums[rear_index] = nums[front_index];
                rear_index++;
            }
            front_index++;
        }

        return rear_index;
    }
};