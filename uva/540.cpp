#include <climits>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <functional>

# ifdef __GNUC__
# if __cplusplus > 199711L
# include <unordered_set>
# include <unordered_map>
# else
# include <tr1/unordered_map>
# include <tr1/unordered_set>
using namespace tr1;
# endif
# else
# include <unordered_map>
# include <unordered_set>
# endif

#define fi first
#define se second
#define FO(x, n) for (int x = 0; x < n; ++x)
#define FOR(x, a, b) for (int x = a; x < b; ++x)
#define RFO(x, n) for (int x = n - 1; x >= 0; --x)
#define RFOR(x, a, b) for (int x = b - 1; x >= a; --x)
using namespace std;
typedef unsigned char byte;
typedef unsigned int uint;
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

int T;
unordered_map<int, queue<int>*> inq;
map<int, int> group;

int main()
{
    int c = 0;
    while (cin >> T)
    {
        ++c;
        queue<queue<int>> q;
        if (T == 0)
            break;
        inq.clear();
        group.clear();
        FO (t, T)
        {
            int cnt;
            cin >> cnt;
            FO (j, cnt)
            {
                int ele;
                cin >> ele;
                group[ele] = t;
            }
        }
        printf("Scenario #%d\n", c);
        for (string s;;)
        {
            cin >> s;
            if (s == "STOP")
                break;
            if (s == "ENQUEUE")
            {
                int ele;
                cin >> ele;
                if (inq[group[ele]])
                {
                    inq[group[ele]]->push(ele);
                }
                else
                {
                    q.push(queue<int>());
                    q.back().push(ele);
                    inq[group[ele]] = &(q.back());
                }
            }
            else if (s == "DEQUEUE")
            {
                int ele = q.front().front();
                printf("%d\n", ele);
                q.front().pop();
                if (q.front().size() == 0)
                {
                    q.pop();
                    inq[group[ele]] = NULL;
                }
            }
        }
        printf("\n");
    }
    return 0;
}