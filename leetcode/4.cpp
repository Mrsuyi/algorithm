#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

class Solution
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int len = nums1.size() + nums2.size();
		vector<int> nums(len);
		merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums.begin());
		return len & 1 ? nums[len / 2] : (double)(nums[len / 2 - 1] + nums[len / 2]) / 2;
	}
};

int main()
{
	while (getchar());

	return 0;
}