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
	ListNode* partition(ListNode* head, int x)
	{
		ListNode* l_head = new ListNode(0);
		ListNode* r_head = new ListNode(0);

		ListNode* l = l_head;
		ListNode* r = r_head;

		while (head)
		{
			if (head->val < x)
			{
				l->next = new ListNode(head->val);
				l = l->next;
			}
			else
			{
				r->next = new ListNode(head->val);
				r = r->next;
			}

			head = head->next;
		}

		l->next = r_head->next;

		return l_head->next;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}