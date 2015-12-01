#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MinStack {
public:
	struct Node
	{
		int val;
		int min;
		Node* pre;
		Node* nxt;

		Node(int x, int m) : val(x), pre(NULL), nxt(NULL)
		{
			min = x < m ? x : m;
		}
	};

	Node* head;
	Node* tail;

	void push(int x)
	{
		tail->nxt = new Node(x, tail->min);
		tail->nxt->pre = tail;
		tail = tail->nxt;
	}

	void pop()
	{
		tail = tail->pre;
		delete tail->nxt;
		tail->nxt = NULL;
	}

	int top()
	{
		return tail->val;
	}

	int getMin()
	{
		return tail->min;
	}

	MinStack()
	{
		head = new Node(INT_MAX, INT_MAX);
		tail = head;

		head->nxt = tail;
		tail->pre = head;
	}
};

int main()
{
	MinStack stack;

	stack.push(2);
	stack.push(0);
	stack.push(3);
	stack.push(0);

	cout << stack.getMin() << endl;
	stack.pop();
	cout << stack.getMin() << endl;
	stack.pop();
	cout << stack.getMin() << endl;
	stack.pop();
	cout << stack.getMin() << endl;
	stack.pop();

	while (getchar());

	return 0;
}