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

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

class LRUCache
{
private:
	struct Node
	{
		Node* l = nullptr;
		Node* r = nullptr;
		int key;
		Node(int key) : key(key) {}
	};

	unordered_map<int, pair<int, Node*>> cache;
	int cap;
	int sum;
	Node* head;
	Node* tail;

	void inc(Node* node)
	{
		if (node == tail) return;

		node->l->r = node->r;
		if (node->r)
		{
			node->r->l = node->l;
		}
		tail->r = node;
		node->l = tail;
		tail = node;
	}

	void add(int key, int value)
	{
		Node* n = new Node(key);
		n->l = tail;
		tail->r = n;
		tail = n;
		cache[key] = make_pair(value, n);
		sum++;
	}

	void del()
	{
		Node* n = head->r;
		cache.erase(n->key);
		head->r = n->r;
		if (n->r)
		{
			n->r->l = head;
		}
		delete n;
		sum--;
	}

public:
	LRUCache(int capacity)
	{
		cap = capacity;
		sum = 0;
		head = new Node(0);
		tail = head;
	}

	int get(int key)
	{
		auto it = cache.find(key);

		if (it != cache.end())
		{
			inc(it->second.second);
			return it->second.first;
		}
		else
		{
			return -1;
		}
	}

	void set(int key, int value)
	{
		auto it = cache.find(key);

		if (it != cache.end())
		{
			inc(it->second.second);
			it->second.first = value;
		}
		else
		{
			if (sum == cap)
			{
				del();
			}
			add(key, value);
		}
	}
};

int main()
{
	LRUCache c(2);

	c.set(2, 1); 
	c.set(2, 2);
	cout << c.get(2) << endl;
	c.set(1, 1);
	c.set(4, 1);
	cout << c.get(2) << endl;

	while (getchar());

	return 0;
}