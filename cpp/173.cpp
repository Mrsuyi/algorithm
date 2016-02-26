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
private:
	stack<TreeNode*> stk;

	void move(TreeNode* node)
	{
		while (node)
		{
			stk.push(node);
			node = node->left;
		}
	}

public:
	BSTIterator(TreeNode *root)
	{
		move(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext()
	{
		return !stk.empty();
	}

	/** @return the next smallest number */
	int next()
	{
		TreeNode* node = stk.top();
		stk.pop();

		if (node->right)
		{
			move(node->right);
		}

		return node->val;
	}
};

// morris traverse

class BSTIterator
{
private:
	TreeNode* cur;

public:
	BSTIterator(TreeNode *root)
	{
		cur = root;
	}

	/** @return whether we have a next smallest number */
	bool hasNext()
	{
		return cur != nullptr;
	}

	/** @return the next smallest number */
	int next()
	{
		while (cur)
		{
			if (!cur->left)
			{
				int ret = cur->val;
				cur = cur->right;
				return ret;
			}
			else
			{
				TreeNode* pre = cur->left;

				while (pre->right && pre->right != cur)
				{
					pre = pre->right;
				}

				if (pre->right == cur)
				{
					pre->right = nullptr;
					int ret = cur->val;
					cur = cur->right;
					return ret;
				}
				else
				{
					pre->right = cur;
					cur = cur->left;
				}
			}
		}
	}
};

int main()
{

	while (getchar());

	return 0;
}