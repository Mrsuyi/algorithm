#include <iostream>
#include <vector>
#include <string>

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
    bool isSymmetric(TreeNode* root)
    {
        return root ? symmetric(root->left, root->right) : true;
    }
    
    bool symmetric(TreeNode* p, TreeNode* q)
    {
        return q == p
            || p
            && q
            && p->val == q->val
            && symmetric(p->left, q->right)
            && symmetric(p->right, q->left);
    }
};

int main()
{
	Solution solution;


	return 0;
}