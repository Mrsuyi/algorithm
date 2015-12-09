#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>

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
	ListNode* reverseBetween(ListNode* head, int m, int n)
	{
		if (!head && !head->next) return head;

		ListNode* ret = new ListNode(0);
		ret->next = head;

		ListNode* _m = ret;

		int mov = m - 1;
		while (mov--)
		{
			_m = _m->next;
		}

		ListNode* pre = _m->next;
		ListNode* i = pre->next;

		int cnt = n - m;
		while (cnt--)
		{
			ListNode* tmp = i->next;
			i->next = pre;
			pre = i;
			i = tmp;
		}

		_m->next->next = i;
		_m->next = pre;

		return ret->next;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}