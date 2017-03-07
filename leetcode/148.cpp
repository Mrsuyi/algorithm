#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <deque>

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
	ListNode* sortList(ListNode* head)
	{
		if (!head || !head->next) return head;

		ListNode* slow = head;
		ListNode* fast = head;

		// find middle
		while (fast->next && fast->next->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}

		// sort 2 side
		fast = sortList(slow->next);
		slow->next = NULL;
		slow = sortList(head);

		// merge 2 side
		head = new ListNode(0);
		ListNode* i = head;
		while (slow && fast)
		{
			if (slow->val < fast->val)
			{
				i->next = slow;
				slow = slow->next;
			}
			else
			{
				i->next = fast;
				fast = fast->next;
			}
			i = i->next;
		}
		if (fast)
		{ 
			slow = fast;
		}
		while (slow)
		{
			i->next = slow;
			i = i->next;
			slow = slow->next;
		}

		return head->next;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}