#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	void rotate(vector<int>& nums, int k)
	{
		k %= nums.size();

		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());
	}
};

int main()
{
	Solution solution;


	while (getchar());

	return 0;
}