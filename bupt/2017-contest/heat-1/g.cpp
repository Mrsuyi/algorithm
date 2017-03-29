#include <iostream>
#include <climits>
using namespace std;

int gcd(int a, int b)
{
	if (a < b) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	int n;
	while (cin >> n)
	{
		int up = 1, dn = INT_MAX;
		for (int i = 0; i < n; ++i)
		{
			int a, b;
			cin >> a >> b;
			if (up % a != 0)
				up *= a / gcd(up, a);
			dn = gcd(dn, b);
		}
		int updn = gcd(up, dn);
		cout << (up / updn) << " " << (dn / updn) << endl;
	}

	return 0;
}