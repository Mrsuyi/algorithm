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
	ListNode* rotateRight(ListNode* head, int k)
	{
		if (!head || !head->next || k == 0) return head;

		ListNode* r = head;
		ListNode* l = head;

		int steps = k;
		while (steps && r->next)
		{
			r = r->next;
			steps--;
		}
		if (steps > 0)
		{
			return rotateRight(head, k % (k - steps + 1));
		}
		while (r->next)
		{
			r = r->next;
			l = l->next;
		}
		r->next = head;
		head = l->next;
		l->next = NULL;

		return head;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}