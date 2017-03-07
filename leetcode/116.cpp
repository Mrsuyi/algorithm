#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct TreeLinkNode
{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
public:
	void connect(TreeLinkNode *root)
	{
		if (!root) return;

		TreeLinkNode* l = root->left;
		TreeLinkNode* r = root->right;

		if (l)
		{
			connect(l);
			connect(r);
		}

		while (l)
		{
			l->next = r;
			l = l->right;
			r = r->left;
		}
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}