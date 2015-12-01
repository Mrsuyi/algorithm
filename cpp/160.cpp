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
			if (ia == NULL)
			{
				ia = headB;
			}

			if (ib == NULL)
			{
				ib = headA;
			}

			if (ia->next == NULL)
			{
				ea = ia;
			}

			if (ib->next == NULL)
			{
				eb = ib;
			}

			if (ea != NULL && eb != NULL && ea != eb) return NULL;

			if (ia == ib) return ia;

			ia = ia->next;
			ib = ib->next;
		}
	}
};

int main()
{

	while (getchar());

	return 0;
}