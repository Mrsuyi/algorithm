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
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        vector<ListNode*> res(hashTable.size() * 2, nullptr);
        int l = res.size();
        for (ListNode* node : hashTable)
        {
            while (node)
            {
                ListNode* nxt = node->next;

                int pos = (node->val % l + l) % l;
                ListNode** mount = &res[pos];
                while (*mount)
                    mount = &((*mount)->next);
                *mount = node;
                node->next = nullptr;

                node = nxt;
            }
        }
        return res;
    }
};
