#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

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
	ListNode* removeElements(ListNode* head, int val)
	{
		ListNode* hd = new ListNode(0);

		ListNode* pre = hd;
		ListNode* cur = head;

		hd->next = head;

		while (cur != NULL)
		{
			if (cur->val == val)
			{
				pre->next = cur->next;
			}
			else
			{
				pre = cur;
			}
			cur = cur->next;
		}

		return hd->next;
	}
};

int main()
{
	Solution solution;


	while (getchar());

	return 0;
}