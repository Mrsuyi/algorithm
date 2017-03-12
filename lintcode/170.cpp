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
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        if (!head) return nullptr;
        
        int l = 0;
        ListNode* cur = head;
        while (cur)
        {
            cur = cur->next;
            ++l;
        }
        k = k % l;
        if (k == 0) return head;

        cur = head;
        while (k--) cur = cur->next;
        ListNode* pre = head;
        while (cur->next)
        {
            cur = cur->next;
            pre = pre->next;
        }
        ListNode* res = pre->next;
        pre->next = nullptr;
        cur->next = head;
        return res;
    }
};