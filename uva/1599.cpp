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

unordered_map<int, string> no2name;
unordered_map<string, int> name2no;
unordered_set<int> has;
vector<vector<int>> dep;
vector<int> cnt;
vector<bool> expli;
int tot = 0;

int reg(const string& name)
{
    if (name2no.count(name))
        return name2no[name];
    int no = tot++;
    no2name[no] = name;
    name2no[name] = no;
    dep.resize(no + 1);
    cnt.resize(no + 1, 0);
    expli.resize(no + 1, false);
    return no;
}

void ins2(int no)
{
    ++cnt[no];
    if (has.count(no))
        return;
    FO (i, dep[no].size())
        ins2(dep[no][i]);
    printf("   Installing %s\n", no2name[no].data());
    has.insert(no);
}
void ins(int no)
{
    if (has.count(no))
        printf("   %s is already installed.\n", no2name[no].data());
    else
    {
        FO (i, dep[no].size())
            ins2(dep[no][i]);
        printf("   Installing %s\n", no2name[no].data());
        expli[no] = true;
        has.insert(no);
    }
}

void unins2(int no)
{
    if (!has.count(no) || cnt[no] > 0 || expli[no])
        return;
    printf("   Removing %s\n", no2name[no].data());
    has.erase(no);
    FO (i, dep[no].size())
    {
        --cnt[dep[no][i]];
        unins2(dep[no][i]);
    }
}
void unins(int no)
{
    if (!has.count(no))
        printf("   %s is not installed.\n", no2name[no].data());
    else if (cnt[no] > 0)
        printf("   %s is still needed.\n", no2name[no].data());
    else
    {
        expli[no] = false;
        unins2(no);
    }
}

int main()
{
    string s;
    while (getline(cin, s))
    {
        cout << s << endl;
        if (s == "END")
        {
            no2name.clear();
            name2no.clear();
            has.clear();
            dep.clear();
            cnt.clear();
            expli.clear();
            tot = 0;
            continue;
        }
        stringstream ss(s);
        string cmd;
        ss >> cmd;
        if (cmd == "DEPEND")
        {
            string hi;
            ss >> hi;
            int nohi = reg(hi);
            for (string lo; ss >> lo;)
            {
                int nolo = reg(lo);
                dep[nohi].push_back(nolo);
            }
        }
        else if (cmd == "INSTALL")
        {
            string name;
            ss >> name;
            ins(reg(name));
        }
        else if (cmd == "REMOVE")
        {
            string name;
            ss >> name;
            unins(reg(name));
        }
        else if (cmd == "LIST")
        {
            for (auto& no : has)
                cout << "   " << no2name[no] << endl;
        }
    }
    return 0;
}