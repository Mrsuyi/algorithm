inline int max(const int a, const int b) { return a > b ? a : b; };
inline int min(const int a, const int b) { return a < b ? a : b; };

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeLinkNode
{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

struct UndirectedGraphNode
{
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

TreeNode* build(vector<int> nums)
{
	if (nums.size() == 0) return NULL;

	TreeNode* root = new TreeNode(nums[0]);
	TreeNode* node = root;
	bool fresh = true;
	queue<TreeNode*> q;

	for (int i = 1; i < nums.size(); i++)
	{
		if (fresh)
		{
			if (nums[i] != 0)
			{
				TreeNode* add = new TreeNode(nums[i]);
				q.push(add);
				node->left = add;
			}
		}
		else
		{
			if (nums[i] != 0)
			{
				TreeNode* add = new TreeNode(nums[i]);
				q.push(add);
				node->right = add;

				node = q.front();
				q.pop();
			}
		}
		fresh = !fresh;
	}

	return root;
}