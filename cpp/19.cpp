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
		ListNode* mov = head;

		for (int i = 1; i < n; i++)
		{
			mov = mov->next;
		}

		if (mov->next == NULL) return head->next;

		ListNode* pre;
		ListNode* del = head;

		do
		{
			mov = mov->next;
			pre = del;
			del = del->next;
		}
		while (mov->next != NULL);

		pre->next = del->next;

		return head;
	}
};

int main()
{
	Solution solution;

	int count;
	int remove;

	ListNode* head;
	ListNode* pre;

	// init
	head = new ListNode(0);
	pre = head;

	// input
	cin >> count;

	while (count--)
	{
		int val;
		cin >> val;
		ListNode* cur = new ListNode(val);
		pre->next = cur;
		pre = cur;
	}

	cin >> remove;

	pre = head->next;
	delete head;
	head = pre;

	//
	head = solution.removeNthFromEnd(head, remove);

	// release
	do
	{
		cout << head->val << ' ';
		ListNode* temp = head->next;
		delete head;
		head = temp;
	}
	while (head != NULL);

	while (getchar());

	return 0;
}