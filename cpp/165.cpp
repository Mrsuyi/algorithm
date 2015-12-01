#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	int compareVersion(string version1, string version2)
	{
		int i1 = 0, i2 = 0, v1 = 0, v2 = 0;

		for (; i1 < version1.size() || i2 < version2.size(); i1++, i2++)
		{
			v1 = 0;
			v2 = 0;

			while (i1 < version1.size() && version1[i1] != '.')
			{
				v1 = v1 * 10 + version1[i1] - '0';
				i1++;
			}

			while (i2 < version2.size() && version2[i2] != '.')
			{
				v2 = v2 * 10 + version2[i2] - '0';
				i2++;
			}
			
			if (v1 != v2) return v1 > v2 ? 1 : -1;
		}
		return 0;
	}
};

int main()
{
	Solution solution;

	string i1, i2;

	while (true)
	{
		cin >> i1;
		cin >> i2;

		cout << solution.compareVersion(i1, i2) << endl;
	}

	while (getchar());

	return 0;
}