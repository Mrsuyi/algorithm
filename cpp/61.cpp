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
	ListNode* rotateRight(ListNode* head, int k)
	{
		if (!head || !head->next) return head;

		ListNode* r = head;
		ListNode* l = head;

		// mov until r moved k steps, or r reached tail
		int len = 1;
		int cnt = k;
		while (cnt && r->next)
		{
			r = r->next;
			cnt--;
			len++;
		}

		// k steps is not finish, means k > len
		if (cnt > 0)
		{
			int rem = k % len;

			if (rem == 0) return head;

			int mov = len - rem - 1;
			while (mov--) { l = l->next; }
		}
		else
		{
			while (r->next)
			{
				r = r->next;
				l = l->next;
			}
		}

		// list operation
		r->next = head;
		head = l->next;
		l->next = NULL;

		return head;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}