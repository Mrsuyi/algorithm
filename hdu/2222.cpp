#include <climits>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <functional>
#define fi first
#define se second
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FO(i, n) for (int i = 0; i < n; ++i)
#define RFO(i, n) for (int i = n - 1; i >= 0; --i)
using namespace std;
typedef unsigned char byte;
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> pii;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }
const int INF = 0x07070707;

int N;
char words[10010][55];
char str[1000010];
struct Trie
{
	int fail;
	int children[26];
	int cnt;
	Trie()
	{
		fail = 0;
		cnt = 0;
		memset(children, -1, sizeof(children));
	}
} tries[500500];
int tot = 1;
int que[500500];

int match()
{
	tries[0] = Trie();
	tot = 1;
	// build
	FO (i, N)
	{
		int cur = 0;
		for (int j = 0; words[i][j] != '\0'; ++j)
		{
			if (tries[cur].children[words[i][j] - 'a'] == -1)
			{
				tries[tot] = Trie();
				tries[cur].children[words[i][j] - 'a'] = tot++;
			}
			cur = tries[cur].children[words[i][j] - 'a'];
		}
		++tries[cur].cnt;
	}
	// make fail
	int l = 0, r = 1;
	que[0] = 0;
	while (l < r)
	{
		int cur = que[l++];
		FO (i, 26)
		{
			if (tries[cur].children[i] == -1)
				continue;
			int pa = cur;
			while (pa != 0)
			{
				pa = tries[pa].fail;
				if (tries[pa].children[i] != -1)
				{
					tries[tries[cur].children[i]].fail = tries[pa].children[i];
					break;
				}
			}
			que[r++] = tries[cur].children[i];
		}
	}
	// search
	int res = 0;
	for (int i = 0, cur = 0; str[i] != '\0'; ++i)
	{
		while (tries[cur].children[str[i] - 'a'] == -1 && cur != 0)
			cur = tries[cur].fail;
		cur = tries[cur].children[str[i] - 'a'];
		cur = cur == -1 ? 0 : cur;
		int tmp = cur;
		while (tmp != 0 && tries[tmp].cnt != -1)
		{
			res += tries[tmp].cnt;
			tries[tmp].cnt = -1;
			tmp = tries[tmp].fail;
		}
	}
	return res;
}

int main()
{
	int T;
	cin >> T;
	FO (t, T)
	{
		cin >> N;
		memset(words, 0, sizeof(words));
		memset(str, 0, sizeof(str));
		FO (i, N)
			cin >> words[i];
		cin >> str;
		printf("%d\n", match());
	}
	return 0;
}