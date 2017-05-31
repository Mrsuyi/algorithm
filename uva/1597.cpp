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

int N, M;
unordered_map<string, map<int, set<int>>> mp;
vector<vector<string>> docs;

int main()
{
    scanf("%d\n", &N);
    docs = vector<vector<string>>(N);
    for (int doc = 0; N--; ++doc)
    {
        string s;
        for (int line = 0; getline(cin, s); ++line)
        {
            if (s == "**********")
                break;
            docs[doc].push_back(s);
            FO (i, s.size())
                if (isalpha(s[i]))
                    s[i] = tolower(s[i]);
                else
                    s[i] = ' ';
            stringstream ss(s);
            string word;
            while (ss >> word)
                mp[word][doc].insert(line);
        }
    }
    scanf("%d\n", &M);
    while (M--)
    {
        string s, word;
        getline(cin, s);
        FO (i, s.size())
            if (isalpha(s[i]))
                s[i] = tolower(s[i]);
        vector<string> ws;
        stringstream ss(s);
        while (ss >> word)
            ws.push_back(word);
        if (ws.size() == 1)
        {
            if (mp[ws[0]].size() == 0)
            {
                printf("Sorry, I found nothing.\n");
                goto end;
            }
            bool first = true;
            for (auto& doc : mp[ws[0]])
            {
                if (first)
                    first = false;
                else
                    printf("----------\n");
                for (int line : doc.second)
                    cout << docs[doc.first][line] << endl;
            }
        }
        else if (ws.size() == 2)
        {
            if (mp[ws[1]].size() == docs.size())
            {
                printf("Sorry, I found nothing.\n");
                goto end;
            }
            bool first = true;
            FO (i, docs.size())
            {
                if (!mp[ws[1]].count(i))
                {
                    if (first)
                        first = false;
                    else
                        printf("----------\n");
                    FO (j, docs[i].size())
                        cout << docs[i][j] << endl;
                }
            }
        }
        else
        {
            string w1 = ws[0], w2 = ws[2], cond = ws[1];
            map<int, set<int>> out;
            if (cond == "and")
            {
                for (auto& doc : mp[w1])
                    if (mp[w2].count(doc.first))
                    {
                        for (int line : doc.second)
                            out[doc.first].insert(line);
                        for (int line : mp[w2][doc.first])
                            out[doc.first].insert(line);
                    }
            }
            else if (cond == "or")
            {
                for (auto& doc : mp[w1])
                    for (int line : doc.second)
                        out[doc.first].insert(line);
                for (auto& doc : mp[w2])
                    for (int line : doc.second)
                        out[doc.first].insert(line);
            }
            if (out.size() == 0)
            {
                printf("Sorry, I found nothing.\n");
                goto end;
            }
            bool first = true;
            for (auto& doc : out)
            {
                if (first)
                    first = false;
                else
                    printf("----------\n");
                for (int line : doc.second)
                    cout << docs[doc.first][line] << endl;
            }
        }
        end:;
        printf("==========\n");
    }
    return 0;
}