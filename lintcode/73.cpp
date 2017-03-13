/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
 

class Solution {
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir)
    {
        if (pl > pr)
            return nullptr;

        for (int i = il; i <= ir; ++i)
        {
            if (inorder[i] == preorder[pl])
            {
                int lsz = i - il;
                int rsz = ir - i;

                TreeNode* res = new TreeNode(preorder[pl]);
                res->left = build(preorder, inorder, pl + 1, pl + lsz, il, i - 1);
                res->right = build(preorder, inorder, pl + lsz + 1, pl + lsz + rsz, i + 1, ir);
                return res;
            }
        }
    }
};