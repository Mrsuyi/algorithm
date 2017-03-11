/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: void
     */
    void reorderList(ListNode *head) {
        // write your code here
        if (!head) return;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* pre = nullptr;
        ListNode* cur = slow->next;
        slow->next = nullptr;
        while (cur)
        {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        ListNode* res = new ListNode(0);
        ListNode* l = head;
        ListNode* r = pre;
        pre = res;
        while (l)
        {
            pre->next = l;
            pre = pre->next;
            l = l->next;
            std::swap(l, r);
        }
    }
};