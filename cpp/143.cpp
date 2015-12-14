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
	void reorderList(ListNode* head)
	{
		if (!head) return;

		ListNode *slow = head, *fast = head;
		
		// find mid
		while (fast->next && fast->next->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}

		// reverse last half
		ListNode* pre = NULL;
		ListNode* i = slow->next;
		while (i)
		{
			ListNode* tmp = i->next;
			i->next = pre;
			pre = i;
			i = tmp;
		}

		// traverse
		ListNode* l = head;
		ListNode* r = pre;

		while (l)
		{
			ListNode* tmp = l->next;
			l->next = r;
			l = tmp;

			if (!r) break;

			tmp = r->next;
			r->next = l;
			r = tmp;
		}
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}