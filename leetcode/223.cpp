#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
	{
		int s_1 = (C - A) * (D - B);
		int s_2 = (G - E) * (H - F);

		int cover = 0;

		int left = A > E ? A : E;
		int right = C < G ? C : G;

		if (left < right)
		{
			int top = D < H ? D : H;
			int bottom = B > F ? B : F;

			if (top > bottom)
			{
				cover = (right - left) * (top - bottom);
			}
		}

		return s_1 + s_2 - cover;
	}
};

int main()
{
	Solution solution;


	while (getchar());

	return 0;
}