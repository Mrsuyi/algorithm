#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <functional>

using namespace std;

struct BST
{
	int val;
	BST *left;
	BST *right;
	BST(int x) : val(x), left(NULL), right(NULL) {}
	
	void max(BST*& node, BST*& parent)
	{
		node = this;
		parent = nullptr;
		
		while (node->right)
		{
			parent = node;
			node = node->right;
		}
	}

	int max()
	{
		BST* node = this;
		while (node->right)
		{
			node = node->right;
		}
		return node->val;
	}

	void min(BST*& node, BST*& parent)
	{
		node = this;
		parent = nullptr;

		while (node->left)
		{
			parent = node;
			node = node->left;
		}
	}

	int min()
	{
		BST* node = this;
		while (node->left)
		{
			node = node->left;
		}
		return node->val;
	}
};

class MedianFinder
{
public:
	BST* root = nullptr;
	int l = 0, r = 0;

	// Adds a number into the data structure.
	void addNum(int num)
	{
		if (!root)
		{
			root = new BST(num);
		}
		else
		{
			// cnt
			if (num >= root->val)
			{
				r++;
			}
			else
			{
				l++;
			}

			// insert
			BST* node = root;
			BST* parent = nullptr;

			while (node)
			{
				parent = node;

				if (num >= node->val)
				{
					node = node->right;
				}
				else
				{
					node = node->left;
				}
			}

			if (num >= parent->val)
			{
				parent->right = new BST(num);
			}
			else
			{
				parent->left = new BST(num);
			}

			// balance
			if (l > r + 1)
			{
				BST* node = nullptr;
				BST* parent = nullptr;

				root->left->max(node, parent);

				if (parent)
				{
					parent->right = node->left;
					node->left = root->left;
				}

				node->right = root;
				root->left = nullptr;
				root = node;

				l--;
				r++;
			}
			else if (r > l + 1)
			{
				BST* node = nullptr;
				BST* parent = nullptr;

				root->right->min(node, parent);

				if (parent)
				{
					parent->left = node->right;
					node->right = root->right;
				}

				node->left = root;
				root->right = nullptr;
				root = node;

				r--;
				l++;
			}
		}
	}

	// Returns the median of current data stream
	double findMedian()
	{
		if (l == r)
		{
			return root->val;
		}
		else if (l > r)
		{
			return double(root->val + root->left->max()) / 2;
		}
		else
		{
			return double(root->val + root->right->min()) / 2;
		}
	}
};

int main()
{
	MedianFinder mf;

	mf.addNum(-1);
	cout << mf.findMedian() << endl;
	mf.addNum(-2);
	cout << mf.findMedian() << endl;
	mf.addNum(-3);
	cout << mf.findMedian() << endl;
	mf.addNum(-4);
	cout << mf.findMedian() << endl;
	mf.addNum(-5);
	cout << mf.findMedian() << endl;

	while (getchar());

	return 0;
}