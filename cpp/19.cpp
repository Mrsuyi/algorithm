#include <iostream>
#include <vector>
#include <string>

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
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode* ret = new ListNode(0);
		ret->next = head;
		ListNode* r = ret;
		ListNode* l = ret;

		while (n--)
		{
			r = r->next;
		}
		while (r->next)
		{
			r = r->next;
			l = l->next;
		}

		l->next = l->next->next;
		return ret->next;
	}
};

int main()
{
	while (getchar());

	return 0;
}