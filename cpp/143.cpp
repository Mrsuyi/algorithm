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
			ListNode* tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}

		ListNode* l = head;
		ListNode* r = pre;
		while (r)
		{
			ListNode* tmpl = l->next;
			ListNode* tmpr = r->next;
			l->next = r;
			r->next = tmpl;
			l = tmpl;
			r = tmpr;
		}
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}