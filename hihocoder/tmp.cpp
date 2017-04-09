#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;
int dirs[8][2] = { {-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2} };
ll matrix[64][64] = { 0 };
size_t sz = 64 * sizeof(ll);

void mul(ll a[64][64], ll b[64][64])
{
	ll res[64][64] = {0};
	for (int i = 0; i < 64; ++i)
		for (int j = 0; j < 64; ++j)
		{
			for (int k = 0; k < 64; ++k)
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % 1000000007;
		}
	memcpy(res, a, sz);
}

void calc(ll a[64][64], int N)
{
	if (N <= 1)
		return;
	if (N % 2)
	{
		ll tmp[64][64];
		memcpy(a, tmp, sz);
		calc(a, N / 2);
		mul(a, a);
		mul(a, tmp);
	}
	else
	{
		calc(a, N / 2);
		mul(a, a);
	}
}

int main()
{
	int N, R, C;
	cin >> N >> R >> C;
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
			for (int k = 0; k < 8; ++k)
			{
				int p = i + dirs[k][0];
				int q = j + dirs[k][1];
				if (p >= 0 && p < 8 && q >= 0 && q < 8)
					matrix[8 * i + j][8 * p + q] = matrix[8 * p + q][8 * i + j] = 1;
			}
	calc(matrix, N);
	ll res = 0;
	for (int i = 0; i < 64; ++i)
		res += matrix[8 * (R - 1) + (C - 1)][i];
	cout << (res % 1000000007) << endl;
	system("PAUSE");
	return 0;
}