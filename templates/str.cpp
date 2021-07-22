#include <cmath>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

string rand_str(int len, int chr = 26) {
  string res(len, '\0');
  for (int i = 0; i < len; ++i)
    res[i] = 'a' + (rand() % chr);
  return res;
}

class Kmp {
  public:
    Kmp(const string& pattern) : p(pattern), f(p.size() + 1, 0) {
      for (int i = 1; i < p.size(); ++i) {
        int j = f[i];
        while (j && p[i] != p[j])
          j = f[j];
        if (p[i] == p[j])
          f[i + 1] = j + 1;
      }
    }

    int match(const string& s) const {
      int j = 0;
      for (int i = 0; i < s.size(); ++i) {
        while (j && s[i] != p[j])
          j = f[j];
        if (s[i] == p[j]) {
          if (++j == p.size())
            return i - p.size() + 1;
        }
      }
      return -1;
    }

    // common[i] is the length of longest common prefix&suffix of pattern[0,i].
    string p;
    vector<int> f;
};

void test_kmp() {
  srand(time(NULL));
  for (int i = 0; i < 100; ++i) {
    string p = rand_str(rand() % 10 + 1, 5);
    string s = rand_str(rand() % 100 + 1, 5);
    int kmp = Kmp(p).match(s);

    int bf = -1;
    for (int i = 0; i + p.size() <= s.size(); ++i) {
      int j = 0;
      for (; j < p.size(); ++j) {
        if (s[i + j] != p[j])
          break;
      }
      if (j == p.size()) {
        bf = i;
        break;
      }
    }
    assert(bf == kmp);
  }
}

class Ac {
  public:
    struct Trie {
      int last = 0; // point to longest pattern suffix.
      int pattern = -1;
      int children[26] = {0};
    };

    Ac(const vector<string>& patterns) : ps(patterns), tries(1) {
      for (int i = 0; i < ps.size(); ++i) {
        int cur = 0;
        for (char c : ps[i]) {
          if (tries[cur].children[c - 'a'] == 0) {
            tries[cur].children[c - 'a'] = tries.size();
            tries.push_back(Trie());
          }
          cur = tries[cur].children[c - 'a'];
        }
        tries[cur].pattern = i;
      }
      f = vector<int>(tries.size(), 0);
      deque<int> bfs = {0};
      while (!bfs.empty()) {
        int cur = bfs.front();
        bfs.pop_front();
        for (int i = 0; i < 26; ++i) {
          if (tries[cur].children[i] == 0)
            continue;
          int nxt = tries[cur].children[i];
          bfs.push_back(nxt);
          if (cur == 0)
            continue;
          int j = f[cur];
          while (j && tries[j].children[i] == 0)
            j = f[j];
          f[nxt] = j = tries[j].children[i];
          tries[nxt].last = (tries[j].pattern != -1 ) ? j : tries[j].last;
        }
      }
    }

    vector<pair<int, int>> match(const string& s) const {
      vector<pair<int, int>> res;
      int j = 0;
      for (int i = 0; i < s.size(); ++i) {
        while (j && tries[j].children[s[i] - 'a'] == 0)
          j = f[j];
        j = tries[j].children[s[i] - 'a'];
        int last = (tries[j].pattern != -1) ? j : tries[j].last;
        while (last) {
          int p = tries[last].pattern;
          res.push_back({i - ps[p].size() + 1, p});
          last = tries[last].last;
        }
      }
      return res;
    }

    vector<string> ps;
    vector<Trie> tries;
    vector<int> f;
};

void test_ac() {
  for (int i = 0; i < 100; ++i) {
    vector<string> ps(rand() % 30);
    for (int j = 0; j < ps.size(); ++j)
      ps[j] = rand_str(rand() % 10 + 1, 7);
    sort(ps.begin(), ps.end());
    ps.resize(unique(ps.begin(), ps.end()) - ps.begin());
    string s = rand_str(rand() % 1000);

    vector<pair<int, int>> res;
    for (int j = 0; j < s.size(); ++j) {
      for (int k = 0; k < ps.size(); ++k) {
        if (j + ps[k].size() > s.size())
          continue;
        if (string_view(&s[0] + j, ps[k].size()) == ps[k])
          res.push_back({j, k});
      }
    }

    Ac ac(ps);
    vector<pair<int, int>> res2 = ac.match(s);

    sort(res.begin(), res.end());
    sort(res2.begin(), res2.end());

    assert(res == res2);
  }
}

int main() {
  //test_kmp();
  test_ac();
  return 0;
}
