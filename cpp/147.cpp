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
		vector<int> nums;

		while (head)
		{
			nums.push_back(head->val);
			head = head->next;
		}

		sort(nums.begin(), nums.end());

		ListNode* ret = new ListNode(0);
		ListNode* i = ret;
		for (int n : nums)
		{
			i->next = new ListNode(n);
			i = i->next;
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