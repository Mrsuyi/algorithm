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

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator
{
public:
	TreeNode* node;

	stack<TreeNode*> stk;

	BSTIterator(TreeNode *root)
	{
		this->node = root;
		while (node)
		{
			stk.push(node);
			node = node->left;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext()
	{
		return !stk.empty();
	}

	/** @return the next smallest number */
	int next()
	{
		int ret;
		node = stk.top();
		stk.pop();
		ret = node->val;
		node = node->right;
		while (node)
		{
			stk.push(node);
			node = node->left;
		}
		return ret;
	}
};

int main()
{

	while (getchar());

	return 0;
}