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
	int maxProduct(vector<string>& words)
	{
		int size = words.size();
		vector<unsigned> letter(size, 0);
		vector<int> len(size, 0);

		for (int i = 0; i < size; i++)
		{
			unsigned l = 0;
			for (auto c : words[i])
			{
				l |= 1 << (c - 'a');
			}
			letter[i] = l;
			len[i] = words[i].size();
		}

		int ret = 0;
		for (int i = 0; i < size; i++)
		for (int j = i + 1; j < size; j++)
		{
			if (!(letter[i] & letter[j]))
			{
				int mul = len[i] * len[j];
				if (mul > ret) ret = mul;
			}
		}
		return ret;
	}
};

int main()
{
	while (getchar());

	return 0;
}