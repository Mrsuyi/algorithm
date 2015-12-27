#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
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
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		multimap<int, ListNode*> vals;

		for (auto node : lists)
		{
			if (node) { vals.insert(make_pair(node->val, node)); }
		}

		ListNode* head = new ListNode(0);
		ListNode* i = head;
		while (!vals.empty())
		{
			auto max = vals.begin();
			i->next = new ListNode(max->first);
			i = i->next;
			if (max->second->next)
			{
				vals.insert(make_pair(max->second->next->val, max->second->next));
			}
			vals.erase(max);
		}
		return head->next;
	}
};

int main()
{
	while (getchar());

	return 0;
}