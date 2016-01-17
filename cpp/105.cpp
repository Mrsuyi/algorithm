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
		unordered_map<int, int> map;
		for (int i = 0; i < inorder.size(); i++)
		{
			map[inorder[i]] = i;
		}
		return build(preorder, map, 0, 0, inorder.size());
	}

	TreeNode* build(vector<int>& pre, unordered_map<int, int>& map, int idx, int offset, int cnt)
	{
		if (cnt <= 0) return NULL;
		
		TreeNode* ret = new TreeNode(pre[idx]);
		
		int l = map[pre[idx]] - idx + offset;
		ret->left = build(pre, map, idx + 1, offset + 1, l);
		ret->right = build(pre, map, idx + l + 1, offset, cnt - l - 1);

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