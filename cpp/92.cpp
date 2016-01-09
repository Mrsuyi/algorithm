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
	ListNode* reverseBetween(ListNode* head, int m, int n)
	{
		ListNode* ret = new ListNode(0);
		ret->next = head;

		ListNode* pre = ret;
		int k = m;

		while (--k)
		{
			pre = pre->next;
		}

		ListNode* l = pre->next;
		ListNode* r = pre->next->next;
		k = n - m;
		
		while (k--)
		{
			ListNode* tmp = r->next;
			r->next = l;
			l = r;
			r = tmp;
		}

		pre->next->next = r;
		pre->next = l;

		return ret->next;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}