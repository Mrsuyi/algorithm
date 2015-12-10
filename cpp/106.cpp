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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		int po_len = postorder.size();
		int in_len = inorder.size();

		if (po_len == 0) return NULL;

		// in [num]=>[idx]
		unordered_map<int, int> in;
		// [po-num]=>[in-idx]
		unordered_map<int, int> po_2_in;

		for (int i = 0; i < po_len; i++)
		{
			in[inorder[i]] = i;
		}
		for (int i = 0; i < in_len; i++)
		{
			po_2_in[postorder[i]] = in[postorder[i]];
		}

		return build(po_2_in, postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
	}

	TreeNode* build(unordered_map<int, int>& po_2_in, vector<int>& po, int po_l, int po_r, vector<int>& in, int in_l, int in_r)
	{
		int mid = po[po_r];
		int i = po_2_in[mid];

		TreeNode* ret = new TreeNode(mid);

		if (i != in_l)
		{
			int len = i - in_l;
			ret->left = build(po_2_in, po, po_l, po_l + len - 1, in, in_l, i - 1);
		}
		if (i < in_r)
		{
			int len = in_r - i;
			ret->right = build(po_2_in, po, po_r - len, po_r - 1, in, i + 1, in_r);
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