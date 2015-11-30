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

class Solution {
public:
	int minDepth(TreeNode* root)
	{
		if (root == NULL) return 0;

		int ret = 1;

		vector<TreeNode*> bfs;

		bfs.push_back(root);

		while (true)
		{
			vector<TreeNode*> temp;

			for (auto node : bfs)
			{
				if (node->left == NULL && node->right == NULL)
				{
					return ret;
				}
				else
				{
					if (node->left != NULL) temp.push_back(node->left);
					if (node->right != NULL) temp.push_back(node->right);
				}
			}

			ret++;
			bfs = temp;
		}
	}
};

int main()
{
	Solution solution;

	return 0;
}