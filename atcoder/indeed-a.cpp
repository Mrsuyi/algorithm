#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int pres[4][2] = {{3, 1}, {0, -1}, {1, -1}, {2, 1}};
int cur[4][2] = {{1, 1}, {0, 1}, {1, -1}, {0, -1}};

int main()
{
    int n, m;
    cin >> n >> m;
    int border[4] = {n, n, 1, 1};
    int dir = 0;
    vector<int> pos = {1, 1};
    while (--m)
    {
        if (pos[cur[dir][0]] == border[dir])
        {
            border[pres[dir][0]] += pres[dir][1];
            dir = (dir + 1) % 4;
        }
        pos[cur[dir][0]] += cur[dir][1];
    }
    cout << pos[0] << " " << pos[1] << endl;
    
    return 0;
};