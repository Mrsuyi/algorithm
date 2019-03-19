#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

// KMP
// Returns index of first |target| in |str|, or -1 if not found.
int kmp(const string& str, const string& target) {
  // target[i] => length of longest common prefix&suffix in target[0, i].
  vector<int> len(target.size(), 0);
  for (int i = 1; i < target.size(); ++i) {
    len[i] = len[i - 1];
    while (len[i] > 0 && target[i] != target[len[i]]) {
      len[i] = len[len[i] - 1];
    }
    if (target[i] == target[len[i]]) {
      ++len[i];
    }
  }
  for (int i = 0, j = 0; i < str.size(); ++i) {
    while (j > 0 && str[i] != target[j]) {
      j = len[j - 1];
    }
    if (str[i] == target[j]) {
      ++j;
      if (j == target.size()) {
        return i - target.size() + 1;
      }
    }
  }
  return -1;
}

int main() {
  assert(kmp("aabaabaa", "aba") == 1);
  assert(kmp("aabaabaa", "aabaa") == 0);
  assert(kmp("abababa", "aa") == -1);
  return 0;
}
