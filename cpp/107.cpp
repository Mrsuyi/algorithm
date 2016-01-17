#include <iostream>
#include <vector>
#include <string>

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
	vector<vector<int>> levelOrderBottom(TreeNode* root)
	{
		int d = depth(root);
		vector<vector<int>> ret(d);
		vector<TreeNode*> nodes;
		vector<TreeNode*> tmp;

		nodes.push_back(root);

		for (int i = 0; i < d; i++)
		{
			tmp.clear();

			for (int j = 0; j < nodes.size(); j++)
			{
				ret[i].push_back(nodes[j]->val);
				if (nodes[j]->left) { tmp.push_back(nodes[j]->left); }
				if (nodes[j]->right) { tmp.push_back(nodes[j]->right); }
			}
			swap(nodes, tmp);
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}

	int depth(TreeNode* node)
	{
		if (!node) return 0;
		return max(depth(node->left), depth(node->right)) + 1;
	}
};

int main()
{
	Solution solution;


	return 0;
}