#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution
{
private:
	class TrieNode
	{
	public:
		TrieNode* children[26];
		bool leaf;
		char val;

		bool hasChildren()
		{
			for (auto n : children)
			{
				if (n) return true;
			}
			return false;
		}

		TrieNode(char c = '0') : val(c), leaf(false)
		{
			memset(children, NULL, sizeof(children));
		}
	};

public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
	{
		vector<string> ret;
		int m = board.size();
		if (m == 0) return ret;
		int n = board[0].size();

		TrieNode* root = new TrieNode();
		
		for (auto& str : words)
		{
			TrieNode* node = root;

			for (char c : str)
			{
				if (node->children[c - 'a'])
				{
					node = node->children[c - 'a'];
				}
				else
				{
					TrieNode* child = new TrieNode(c);
					node->children[c - 'a'] = child;
					node = child;
				}
			}
			node->leaf = true;
		}

		for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			string prefix;
			dfs(ret, board, prefix, root, i, j, m, n);
		}

		return ret;
	}

	void dfs(vector<string>& ret, vector<vector<char>>& board, string& prefix, TrieNode* node, int x, int y, int m, int n)
	{
		char c = board[x][y];

		if (c == '*') return;
		
		if (node->children[c - 'a'])
		{
			TrieNode* tmp = node;
			node = node->children[c - 'a'];
			prefix.push_back(c);
			board[x][y] = '*';

			if (node->leaf)
			{
				ret.push_back(prefix);
				node->leaf = false;
			}
			if (node->hasChildren())
			{
				if (x > 0) dfs(ret, board, prefix, node, x - 1, y, m, n);
				if (x < m - 1) dfs(ret, board, prefix, node, x + 1, y, m, n);
				if (y > 0) dfs(ret, board, prefix, node, x, y - 1, m, n);
				if (y < n - 1) dfs(ret, board, prefix, node, x, y + 1, m, n);
			}

			if (!node->leaf && !node->hasChildren())
			{
				tmp->children[node->val - 'a'] = nullptr;
				delete node;
			}

			prefix.pop_back();
			board[x][y] = c;
		}
	}
};

int main()
{
	vector<string> input = { "abc", "aed", "afg" };
	vector<vector<char>> board;

	for (auto& str : input)
	{
		board.push_back(vector<char>());
		
		for (char c : str)
		{
			board.back().push_back(c);
		}
	}

	vector<string> words = { "abcdefg", "gfedcbaaa", "eaabcdgfa", "befa", "dgc", "ade" };

	Solution so;
	so.findWords(board, words);

	while (getchar());

	return 0;
}