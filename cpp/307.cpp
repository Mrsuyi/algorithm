#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

struct SegNode
{
	int val, l, r;
	SegNode *left;
	SegNode *right;
	SegNode(int x, int l, int r) : val(x), l(l), r(r), left(NULL), right(NULL) {}
};

class NumArray
{
private:
	SegNode* root;
	vector<int> nums;

	SegNode* build(vector<int>& nums, int l, int r)
	{
		if (l == r)
		{
			return new SegNode(nums[l], l , l);
		}
		else
		{
			int mid = (l + r) >> 1;

			SegNode* nl = build(nums, l, mid);
			SegNode* nr = build(nums, mid + 1, r);

			SegNode* ret = new SegNode(nl->val + nr->val, l, r);
			ret->left = nl;
			ret->right = nr;

			return ret;
		}
	}

	void modify(SegNode* node, int i, int diff)
	{
		node->val += diff;
		if (node->left)
		{
			if (i <= node->left->r)
			{
				modify(node->left, i, diff);
			}
			else
			{
				modify(node->right, i, diff);
			}
		}
	}

	int val(SegNode* node, int l, int r)
	{
		if (l == node->l && r == node->r) return node->val;

		int mid = (node->l + node->r) >> 1;
		if (l > mid)
		{
			return val(node->right, l, r);
		}
		else if (r <= mid)
		{
			return val(node->left, l, r);
		}
		else	
		{
			return val(node->left, l, mid) + val(node->right, mid + 1, r);
		}
	}

public:
	NumArray(vector<int> &nums)
	{
		int len = nums.size();
		this->nums = nums;
		if (!len) return;
		root = build(nums, 0, len - 1);
	}

	void update(int i, int val)
	{
		modify(root, i, val - nums[i]);
		nums[i] = val;
	}

	int sumRange(int i, int j)
	{
		return val(root, i, j);
	}
};

int main()
{
	while (getchar());

	return 0;
}