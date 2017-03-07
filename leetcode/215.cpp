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

//heap
class Solution
{
public:
	int findKthLargest(vector<int>& nums, int k)
	{
		int len = nums.size();
		priority_queue<int, vector<int>, greater<int>> q;
		
		for (int i = 0; i < k; i++)
		{
			q.push(nums[i]);
		}
		for (int i = k; i < len; i++)
		{
			if (q.top() < nums[i])
			{
				q.pop();
				q.push(nums[i]);
			}
		}

		return q.top();
	}
};

class Solution
{
private: 
	inline void swap(vector<int>& nums, int i, int j)
	{
		int tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}

public:
	int findKthLargest(vector<int>& nums, int k)
	{
		return search(nums, 0, nums.size() - 1, k);
	}

	int search(vector<int>& nums, int l, int r, int k)
	{
		if (l >= r) return nums[l];

		int cmp = nums[l];
		int i_l = l + 1;
		int i_r = r;

		while (true)
		{
			while (nums[i_l] <= cmp && i_l <= i_r) { i_l++; }
			while (nums[i_r] >  cmp && i_r >  i_l) { i_r--; }

			if (i_l < i_r) swap(nums, i_l++, i_r--); else break;
		}
		
		int idx = i_l - 1;

		swap(nums, l, i_l - 1);

		int rank = r - idx + 1;

		if (rank == k)
		{
			return cmp;
		}
		else if (rank < k)
		{
			return search(nums, l, idx - 1, k - rank);
		}
		else
		{
			return search(nums, idx + 1, r, k);
		}
	}
};

int main()
{
	Solution solution;

	vector<int> input = { 3,2,1,5,6,4 };

	solution.findKthLargest(input, 2);

	while (getchar());

	return 0;
}