#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	int N;
	cin >> N;
	unordered_map<int, int> row, col, dia1, dia2;
	for (int i = 0; i < N; ++i)
	{
		int R, C;
		cin >> R >> C;
		++row[R];
		++col[C];
		++dia1[R - C];
		++dia2[R + C];
	}
	long long res = 0;
	for (auto& p : row)
		res += p.second * (p.second - 1) / 2;
	for (auto& p : col)
		res += p.second * (p.second - 1) / 2;
	for (auto& p : dia1)
		res += p.second * (p.second - 1) / 2;
	for (auto& p : dia2)
		res += p.second * (p.second - 1) / 2;
	cout << res << endl;
	
	return 0;
}