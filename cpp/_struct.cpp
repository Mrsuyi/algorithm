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