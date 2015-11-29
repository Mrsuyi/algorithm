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
		ListNode* head = new ListNode(0);
		ListNode* mov = head;

		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				mov->next = l1;
				l1 = l1->next;
			}
			else
			{
				mov->next = l2;
				l2 = l2->next;
			}

			mov = mov->next;
		}
		
		if (l1) mov->next = l1; else mov->next = l2;

		return head->next;
	}
};

int main()
{
	Solution solution;

	int count;

	ListNode* head1;
	ListNode* pre1;

	ListNode* head2;
	ListNode* pre2;

	// 1
	head1 = new ListNode(0);
	pre1 = head1;

	cin >> count;
	while (count--)
	{
		int val;
		cin >> val;
		ListNode* cur = new ListNode(val);
		pre1->next = cur;
		pre1 = cur;
	}

	pre1 = head1->next;
	delete head1;
	head1 = pre1;

	// 2
	head2 = new ListNode(0);
	pre2 = head2;

	cin >> count;
	while (count--)
	{
		int val;
		cin >> val;
		ListNode* cur = new ListNode(val);
		pre2->next = cur;
		pre2 = cur;
	}

	pre2 = head2->next;
	delete head2;
	head2 = pre2;

	//
	head1 = solution.mergeTwoLists(head1, head2);

	// release
	do
	{
		cout << head1->val << ' ';
		head1 = head1->next;
	}
	while (head1 != NULL);

	while (getchar());

	return 0;
}