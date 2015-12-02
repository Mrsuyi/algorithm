#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

class Stack {
public:
	queue<int> q;

	// Push element x onto stack.
	void push(int x)
	{
		q.push(x);
	}

	// Removes the element on top of the stack.
	void pop()
	{
		int size = q.size();
		
		while (--size)
		{
			q.push(q.front());
			q.pop();
		}

		q.pop();
	}

	// Get the top element.
	int top()
	{
		int size = q.size();

		while (--size)
		{
			q.push(q.front());
			q.pop();
		}

		int ret = q.front();
		q.pop();
		q.push(ret);
		return ret;
	}

	// Return whether the stack is empty.
	bool empty()
	{
		return q.size() == 0;
	}
};

int main()
{
	Stack stack;

	stack.push(1);
	stack.push(2);
	stack.pop();

	cout << stack.top() << endl;

	while (getchar());

	return 0;
}