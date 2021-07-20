#include <cmath>
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

    int match(const string& s) {
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

  void add(const string &s) {
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

} // namespace ac

int main() {
  test_kmp();
  return 0;
}
