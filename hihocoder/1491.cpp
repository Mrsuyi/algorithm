#include <iostream>
using namespace std;

int N, M;
int monh[7][7] = {0};
int mona[7][7] = {0};
int dp[1 << 21][7] = {0};
char map[7][7];
int total = 0;
int dx, dy;
int myh, mya;
int res = -1;
int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int mark(int status, int x, int y)
{
	return status | (1 << (x * M + y));
}
bool marked(int status, int x, int y)
{
	return status & (1 << (x * M + y));
}
int expand(int status, int x, int y)
{
	for (int i = 0; i < 4; ++i)
	{
		int p = x + dirs[i][0];
		int q = y + dirs[i][1];
		if (p >= 0 && p < N && q >= 0 && q < M)
			status = mark(status, p, q);
	}
	return status;
}

void dfs(int status, int flipable, int hp, int round, int rest)
{
	if (dp[status][round] >= hp)
		return;
	dp[status][round] = hp;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (!marked(status, i, j) && marked(flipable, i, j))
			{
				int r = std::max(round - 1, 0);
				int h = hp;
				int newstatus = mark(status, i, j);
				int newflipable = expand(flipable, i, j);
				
				// if is a monster
				if (map[i][j] == 'S' || map[i][j] == 'M')
				{
					for (int mh = monh[i][j]; mh > 0; mh -= mya)
					{
						if (r > 0)
							--r;
						else
							h -= mona[i][j];
					}
					if (h <= 0) continue;
					if (rest - 1 == 0)
						res = std::max(res, h);
					else
						dfs(newstatus, newflipable, h, map[i][j] == 'S' ? 5 : r, rest - 1);
				}
				// not a monster
				else
				{
					dfs(newstatus, newflipable, h, r, rest);
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; ++j)
		{
			map[i][j] = str[j];
			if (str[j] == 'M' || str[j] == 'S')
				++total;
			else if (str[j] == 'D')
			{
				dx = i;
				dy = j;
			}
		}
	}
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (map[i][j] == 'M' || map[i][j] == 'S')
				cin >> monh[i][j] >> mona[i][j];
	cin >> myh >> mya;
	
	int status = mark(0, dx, dy);
	int flipable = expand(0, dx, dy);
	dfs(status, flipable, myh, 5, total);
	if (res == -1)
		cout << "DEAD" << endl;
	else
		cout << res << endl;

	return 0;
}