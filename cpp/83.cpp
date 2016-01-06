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
		ListNode* i = head;

		while (i)
		{
			if (i->next && i->next->val == i->val)
			{
				i->next = i->next->next;
			}
			else
			{
				i = i->next;
			}
		}
		return head;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}