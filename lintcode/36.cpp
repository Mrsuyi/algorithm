/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* nm = dummy;
        while (--m) nm = nm->next;
        ListNode* nn = dummy;
        while (--n) nn = nn->next;

        ListNode* end = nn->next->next;
        ListNode* pre = end;
        ListNode* cur = nm->next;
        while (cur != end)
        {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        nm->next = pre;

        return dummy->next;
    }
};
