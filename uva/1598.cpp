#include <algorithm>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
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

#define fi first
#define se second
#define FO(x, n) for (int x = 0; x < n; ++x)
#define FOR(x, a, b) for (int x = a; x < b; ++x)
#define RFO(x, n) for (int x = n - 1; x >= 0; --x)
#define RFOR(x, a, b) for (int x = b - 1; x >= a; --x)
typedef unsigned char byte;
typedef unsigned int uint;
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

int N;
const int BUY = 0, SEL = 1;
struct Val
{
    int sz, price, type;
    bool cancel;
    Val() : sz(0), price(0), cancel(false) {}
};
vector<Val> vals;
struct CmpBuy
{
    bool operator()(const int& lhs, const int& rhs)
    {
        return vals[lhs].price < vals[rhs].price ||
            (vals[lhs].price == vals[rhs].price && lhs > rhs);
    }
};
struct CmpSel
{
    bool operator()(const int& lhs, const int& rhs)
    {
        return vals[lhs].price > vals[rhs].price ||
            (vals[lhs].price == vals[rhs].price && lhs > rhs);
    }
};
map<int, int> sum_buy, sum_sel;

int main()
{
    for (int t = 0; cin >> N; ++t)
    {
        if (t != 0)
            printf("\n");
        sum_buy.clear();
        sum_sel.clear();
        vals.clear();
        vals.push_back(Val());
        priority_queue<int, vector<int>, CmpBuy> buys;
        priority_queue<int, vector<int>, CmpSel> sels;
        FO (i, N)
        {
            string cmd;
            cin >> cmd;
            vals.push_back(Val());
            if (cmd == "SELL" || cmd == "BUY")
            {
                cin >> vals.back().sz >> vals.back().price;
                if (cmd == "SELL")
                {
                    vals.back().type = SEL;
                    sels.push(vals.size() - 1);
                    sum_sel[vals.back().price] += vals.back().sz;
                }
                else
                {
                    vals.back().type = BUY;
                    buys.push(vals.size() - 1);
                    sum_buy[vals.back().price] += vals.back().sz;
                }
                // trade
                while (true)
                {
                    while (buys.size() > 0 && vals[buys.top()].cancel)
                        buys.pop();
                    while (sels.size() > 0 && vals[sels.top()].cancel)
                        sels.pop();
                    if (sels.size() == 0 || buys.size() == 0 || vals[buys.top()].price < vals[sels.top()].price)
                        break;
                    int vol = min(vals[buys.top()].sz, vals[sels.top()].sz);
                    int pr = (cmd == "SELL") ? vals[buys.top()].price : vals[sels.top()].price;
                    printf("TRADE %d %d\n", vol, pr);
                    vals[buys.top()].sz -= vol;
                    vals[sels.top()].sz -= vol;
                    sum_buy[vals[buys.top()].price] -= vol;
                    sum_sel[vals[sels.top()].price] -= vol;
                    if (vals[buys.top()].sz == 0)
                        buys.pop();
                    if (vals[sels.top()].sz == 0)
                        sels.pop();
                }
            }
            else
            {
                int id;
                cin >> id;
                if (!vals[id].cancel)
                {
                    vals[id].cancel = true;
                    if (vals[id].type == BUY)
                        sum_buy[vals[id].price] -= vals[id].sz;
                    else
                        sum_sel[vals[id].price] -= vals[id].sz;
                }
            }
            // quote
            int bid_sz = 0, bid_pr = 0, ask_sz = 0, ask_pr = 99999;
            for (auto it = sum_buy.rbegin(); it != sum_buy.rend(); ++it)
                if (it->second != 0)
                {
                    bid_pr = it->first;
                    bid_sz = it->second;
                    break;
                }
            for (auto it = sum_sel.begin(); it != sum_sel.end(); ++it)
                if (it->second != 0)
                {
                    ask_pr = it->first;
                    ask_sz = it->second;
                    break;
                }
            printf("QUOTE %d %d - %d %d\n", bid_sz, bid_pr, ask_sz, ask_pr);
        }
    }
    return 0;
}