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

		connect(l);
		connect(r);

		while (l && r)
		{
			TreeLinkNode* tmp1 = l;
			TreeLinkNode* tmp2 = r;
			while (tmp1->next) { tmp1 = tmp1->next; }

			while (!l->left && !l->right && l->next) { l = l->next; }
			l = l->left ? l->left : l->right;
			while (!r->left && !r->right && r->next) { r = r->next; }
			r = r->left ? r->left : r->right;

			tmp1->next = tmp2;
		}
	}
};

int main()
{
	while (getchar());

	return 0;
}