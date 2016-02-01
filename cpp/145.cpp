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
		stack<TreeNode*> stk;

		stk.push(root);

		while (!stk.empty())
		{
			TreeNode* b = stk.top();
			stk.pop();

			if (b)
			{
				ret.push_back(b->val);
				stk.push(b->right);
				stk.push(b->left);
			}
		}

		return ret;
	}
};

class Solution
{
public:
	vector<int> postorderTraversal(TreeNode* root)
	{
		vector<int> ret;
		stack<TreeNode*> stk;
		stk.push(root);

		while (!stk.empty())
		{
			TreeNode* node = stk.top();
			stk.pop();
			
			if (node)
			{
				ret.push_back(node->val);
				stk.push(node->left);
				stk.push(node->right);
			}
		}

		reverse(ret.begin(), ret.end());
		return ret;
	}
};

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        stack<TreeNode*> stk;
        vector<int> ret;
        stk.push(root);
        
        while (root)
        {
            if (root->left || root->right)
            {
                if (root->right)
                {
                    stk.push(root->right);
                    root->right = nullptr;
                }
                if (root->left)
                {
                    stk.push(root->left);
                    root->left = nullptr;
                }
            }
            else
            {
                ret.push_back(root->val);
                stk.pop();
            }
            root = stk.empty() ? nullptr : stk.top();
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