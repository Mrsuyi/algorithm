#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

namespace kmp {

  int n;
  string pat;
  vector<int> pre;
  int state;

  void init(const string& pattern) {
    pat = pattern;
    n = pat.size();
    pre = vector<int>(n, 0);
    for (int i = 1; i < n; ++i) {
      pre[i] = pre[i - 1];
      while (true) {
        if (pat[i] == pat[pre[i]]) {
          ++pre[i];
          break;
        }
        if (pre[i] == 0)
          break;
        pre[i] = pre[pre[i] - 1];
      }
    }
    state = 0;
  }

  bool match(char c) {
    bool res = false;
    while (true) {
      if (c == pat[state]) {
        ++state;
        if (state == n) {
          res = true;
          state = pre[state - 1];
        }
        break;
      }
      if (state == 0)
        break;
      state = pre[state - 1];
    }
    return res;
  }

}  // namespace kmp

namespace ac {

  struct Trie {
    Trie() {
      memset(children, 0, sizeof(children));
      pre = 0;
      word = false;
    }
    int children[26];
    int pre;
    bool word;
  };

  vector<Trie> tries;
  int state;

  void add(const string& s) {
    int cur = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      if (tries[cur].children[s[i] - 'a'] == 0) {
        tries[cur].children[s[i] - 'a'] = tries.size();
        tries.push_back(Trie());
      }
      cur = tries[cur].children[s[i] - 'a'];
      tries[cur].word |= (i == s.size() - 1);
    }
  }

  void build() {
    vector<int> bfs = {0};
    while (!bfs.empty()) {
      vector<int> subs;
      for (int cur : bfs) {
        for (int i = 0; i < 26; ++i) {
          if (tries[cur].children[i] == 0)
            continue;
          int nxt = tries[cur].children[i];
          int pre = tries[cur].pre;
          if (cur != 0) {
            while (true) {
              if (tries[pre].children[i] != 0) {
                tries[nxt].pre = tries[pre].children[i];
                break;
              }
              if (pre == 0)
                break;
              pre = tries[pre].pre;
            }
          }
          subs.push_back(nxt);
        }
      }
      swap(subs, bfs);
    }
  }

  bool match(char c) {
    while (true) {
      if (tries[state].children[c - 'a'] != 0) {
        state = tries[state].children[c - 'a'];
        break;
      }
      if (state == 0)
        break;
      state = tries[state].pre;
    }
    int cur = state;
    while (cur) {
      if (tries[cur].word)
        return true;
      cur = tries[cur].pre;
    }
    return false;
  }

}  // namespace ac

int main() {
  for (int i = 0; i < 100; ++i) {
    int n = rand() % 9 + 1;
    string pat(n, 0);
    for (int j = 0; j < n; ++j)
      pat[j] = 'a' + (rand() % 4);
    kmp::init(pat);

    int l = rand() % 100000 + 1;
    string s(l, 0);

    int ckmp = 0, cbf = 0;
    for (int j = 0; j < l; ++j) {
      s[j] = 'a' + (rand() % 4);

      ckmp += kmp::match(s[j]);
      bool bf = (j + 1) >= n;
      for (int k = 0; k < n; ++k) {
        if (s[j - k] != pat[n - 1 - k]) {
          bf = false;
          break;
        }
      }
      cbf += bf;
      assert(ckmp == cbf);
    }
    printf("Pattern: %d, String: %d, Match: %d\n", n, l, ckmp);
  }
  return 0;
}
