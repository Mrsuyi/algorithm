#include <climits>
#include <cstring>
#include <cmath>
#include <cfloat>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef unsigned char byte;
typedef long long llong;
typedef unsigned long long ullong;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;
		vector<int> nums(N);
		for (int i = 0; i < N; ++i)
			cin >> nums[i];
		vector<int> lefts, stuff;
		lefts.push_back(nums[0] - 1);
		stuff.push_back(1);
		cout << 1;
		for (int i = 1; i < N; ++i)
		{
			if (nums[i] > nums[i - 1])
			{
				lefts.push_back(nums[i] - nums[i - 1]);
				stuff.push_back(0);
			}
			while (*lefts.rbegin() == 0)
			{
				lefts.pop_back();
				int l = stuff.size();
				stuff[l - 2] += stuff[l - 1];
				stuff.pop_back();
			}
			--lefts.back();
			++stuff.back();
			cout << " " << (stuff.back());
		}
		cout << endl;
	}
    return 0;
};

// a smarter one
#include <climits>
#include <cstring>
#include <cmath>
#include <cfloat>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef unsigned char byte;
typedef long long llong;
typedef unsigned long long ullong;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;
		vector<int> nums(N + 1, 0);
		for (int i = 1; i <= N; ++i)
		{
			cin >> nums[i];
			int j = i - 1;
			while (nums[i] - nums[j] < i - j)
				--j;
			if (i == 1)
				cout << (i - j);
			else
				cout << " " << (i - j);
		}
		cout << endl;		
	}
    return 0;
};