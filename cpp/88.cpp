#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		int fill = m + n - 1;
		int i1 = m - 1;
		int i2 = n - 1;

		while (i1 >= 0 && i2 >= 0)
		{
			int a = nums1[i1];
			int b = nums2[i2];

			if (a > b)
			{
				nums1[fill] = a;
				i1--;
			}
			else
			{
				nums1[fill] = b;
				i2--;
			}

			fill--;
		}

		if (i1 >= 0)
		{
			while (i1 >= 0) nums1[fill--] = nums1[i1--];
		}
		else
		{
			while (i2 >= 0) nums1[fill--] = nums2[i2--];
		}
	}
};

int main()
{
	Solution solution;

	vector<int> a = { 0 };
	vector<int> b = { 1 };

	solution.merge(a, 0, b, 1);

	for (auto i = a.begin(); i != a.end(); i++) { cout << *i << ' '; }

	while (getchar());

	return 0;
}