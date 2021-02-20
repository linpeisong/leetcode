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
// 递归思路
class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } 
        else if (l2 == nullptr) {
            return l1;
        }
        else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else if (l2->val < l1->val) {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
// 迭代思路：用一个哨兵指针，不断调整它的next，直到指向l1或者l2的尾部
class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // new一个空节点用于连接prev哨兵
        ListNode *prehead = new ListNode(-1);
        ListNode *prev = prehead;

        while (l1 != nullptr && l2 != nullptr) {
            if(l1->val <= l2->val) {
                prev->next = l1;
                l1 = l1->next;
            }
            else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }

        // l1跟l2有一个为空
        if (l1 == nullptr) {
            prev->next = l2;
        } 
        else {
            prev->next = l1;
        }

        // prevhead连接在哨兵的头部ListNode作为返回
        return prevhead->next;


    }
};
