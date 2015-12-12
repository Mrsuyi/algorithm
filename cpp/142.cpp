#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

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
	ListNode *detectCycle(ListNode *head)
	{
		ListNode* slow = head;
		ListNode* fast = head;

		ListNode* mark;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast) break;
		}

		if (!fast || !fast->next) return NULL;

		fast = head;
		while (fast != slow)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return fast;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}