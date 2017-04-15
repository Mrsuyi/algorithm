#include <iostream>
#include <array>
using namespace std;

typedef long long ll;
typedef array<array<ll, 64>, 64> Matrix;

Matrix mul(const Matrix& a, const Matrix& b)
{
	Matrix res = { 0 };
	for (int i = 0; i < 64; ++i)
		for (int j = 0; j < 64; ++j)
		{
			for (int k = 0; k < 64; ++k)
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % 1000000007;
		}
	return res;
}

Matrix calc(const Matrix& a, int N)
{
	if (N == 1)
		return a;
	Matrix half = calc(a, N / 2);
	Matrix res = mul(half, half);
	if (N % 2)
		res = mul(res, a);
	return res;
}

int dirs[8][2] = { { 2, 1 },{ 2, -1 },{ -2, 1 },{ -2, -1 },{ 1, 2 },{ 1, -2 },{ -1, 2 },{ -1, -2 } };

int main()
{
	int N, R, C;
	cin >> N >> R >> C;

	Matrix conns = { 0 };
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
		{
			for (int k = 0; k < 8; ++k)
			{
				int p = i + dirs[k][0];
				int q = j + dirs[k][1];
				if (p >= 0 && p < 8 && q >= 0 && q < 8)
				{
					int a = 8 * i + j;
					int b = 8 * p + q;
					conns[a][b] = conns[b][a] = 1;
				}
			}
		}
	conns = calc(conns, N);
	ll res = 0;
	for (int i = 0; i < 64; ++i)
		res = (res + conns[(R - 1) * 8 + (C - 1)][i]) % 1000000007;
	cout << res << endl;
	system("PAUSE");
	return 0;
}
