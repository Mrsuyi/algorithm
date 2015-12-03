#include <iostream>
#include <vector>
#include <stack>
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
	void deleteNode(ListNode* node)
	{
		node->val = node->next->val;
		node->next = node->next->next;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}