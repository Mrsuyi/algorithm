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

int T, N;
string input;
int a[110][110], b[110][110];

void mul(int a[110][110], int b[110][110])
{
	int tmp[110][110] = {0};
	FO (i, N) FO (j, N) FO (k, N)
		tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % 2;
	memcpy(a, tmp, sizeof(tmp));
}

int main()
{
	while (cin >> T)
	{
		cin >> input;
		N = input.size();
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		FO (i, N)
		{
			a[i][i] = 1;
			a[i][(i + 1) % N] = 1;
			b[i][i] = 1;
		}
		for (; T; T >>= 1)
		{
			if (T & 1)
				mul(b, a);
			mul(a, a);
		}
		FO (i, N)
		{
			int res = 0;
			FO (j, N)
				res += (input[j] - '0') * b[j][i];
			cout << char('0' + (res % 2));
		}
		cout << endl;
	}
	return 0;
}