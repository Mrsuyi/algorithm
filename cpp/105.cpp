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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		int pr_len = preorder.size();
		int in_len = inorder.size();

		if (pr_len == 0) return NULL;

		// in [num]=>[idx]
		unordered_map<int, int> in;
		// [pr-num]=>[in-idx]
		unordered_map<int, int> pr_2_in;

		for (int i = 0; i < pr_len; i++)
		{
			in[inorder[i]] = i;
		}
		for (int i = 0; i < in_len; i++)
		{
			pr_2_in[preorder[i]] = in[preorder[i]];
		}

		return build(pr_2_in, preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}

	TreeNode* build(unordered_map<int, int>& pr_2_in, vector<int>& pr, int pr_l, int pr_r, vector<int>& in, int in_l, int in_r)
	{
		int mid = pr[pr_l];
		int i = pr_2_in[mid];

		TreeNode* ret = new TreeNode(mid);

		if (i != in_l)
		{
			int len = i - in_l;
			ret->left = build(pr_2_in, pr, pr_l + 1, pr_l + len, in, in_l, i - 1);
		}
		if (i < in_r)
		{
			int len = i - in_l;
			ret->right = build(pr_2_in, pr, pr_l + len + 1, pr_r, in, i + 1, in_r);
		}
		return ret;
	}
};

int main()
{
	Solution solution;

	vector<int> a = { 1,2,4,5,3,6,7 };
	vector<int> b = { 4,2,5,1,6,3,7 };

	solution.buildTree(a, b);

	while (getchar());

	return 0;
}