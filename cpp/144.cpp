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
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> ret;
		stack<TreeNode*> st;

		st.push(root);

		while (!st.empty())
		{
			TreeNode* b = st.top();
			st.pop();

			if (b)
			{
				ret.push_back(b->val);
				st.push(b->right);
				st.push(b->left);
			}
		}

		return ret;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}