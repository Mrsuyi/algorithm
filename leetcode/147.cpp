#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <deque>

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
	ListNode* insertionSortList(ListNode* head)
	{
		ListNode* ret = new ListNode(INT_MIN);

		while (head)
		{
			ListNode* i = ret;
			while (i->next && i->next->val < head->val)
			{
				i = i->next;
			}
			ListNode* insert = new ListNode(head->val);
			insert->next = i->next;
			i->next = insert;
			head = head->next;
		}

		return ret->next;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}