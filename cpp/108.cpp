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
	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		if (nums.size() == 0) return NULL;
		return build(nums, 0, nums.size() - 1);
	}

	TreeNode* build(vector<int>& nums, int l, int r)
	{
		if (l > r) return NULL;
		if (l == r) return new TreeNode(nums[l]);

		int mid = (l + r) / 2 + (l + r) % 2;

		TreeNode* ret = new TreeNode(nums[mid]);
		ret->left = build(nums, l, mid - 1);
		ret->right = build(nums, mid + 1, r);

		return ret;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}