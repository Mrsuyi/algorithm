#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>

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
		if (!head || !head->next) return head;

		ListNode* ret = new ListNode(0);
		ret->next = head;

		ListNode* pre = ret;
		ListNode* i = head;

		while (i)
		{
			// move before next different node
			ListNode* mov = i;
			while (mov->next && mov->next->val == i->val) mov = mov->next;

			if (mov != i)
			{
				pre->next = mov->next;
			}
			else
			{
				pre = i;
			}
			
			i = mov->next;
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