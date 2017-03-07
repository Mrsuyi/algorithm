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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		if (headA == NULL || headB == NULL) return NULL;

		ListNode *ia = headA, *ib = headB;
		ListNode *ea, *eb;

		while (true)
		{
			if (ia == ib) return ia;

			if (ia->next == NULL)
			{
				ea = ia;
				ia = headB;
			}
			else
			{
				ia = ia->next;
			}
			if (ib->next == NULL)
			{
				eb = ib;
				ib = headA;
			}
			else
			{
				ib = ib->next;
			}
			if (ea != NULL && eb != NULL && ea != eb) return NULL;
		}
	}
};

int main()
{

	while (getchar());

	return 0;
}