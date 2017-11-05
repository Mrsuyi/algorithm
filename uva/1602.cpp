#include <algorithm>
#include <array>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
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
using namespace std;

#define FO(x, n) for (int x = 0; x < n; ++x)
typedef long long llong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int INF = 0x0f0f0f0f, MOD = 1e9 + 7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 15;
int res[MAXN][MAXN][MAXN];
int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int N, W, H;

typedef pii Cell;
typedef set<Cell> Shape;
set<Shape> shapes[MAXN];

Shape normalize(const Shape& s)
{
    int mx = 0, my = 0;
    for (const Cell& c : s)
    {
        mx = min(mx, c.first);
        my = min(my, c.second);
    }
    Shape res;
    for (const Cell& c : s)
        res.insert(Cell(c.first - mx, c.second - my));
    return res;
}

Shape rotate(Shape& s)
{
    Shape res;
    for (const Cell& c : s)
        res.insert(Cell(c.second, -c.first));
    return res;
}

Shape flip(Shape& s)
{
    Shape res;
    for (const Cell& c : s)
        res.insert(Cell(c.first, -c.second));
    return res;
}

void ins(const Shape& s, int n)
{
    Shape ss = s;
    for (int i = 0; i < 2; ++i, ss = flip(ss))
    for (int j = 0; j < 4; ++j)
    {
        ss = normalize(rotate(ss));
        if (shapes[n].count(ss))
            return;
    }
    shapes[n].insert(normalize(s));
}

void calc()
{
    shapes[1].insert({Cell(0, 0)});
    for (int i = 2; i <= 10; ++i)
    {
        for (const Shape& s : shapes[i - 1])
        {
            for (const Cell& c : s)
            {
                for (int j = 0; j < 4; ++j)
                {
                    Cell newc(c.first + dirs[j][0], c.second + dirs[j][1]);
                    if (!s.count(newc))
                    {
                        Shape news = s;
                        news.insert(newc);
                        ins(news, i);
                    }
                }
            }
        }
    }
    for (int i = 1; i <= 10; ++i)
    for (int w = 1; w <= 10; ++w)
    for (int h = 1; h <= 10; ++h)
    {
        int cnt = 0;
        for (const Shape& shape : shapes[i])
        {
            int mx = 0, my = 0;
            for (const Cell& c : shape)
            {
                mx = max(mx, c.first);
                my = max(my, c.second);
            }
            if (min(mx, my) < min(w, h) && max(mx, my) < max(w, h))
                ++cnt;
        }
        res[i][w][h] = cnt;
    }
}

int main()
{
    calc();
    while (cin >> N >> W >> H)
        cout << res[N][W][H] << endl;
    return 0;
}