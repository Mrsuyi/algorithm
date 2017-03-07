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

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator
{
	struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator
{
private:
	bool moved;
	int val;

public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums)
	{
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.
		moved = false;
	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek()
	{
		if (!moved)
		{
			val = Iterator::next();
			moved = true;
		}
		return val;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next()
	{
		if (!moved) return Iterator::next();

		moved = false;
		return val;
	}

	bool hasNext() const
	{
		if (moved) return true;
		return Iterator::hasNext();
	}
};

int main()
{
	while (getchar());

	return 0;
}