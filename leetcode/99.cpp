#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	void recoverTree(TreeNode* root)
	{
		vector<TreeNode*> nodes;

		search(root, nodes);

		int i = 0, k;
		int len = nodes.size();
		
		while (nodes[i]->val < nodes[i + 1]->val) { i++; }
		k = i;
		i += 2;
		while (i < len && nodes[i]->val > nodes[i - 1]->val) { i++; }

		if (i == len)
		{
			swap(nodes[k], nodes[k + 1]);
		}
		else
		{
			swap(nodes[k], nodes[i]);
		}
	}

	void search(TreeNode* node, vector<TreeNode*>& nodes)
	{
		if (!node) return;
		search(node->left, nodes);
		nodes.push_back(node);
		search(node->right, nodes);
	}

	void swap(TreeNode* a, TreeNode* b)
	{
		int tmp = a->val;
		a->val = b->val;
		b->val = tmp;
	}
};


class Solution
{
public:
	void recoverTree(TreeNode* root)
	{
		TreeNode* pre = new TreeNode(INT_MIN);
		TreeNode* m = NULL;
		TreeNode* n = NULL;

		search(root, pre, m, n);

		int tmp = m->val;
		m->val = n->val;
		n->val = tmp;
	}

	void search(TreeNode* node, TreeNode*& pre, TreeNode*& m, TreeNode*& n)
	{
		if (!node) return;
		search(node->left, pre, m, n);
		if (pre->val > node->val)
		{
			if (!m) { m = pre; }
			n = node;
		}
		pre = node;
		search(node->right, pre, m, n);
	}
};


int main()
{
	while (getchar());

	return 0;
}