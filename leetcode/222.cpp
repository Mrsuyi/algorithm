#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
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
	int countNodes(TreeNode* root)
	{
		int level = 0;
		TreeNode* i = root;
		while (i)
		{
			i = i->left;
			level++;
		}

		if (level == 0) return 0;

		int l = 0, r = (1 << (level - 1)) - 1;
		while (l <= r)
		{
			int mid = l + ((r - l) >> 1);

			if (get(root, mid, level - 1))
			{
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}

		return (1 << (level - 1)) + r;
	}

	TreeNode* get(TreeNode* root, int idx, int n)
	{
		while (n-- && root)
		{
			root = (idx & (1 << n)) ? root->right : root->left;
		}
		return root;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}