#include <cmath>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

string rand_str(int len, int chr = 26) {
  string res(len, '\0');
  for (int i = 0; i < len; ++i) res[i] = 'a' + (rand() % chr);
  return res;
}

class Kmp {
 public:
  Kmp(const string& pattern) : p(pattern), f(p.size() + 1, 0) {
    for (int i = 1; i < p.size(); ++i) {
      int j = f[i];
      while (j && p[i] != p[j]) j = f[j];
      if (p[i] == p[j]) f[i + 1] = j + 1;
    }
  }

  int match(const string& s) const {
    int j = 0;
    for (int i = 0; i < s.size(); ++i) {
      while (j && s[i] != p[j]) j = f[j];
      if (s[i] == p[j]) {
        if (++j == p.size()) return i - p.size() + 1;
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
        if (s[i + j] != p[j]) break;
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
    int last = 0;  // point to longest pattern suffix.
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
        if (tries[cur].children[i] == 0) continue;
        int nxt = tries[cur].children[i];
        bfs.push_back(nxt);
        if (cur == 0) continue;
        int j = f[cur];
        while (j && tries[j].children[i] == 0) j = f[j];
        f[nxt] = j = tries[j].children[i];
        tries[nxt].last = (tries[j].pattern != -1) ? j : tries[j].last;
      }
    }
  }

  vector<pair<int, int>> match(const string& s) const {
    vector<pair<int, int>> res;
    int j = 0;
    for (int i = 0; i < s.size(); ++i) {
      while (j && tries[j].children[s[i] - 'a'] == 0) j = f[j];
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
    for (int j = 0; j < ps.size(); ++j) ps[j] = rand_str(rand() % 10 + 1, 7);
    sort(ps.begin(), ps.end());
    ps.resize(unique(ps.begin(), ps.end()) - ps.begin());
    string s = rand_str(rand() % 1000);

    vector<pair<int, int>> res;
    for (int j = 0; j < s.size(); ++j) {
      for (int k = 0; k < ps.size(); ++k) {
        if (j + ps[k].size() > s.size()) continue;
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

class Sam {
 public:
  struct Trie {
    int len = 0;  // len of the max suffix.
    int link = -1;
    int children[26] = {0};

    int first_pos = -1;
    bool is_clone = false;
    vector<int> inv_link;
    int pos_cnt = 0;
  };

  Sam(const string& text) : t(text) {
    tries.push_back(Trie());
    int last = 0;
    for (int i = 0; i < t.size(); ++i) {
      int cur = tries.size();
      tries.push_back(Trie());
      tries[cur].len = i + 1;
      tries[cur].first_pos = i;
      int p = last;

      int c = t[i] - 'a';
      while (p != -1 && tries[p].children[c] == 0) {
        tries[p].children[c] = cur;
        p = tries[p].link;
      }
      if (p == -1) {
        tries[cur].link = 0;
      } else {
        int q = tries[p].children[c];
        if (tries[q].len == tries[p].len + 1) {
          tries[cur].link = q;
        } else {
          int clone = tries.size();
          tries.push_back(Trie(tries[q]));
          tries[clone].len = tries[p].len + 1;
          tries[clone].first_pos = tries[q].first_pos;
          tries[clone].is_clone = true;
          while (p != -1 && tries[p].children[c] == q) {
            tries[p].children[c] = clone;
            p = tries[p].link;
          }
          tries[q].link = tries[cur].link = clone;
        }
      }
      last = cur;
    }

    for (int i = tries.size() - 1; i > 0; --i) {
      tries[tries[i].link].inv_link.push_back(i);
    }
    pos_cnt(0);
  }

  int pos_cnt(int u) {
    tries[u].pos_cnt = !tries[u].is_clone;
    for (int v : tries[u].inv_link) {
      tries[u].pos_cnt += pos_cnt(v);
    }
    return tries[u].pos_cnt;
  }

  void print() const {
    for (int u = 0; u < tries.size(); ++u) {
      string schild;
      for (int i = 0; i < 26; ++i) {
        if (tries[u].children[i] != 0) {
          if (!schild.empty()) schild += ", ";
          schild += string(1, 'a' + i) + "->" +
                    to_string(tries[u].children[i]) + ", ";
        }
      }
      string sposs;
      if (u != 0) {
        vector<int> poss = all_pos(u);
        int len = tries[u].len;
        sort(poss.begin(), poss.end());
        int j = 0;
        for (int i = 0; i < poss.size(); ++i) {
          int bgn = poss[i] - len + 1;
          if (j < bgn) sposs += t.substr(j, bgn - j);
          while (i + 1 < poss.size() && poss[i + 1] - len + 1 < poss[i]) ++i;
          int end = poss[i];
          sposs += "{" + t.substr(bgn, end - bgn + 1) + "}";
          j = end + 1;
        }
        sposs += t.substr(j);
      }
      printf(
          "%d len: %d link: %d first_pos: %d is_clone: %d, children: %s "
          "poss: %s cnt:%d\n",
          u, tries[u].len, tries[u].link, tries[u].first_pos, tries[u].is_clone,
          schild.c_str(), sposs.c_str(), tries[u].pos_cnt);
    }
  }

  vector<int> all_pos(int u) const {
    vector<int> res, bfs = {u};
    while (!bfs.empty()) {
      int cur = bfs.back();
      bfs.pop_back();
      if (!tries[cur].is_clone) res.push_back(tries[cur].first_pos);
      for (int v : tries[cur].inv_link) bfs.push_back(v);
    }
    return res;
  }

  vector<string> longest_substr(const string& s) const {
    vector<string> res(s.size());
    int cur = 0;
    int len = 0;
    for (int i = 0; i < s.size(); ++i) {
      int c = s[i] - 'a';
      while (cur != 0 && tries[cur].children[c] == 0) {
        cur = tries[cur].link;
        len = tries[cur].len;
      }
      if (tries[cur].children[c] != 0) {
        cur = tries[cur].children[c];
        ++len;
      }
      if (len > 0) res[i] = t.substr(tries[cur].first_pos - len + 1, len);
    }
    return res;
  }

  vector<Trie> tries;
  vector<vector<int>> cnt_idxs;
  string t;
};

void test_sam() {
  for (int i = 0; i < 100; ++i) {
    string p = rand_str(rand() % 20 + 1, 7);
    string s = rand_str(rand() % 100 + 1, 7);
    printf("Test case #%d: '%s' in %s\n", i, p.data(), s.data());

    vector<string> subs;
    for (int l = 0; l < p.size(); ++l) {
      for (int r = l; r < p.size(); ++r) {
        subs.push_back(p.substr(l, r - l + 1));
      }
    }
    sort(subs.begin(), subs.end());
    subs.resize(unique(subs.begin(), subs.end()) - subs.begin());
    sort(subs.begin(), subs.end(), [](const string& lhs, const string& rhs) {
      return lhs.size() > rhs.size();
    });

    vector<string> res = Sam(p).longest_substr(s);
    for (int j = 0; j < s.size(); ++j) {
      string sub;
      for (int k = 0; k < subs.size(); ++k) {
        if (subs[k].size() > j + 1) continue;
        if (subs[k] == s.substr(j - subs[k].size() + 1, subs[k].size())) {
          sub = subs[k];
          break;
        }
      }
      assert(sub == res[j]);
    }
  }
}

int main() {
  // test_kmp();
  // test_ac();
  // test_sam();
  Sam sam("gxgogogxg");
  // Sam sam("abcbc");
  sam.print();
  return 0;
}
