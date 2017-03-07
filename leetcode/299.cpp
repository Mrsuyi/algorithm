#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <functional>

using namespace std;

class Solution
{
public:
	string getHint(string secret, string guess)
	{
		int bull = 0, cow = 0;

		int cnt[10] = { 0 };

		for (int i = 0; i < secret.size(); i++)
		{
			if (guess[i] == secret[i])
			{
				bull++;
			}
			else
			{
				cnt[secret[i] - '0']++;
			}
		}

		for (int i = 0; i < secret.size(); i++)
		{
			char c = guess[i];
			if (c != secret[i] && cnt[c - '0'])
			{
				cow++;
				cnt[c - '0']--;
			}
		}

		return to_string(bull) + "A" + to_string(cow) + "B";
	}
};

int main()
{
	while (getchar());

	return 0;
}