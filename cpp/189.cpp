#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	inline int MCD(int a, int b)
	{
		int bg, sm;

		if (a > b)
		{
			bg = a;
			sm = b;
		}
		else
		{
			bg = b;
			sm = a;
		}

		while (true)
		{
			int quo = bg % sm;
			if (quo == 0) return sm;
			bg = sm;
			sm = quo;
		}
	}

	void rotate(vector<int>& nums, int k)
	{
		int len = nums.size();

		if (len == 0 || k % len == 0) return;

		int mcd = MCD(len, k);

		// round is the mcd(min common divisor) of (len & k)
		// mov of each round is (len / mcd)
		// len = 6, k = 4    =>   mcd = 2, round = 2, mov = 3

		for (int round = 0; round < mcd; round++)
		{
			int src = round;
			int dst = (round + k) % len;
			int val = nums[src];

			for (int mov = 0; mov < len / mcd; mov++)
			{
				int tmp = nums[dst];
				nums[dst] = val;
				val = tmp;
				dst = (dst + k) % len;
			}
		}
	}
};

int main()
{
	Solution solution;


	while (getchar());

	return 0;
}