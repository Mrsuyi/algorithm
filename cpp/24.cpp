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
	ListNode* swapPairs(ListNode* head)
	{
		ListNode* ret = new ListNode(0);
		ret->next = head;
		ListNode* pre = ret;

		while (pre->next && pre->next->next)
		{
			ListNode* l = pre->next;
			ListNode* r = pre->next->next;
			ListNode* nxt = r->next;

			pre->next = r;
			r->next = l;
			l->next = nxt;
			pre = l;
		}
		return ret->next;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}