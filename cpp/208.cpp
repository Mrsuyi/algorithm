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

class TrieNode
{
public:
	TrieNode* childs[26];
	bool word;
	// Initialize your data structure here.
	TrieNode()
	{
		word = false;
		memset(childs, NULL, sizeof(TrieNode*) * 26);
	}
};

class Trie
{
private:
	TrieNode* root;

public:
	Trie()
	{
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word)
	{
		TrieNode* node = root;
		for (char c : word)
		{
			int idx = c - 'a';
			if (!node->childs[idx])
			{
				node->childs[idx] = new TrieNode();
			}
			node = node->childs[idx];
		}
		node->word = true;
	}

	// Returns if the word is in the trie.
	bool search(string word)
	{
		TrieNode* node = root;
		for (char c : word)
		{
			int idx = c - 'a';
			if (!node->childs[idx]) return false;
			node = node->childs[idx];
		}
		return node->word;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix)
	{
		TrieNode* node = root;
		for (char c : prefix)
		{
			int idx = c - 'a';
			if (!node->childs[idx]) return false;
			node = node->childs[idx];
		}
		return true;
	}
};

int main()
{
	while (getchar());

	return 0;
}