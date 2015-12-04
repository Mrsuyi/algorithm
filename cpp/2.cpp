#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		int carry = 0;

		ListNode* head = new ListNode(0);
		ListNode* i = head;

		while (l1 && l2)
		{
			int add = carry + l1->val + l2->val;
			carry = add >= 10;

			i->next = new ListNode(add - carry * 10);
			i = i->next;
			
			l1 = l1->next;
			l2 = l2->next;
		}

		if (l2) l1 = l2;
		while (l1)
		{
			int add = carry + l1->val;
			carry = add >= 10;

			i->next = new ListNode(add - carry * 10);
			i = i->next;

			l1 = l1->next;
		}

		if (carry)
		{
			i->next = new ListNode(1);
		}

		return head->next;
	}
};

int main()
{

	while (getchar());

	return 0;
}