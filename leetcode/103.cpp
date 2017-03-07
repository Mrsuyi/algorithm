#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root)
	{
		if (!root) return {};

		vector<vector<int>> ret;
		stack<TreeNode*> level;
		level.push(root);
		bool l_2_r = true;

		while (!level.empty())
		{
			stack<TreeNode*> tmp;
			vector<int> vals;

			while (!level.empty())
			{
				TreeNode* node = level.top();
				vals.push_back(node->val);
				if (l_2_r)
				{
					if (node->left) tmp.push(node->left);
					if (node->right) tmp.push(node->right);
				}
				else
				{
					if (node->right) tmp.push(node->right);
					if (node->left) tmp.push(node->left);
				}
				level.pop();
			}

			ret.push_back(vals);
			level = tmp;
			l_2_r = !l_2_r;
		}

		return ret;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}