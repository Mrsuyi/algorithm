#include <algorithm>
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

const int ASSIGN = 0;
const int OUTPUT = 1;
const int LOCK = 2;
const int UNLOCK = 3;
const int END = 4;
int cost[6];
unordered_map<string, int> mp;
struct Cmd
{
    int type;
    char var;
    int val;
};
struct Prog
{
    int id, idx;
    vector<Cmd> cmds;
    Prog() : idx(0) {}
};

int T, N, P;
int vals[128];
bool locked[128];

int main()
{
    mp["lock"] = LOCK;
    mp["unlock"] = UNLOCK;
    mp["print"] = OUTPUT;
    mp["end"] = END;

    cin >> T;
    FO (t, T)
    {
        if (t != 0)
            cout << endl;
        memset(vals, 0, sizeof(vals));
        memset(locked, 0, sizeof(locked));
        scanf("%d %d %d %d %d %d %d\n", &N, &cost[0], &cost[1], &cost[2], &cost[3], &cost[4], &P);
        deque<int> ready;
        queue<int> block;
        vector<Prog> progs(1);
        FO (i, N)
        {
            progs.push_back(Prog());
            progs.back().id = i + 1;
            string s;
            while (getline(cin, s))
            {
                Cmd cmd;
                if (s.find('=') != string::npos)
                {
                    cmd.type = ASSIGN;
                    cmd.var = s[0];
                    cmd.val = stoi(s.substr(4));
                }
                else
                {
                    cmd.type = mp[s.substr(0, s.find(' '))];
                    if (cmd.type != END)
                        cmd.var = s[s.size() - 1];
                }
                progs.back().cmds.push_back(cmd);
                if (cmd.type == END)
                    break;
            }
            ready.push_back(i + 1);
        }
        while (!ready.empty())
        {
            Prog& prog = progs[ready.front()];
            ready.pop_front();
            if (prog.cmds.size() == 0)
                continue;
            for (int p = P; p > 0 && prog.idx < prog.cmds.size();)
            {
                Cmd& cmd = prog.cmds[prog.idx];
                switch (cmd.type)
                {
                    case ASSIGN:
                        vals[cmd.var] = cmd.val;
                        ++prog.idx;
                        break;
                    case OUTPUT:
                        printf("%d: %d\n", prog.id, vals[cmd.var]);
                        ++prog.idx;
                        break;
                    case LOCK:
                        if (!locked[cmd.var])
                        {
                            locked[cmd.var] = true;
                            ++prog.idx;
                            break;
                        }
                        else
                        {
                            block.push(prog.id);
                            goto end;
                        }
                    case UNLOCK:
                        if (!block.empty())
                        {
                            ready.push_front(block.front());
                            block.pop();
                        }
                        locked[cmd.var] = false;
                        ++prog.idx;
                        break;
                    case END:
                        ++prog.idx;
                        break;
                    default:;
                }
                p -= cost[cmd.type];
            }
            if (prog.idx < prog.cmds.size())
                ready.push_back(prog.id);
            end:;
        }
    }
    return 0;
}