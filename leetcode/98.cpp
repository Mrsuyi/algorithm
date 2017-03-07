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

typedef long long LL;

inline LL max(const LL a, const LL b) { return a > b ? a : b; };
inline LL min(const LL a, const LL b) { return a < b ? a : b; };

class Solution
{
public:
	bool isValidBST(TreeNode* root)
	{
		return check(root, LLONG_MIN, LLONG_MAX);
	}

	bool check(TreeNode* root, LL l, LL r)
	{
		if (!root) return true;
		if (root->val <= l || root->val >= r) return false;
		return check(root->left, l, min(root->val, r))
			&& check(root->right, max(root->val, l), r);
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}