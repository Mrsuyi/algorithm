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
	ListNode* deleteDuplicates(ListNode* head)
	{
		ListNode* pre = head;
		ListNode* cur = head;

		while (cur)
		{
			do
			{
				cur = cur->next;
			}
			while (cur && cur->val == pre->val);

			pre->next = cur;
			pre = cur;
		}

		return head;
	}
};

int main()
{
	Solution solution;

	int count;

	ListNode* head = new ListNode(0);
	ListNode* pre = head;

	cin >> count;
	while (count--)
	{
		int input;
		cin >> input;
		ListNode* cur = new ListNode(input);
		pre->next = cur;
		pre = cur;
	}

	head = solution.deleteDuplicates(head->next);

	while (head)
	{
		cout << head->val << ' ';
		head = head->next;
	}

	while (getchar());

	return 0;
}