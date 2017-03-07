#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Queue {
public:
	stack<int> s;
	
	// Push element x to the back of queue.
	void push(int x)
	{
		s.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void)
	{
		stack<int> tmp;

		int cnt = s.size() - 1;

		for (int i = 0; i < cnt; i++)
		{
			tmp.push(s.top());
			s.pop();
		}

		s.pop();

		for (int i = 0; i < cnt; i++)
		{
			s.push(tmp.top());
			tmp.pop();
		}
	}

	// Get the front element.
	int peek(void)
	{
		stack<int> tmp;

		int cnt = s.size();

		for (int i = 0; i < cnt; i++)
		{
			tmp.push(s.top());
			s.pop();
		}

		int ret = tmp.top();

		for (int i = 0; i < cnt; i++)
		{
			s.push(tmp.top());
			tmp.pop();
		}

		return ret;
	}

	// Return whether the queue is empty.
	bool empty(void)
	{
		return s.empty();
	}
};

int main()
{
	Queue q;

	while (getchar());

	return 0;
}