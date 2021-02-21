/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == nullptr || head->next == nullptr) return head;

        ListNode* front_pointer = head;
        // 因为是ListNode，只需要一个listnode指定当前的位置不断移动改变next，不需要快慢指针做覆盖来删除元素
        while (front_pointer != nullptr && front_point->next != nullptr) {
            if (front_pointer->val == front_pointer->next->val){
                front_pointer->next = front_pointer->next->next;
            }
            else {
                front_point = front_point->next;
            }
        }
        return head;
    }
};