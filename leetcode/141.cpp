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
	bool hasCycle(ListNode *head)
	{
		ListNode* slow = head;
		ListNode* fast = head;

		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast) return true;
		}

		return false;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}