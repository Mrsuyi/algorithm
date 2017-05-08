#include <climits>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
typedef unsigned char byte;
typedef long long llong;
typedef unsigned long long ullong;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

string s;
bool vars[128];

bool ok(int& i)
{
	if (s[i] >= 'a' && s[i] <= 'z')
		return vars[s[i++]];
	else if (s[i] == 'N')
		return !ok(++i);
	char c = s[i++];
	bool l = ok(i);
	bool r = ok(i);
	switch (c)
	{
		case 'K': return l && r;
		case 'A': return l || r;
		case 'C': return !(l && !r);
		case 'E': return !(l ^ r);
	}
}

int main()
{
	while (cin >> s)
	{
		if (s == "0")
			break;
		int i;
		for (i = 0; i < 32; ++i)
		{
			vars['p'] = i & (1 << 0);
			vars['q'] = i & (1 << 1);
			vars['r'] = i & (1 << 2);
			vars['s'] = i & (1 << 3);
			vars['t'] = i & (1 << 4);
			
			int idx = 0;
			if (!ok(idx))
				break;
		}
		if (i == 32)
			cout << "tautology" << endl;
		else
			cout << "not" << endl;
	}
    return 0;
};