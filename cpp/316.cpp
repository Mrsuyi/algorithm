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
	string removeDuplicateLetters(string s)
	{
		int len = s.length();

		int cnt[26] = { 0 };
		stack<char> stk;
		set<char> set;

		for (int i = 0; i < len; i++)
		{
			cnt[s[i] - 'a']++;
		}

		for (auto c : s)
		{
			cnt[c - 'a']--;
			
			if (set.find(c) != set.end()) continue;

			while (!stk.empty() && stk.top() > c && cnt[stk.top() - 'a'])
			{
				set.erase(stk.top());
				stk.pop();
			}
			stk.push(c);
			set.emplace(c);
		}
		string ret;
		while (!stk.empty())
		{
			ret += stk.top();
			stk.pop();
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};

int main()
{
	while (getchar());

	return 0;
}