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

class Codec
{
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root)
	{
		string ret;

		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty())
		{
			TreeNode* node = q.front();
			q.pop();

			if (node)
			{
				ret += '#' + to_string(node->val);
				q.push(node->left);
				q.push(node->right);
			}
			else
			{
				ret += "#n";
			}
		}

		return ret + '#';
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data)
	{
		TreeNode* ret = new TreeNode(0);
		TreeNode* node = ret;
		queue<TreeNode*> q;
		int len = data.length();

		for (int i(1), state(1); i < len; i++, state = !state)
		{
			TreeNode* nxt = NULL;

			if (data[i] != 'n')
			{
				nxt = new TreeNode(data[i] == '-' ? -num(data, ++i) : num(data, i));
				q.push(nxt);
			}
			else
			{
				i++;
			}

			if (state)
			{
				node->right = nxt;
			}
			else
			{
				node = q.front();
				q.pop();
				node->left = nxt;
			}
		}

		return ret->right;
	}

	int num(string& str, int& idx)
	{
		int ret = 0;
		for (char c = str[idx]; c != '#'; c = str[++idx])
		{
			ret = 10 * ret + c - '0';
		}
		return ret;
	}
};

int main()
{
	while (getchar());

	return 0;
}