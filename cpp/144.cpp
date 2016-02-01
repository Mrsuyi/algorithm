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

class Solution
{
public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> ret;
		stack<TreeNode*> stk;

		stk.push(root);

		while (!stk.empty())
		{
			TreeNode* b = stk.top();
			stk.pop();

			if (b)
			{
				ret.push_back(b->val);
				stk.push(b->right);
				stk.push(b->left);
			}
		}

		return ret;
	}
};

class Solution
{
public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> ret;
		dfs(ret, root);
		return ret;
	}

	void dfs(vector<int>& ret, TreeNode* node)
	{
		if (!node) return;

		ret.push_back(node->val);
		dfs(ret, node->left);
		dfs(ret, node->right);
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}