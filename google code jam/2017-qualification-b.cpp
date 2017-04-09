#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		string N;
		cin >> N;
        string res;
        for (int i = 0; i < N.size(); ++i)
        {
            if (i < N.size() - 1 && N[i] > N[i + 1])
            {
                res.push_back(N[i] - 1);
                res.resize(N.size(), '9');
                for (int j = i; j > 0 && res[j - 1] > res[j]; --j)
                {
                    res[j] = '9';
                    --res[j - 1];
                }
                break;
            }
            res.push_back(N[i]);
		}
		if (res[0] == '0')
			res = res.substr(1);
		printf("Case #%d: %s\n", t + 1, res.data());
	}

	return 0;
}