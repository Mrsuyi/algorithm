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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		ListNode* ret = new ListNode(0);
		ListNode* i = ret;

		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				i->next = l1;
				l1 = l1->next;
			}
			else
			{
				i->next = l2;
				l2 = l2->next;
			}
			i = i->next;
		}
		i->next = l1 ? l1 : l2;

		return ret->next;
	}
};

int main()
{
	while (getchar());

	return 0;
}