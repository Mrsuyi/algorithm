#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		int R, C;
		cin >> R >> C;
		vector<string> matrix(R);
		for (int i = 0; i < R; ++i)
			cin >> matrix[i];
		vector<string> res(R, string(C, ' '));
		vector<bool> empty(R, true);
		int pending = 0;
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
				if (matrix[i][j] != '?')
				{
					empty[i] = false;
					break;
				}
			if (empty[i])
			{
				if (i > 0 && !empty[i - 1])
				{
					res[i] = res[i - 1];
					empty[i] = false;
				}
				else
					++pending;
			}
			else
			{
				int j = C - 1;
				while (matrix[i][j] == '?') --j;
				for (int k = j; k < C; ++k)
					res[i][k] = matrix[i][j];
				for (; j >= 0; --j)
					res[i][j] = matrix[i][j] == '?' ? res[i][j + 1] : matrix[i][j];
				if (pending > 0)
				{
					for (int k = 0; k < pending; ++k)
						res[k] = res[i];
					pending = 0;
				}
			}
		}
		printf("Case #%d:\n", t + 1);
		for (int i = 0; i < R; ++i)
			cout << res[i] << endl;
	}
	return 0;
}