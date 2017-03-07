#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
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
	ListNode* reverseKGroup(ListNode* head, int k)
	{
		if (k == 1) return head;

		ListNode* ret = new ListNode(0);
		ret->next = head;
		ListNode* pre = ret;
		while (pre)
		{
			ListNode* i = pre->next;
			int cnt = k;
			while (cnt && i) { i = i->next; cnt--; }
			if (cnt) break;

			pre = rev(pre, i);
		}

		return ret->next;
	}

	ListNode* rev(ListNode* pre, ListNode* nxt)
	{
		ListNode* l = pre->next;
		ListNode* r = pre->next->next;
		while (r != nxt)
		{
			ListNode* tmp = r->next;
			r->next = l;
			l = r;
			r = tmp;
		}
		nxt = pre->next;
		nxt->next = r;
		pre->next = l;
		return nxt;
	}
};

int main()
{
	int nums[5] = { 1,2,3,4,5 };
	ListNode* head = new ListNode(0);
	ListNode* i = head;
	for (auto n : nums)
	{
		i->next = new ListNode(n);
		i = i->next;
	}

	Solution solution;
	solution.reverseKGroup(head->next, 2);

	while (getchar());

	return 0;
}