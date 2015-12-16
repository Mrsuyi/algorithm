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

class WordDictionary
{
private:
	class Trie
	{
	public:
		Trie* childs[26];
		bool word;

		Trie()
		{
			word = false;
			memset(childs, NULL, sizeof(Trie*) * 26);
		}
	};

	Trie* root;

public:

	WordDictionary()
	{
		root = new Trie();
	}

	// Adds a word into the data structure.
	void addWord(string word)
	{
		Trie* node = root;
		for (char c : word)
		{
			int idx = c - 'a';
			if (!node->childs[idx])
			{
				node->childs[idx] = new Trie();
			}
			node = node->childs[idx];
		}
		node->word = true;
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word)
	{
		return sch(word, 0, root);
	}

	bool sch(string& word, int idx, Trie* node)
	{
		if (idx == word.size()) return node->word;

		if (word[idx] == '.')
		{
			for (auto n : node->childs)
			{
				if (n && sch(word, idx + 1, n)) return true;
			}
			return false;
		}
		else
		{
			Trie* n = node->childs[word[idx] - 'a'];
			return n && sch(word, idx + 1, n);
		}
	}
};

int main()
{
	while (getchar());

	return 0;
}