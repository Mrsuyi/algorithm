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
	vector<int> rightSideView(TreeNode* root)
	{
		vector<int> ret;

		traverse(ret, root, 0);

		return ret;
	}

	void traverse(vector<int>& ret, TreeNode* root, int level)
	{
		if (!root) return;

		if (ret.size() == level)
		{
			ret.push_back(root->val);
		}
		else
		{
			ret[level] = root->val;
		}

		traverse(ret, root->left, level + 1);
		traverse(ret, root->right, level + 1);
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}