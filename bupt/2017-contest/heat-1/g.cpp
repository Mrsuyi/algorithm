#include <iostream>
#include <climits>
using namespace std;

long long gcd(long long a, long long b)
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
		long long up = 1, dn = -1;
		for (int i = 0; i < n; ++i)
		{
			long long a, b;
			cin >> a >> b;
			if (up % a != 0)
				up *= a / gcd(up, a);
			if (dn == -1)
				dn = b;
			else
				dn = gcd(dn, b);
		}
		long long updn = gcd(up, dn);
		cout << (up / updn) << " " << (dn / updn) << endl;
	}

	return 0;
}