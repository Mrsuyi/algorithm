#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	bool isPalindrome(ListNode* head)
	{
		if (!head || !head->next) return true;

		ListNode *fast = head, *slow = head;
		
		// find mid
		while (fast->next && fast->next->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}

		// reverse last half
		ListNode* pre = NULL;
		ListNode* cur = slow->next;
		while (cur)
		{
			ListNode* nxt = cur->next;
			cur->next = pre;
			pre = cur;
			cur = nxt;
		}

		// compare
		ListNode* tail = pre;
		while (tail && tail->val == head->val)
		{
			head = head->next;
			tail = tail->next;
		}

		return tail == NULL;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}