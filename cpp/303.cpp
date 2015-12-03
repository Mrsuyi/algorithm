#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class NumArray
{
public:
	int* sum;

	NumArray(vector<int> &nums)
	{
		this->sum = new int[nums.size()];
		int add = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			sum[i] = add += nums[i];
		}
	}

	int sumRange(int i, int j)
	{
		return i == 0 ? sum[j] : sum[j] - sum[i - 1];
	}
};

int main()
{

	while (getchar());

	return 0;
}