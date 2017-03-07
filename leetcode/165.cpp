#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	int compareVersion(string version1, string version2)
	{
		int l1 = version1.size(), l2 = version2.size();

		for (int i1 = 0, i2 = 0; i1 < l1 || i2 < l2; i1++, i2++)
		{
			int n1 = 0, n2 = 0;

			while (i1 < l1 && version1[i1] != '.')
			{
				n1 = n1 * 10 + version1[i1++] - '0';
			}
			while (i2 < l2 && version2[i2] != '.')
			{
				n2 = n2 * 10 + version2[i2++] - '0';
			}

			if (n1 != n2) return n1 > n2 ? 1 : -1;
		}
		return 0;
	}
};

int main()
{
	while (getchar());

	return 0;
}