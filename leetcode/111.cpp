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
	int minDepth(TreeNode* root)
	{
		if (!root) return 0;

		int ret = 1;
		vector<TreeNode*> bfs, tmp;
		bfs.push_back(root);

		while (!bfs.empty())
		{
			tmp.clear();
			for (int i = 0; i < bfs.size(); i++)
			{
				if (!bfs[i]->left && !bfs[i]->right) return ret;
				if (bfs[i]->left) { tmp.push_back(bfs[i]->left); }
				if (bfs[i]->right) { tmp.push_back(bfs[i]->right); }
			}
			swap(bfs, tmp);
			ret++;
		}
	}
};

int main()
{
	Solution solution;


	return 0;
}