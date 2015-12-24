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
	ListNode* reverseKGroup(ListNode* head, int k)
	{
		ListNode* ret = new ListNode(0);
		ret->next = head;

		ListNode* before = ret;
		do
		{
			ListNode* bgn = before->next;

			ListNode* after = bgn;
			int cnt = k;
			while (cnt && after)
			{
				after = after->next;
				cnt--;
			}
			if (cnt) break;

			ListNode* pre = after;
			ListNode* cur = bgn;
			cnt = k;
			while (cnt--)
			{
				ListNode* nxt = cur->next;
				cur->next = pre;
				pre = cur;
				cur = nxt;
			}

			before->next = pre;
			before = bgn;
		}
		while (before->next);

		return ret->next;
	}
};

int main()
{
	while (getchar());

	return 0;
}