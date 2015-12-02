#include <iostream>
#include <vector>
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
	ListNode* reverseList(ListNode* head)
	{
		ListNode* pre = NULL;

		while (head)
		{
			ListNode* nxt = head->next;
			head->next = pre;
			pre = head;
			head = nxt;
		}

		return pre;
	}
};

int main()
{
	Solution solution;

	ListNode a(1), b(2), c(3);
	a.next = &b;
	b.next = &c;

	solution.reverseList(&a);

	while (getchar());

	return 0;
}