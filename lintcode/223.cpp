/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head a ListNode
     * @return a boolean
     */
    bool isPalindrome(ListNode* head) {
        // Write your code here
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* pre = nullptr;
        ListNode* cur = slow;
        while (cur)
        {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        ListNode* l = head;
        ListNode* r = pre;
        while (l && r)
        {
            if (l->val != r->val)
                return false;
            l = l->next;
            r = r->next;
        }
        return true;
    }
};