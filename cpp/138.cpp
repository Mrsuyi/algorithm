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

struct RandomListNode
{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}	
};

class Solution
{
public:
	RandomListNode *copyRandomList(RandomListNode *head)
	{
		unordered_map<RandomListNode*, RandomListNode*> map;

		RandomListNode* ret = new RandomListNode(0);
		RandomListNode* pre = ret;
		RandomListNode* it = head;

		while (it)
		{
			RandomListNode* cur = new RandomListNode(it->label);
			map[it] = cur;
			it = it->next;
			pre->next = cur;
			pre = cur;
		}

		it = head;
		pre = ret;
		while (it)
		{
			pre->next->random = map[it->random];
			pre = pre->next;
			it = it->next;
		}

		return ret->next;
	}
};

class Solution
{
public:
	RandomListNode *copyRandomList(RandomListNode *head)
	{
		RandomListNode* n = head;
		while (n)
		{
			RandomListNode* copy = new RandomListNode(n->label);
			copy->next = n->next;
			n->next = copy;
			n = copy->next;
		}

		n = head;
		while (n)
		{
			if (n->random)
			{
				n->next->random = n->random->next;
			}
			n = n->next->next;
		}

		RandomListNode* ret = new RandomListNode(0);
		RandomListNode* pre = ret;
		n = head;
		while (n)
		{
			pre->next = n->next;
			pre = pre->next;
			n->next = n->next->next;
			n = n->next;
		}
		return ret->next;
	}
};

int main()
{
	while (getchar());

	return 0;
}