class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0) {
            return 0;
        }

        int rear_index = 0, front_index = 1;
        while (front_index < nums.size()) {
            if (nums[front_index] == nums[rear_index]) {
                front_index++;
            }
            else
            {
                rear_index++;
                nums[rear_index] = nums[front_index];
                if (rear_index == front_index) {
                    front_index++;
                }
            }
        }

        return rear_index + 1;

    }
};