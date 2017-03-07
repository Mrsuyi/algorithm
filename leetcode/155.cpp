#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class MinStack
{
private:
	struct Node
	{
		int val;
		int mim;
		Node* nxt;

		Node(int v, Node* n, int m) : val(v), nxt(n)
		{
			mim = min(v, m);
		}
	};

	Node* ptop = new Node(INT_MAX, nullptr, INT_MAX);

public:
	void push(int x)
	{
		Node* n = new Node(x, ptop, ptop->mim);
		ptop = n;
	}

	void pop()
	{
		Node* tmp = ptop->nxt;
		delete ptop;
		ptop = tmp;
	}

	int top()
	{
		return ptop->val;
	}

	int getMin()
	{
		return ptop->mim;
	}
};

int main()
{
	while (getchar());

	return 0;
}