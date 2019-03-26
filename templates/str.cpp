#include <cassert>
#include <deque>
#include <iostream>
#include <unordered_map>
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

// AC
struct Trie {
  Trie(int len = 0) : len(len), fail(0), is_word(false) {}
  int len;
  int fail;
  bool is_word;
  unordered_map<char, int> children;
};

// Returns index of first |targets| in |str|, or -1 if not found.
int ac(const string& str, const vector<string>& targets) {
  // Build up tries.
  vector<Trie> tries(1);
  for (const string& target : targets) {
    int cur = 0;
    for (const char c : target) {
      if (tries[cur].children.count(c) == 0) {
        tries[cur].children[c] = tries.size();
        tries.push_back(Trie(tries[cur].len + 1));
      }
      cur = tries[cur].children[c];
    }
    tries[cur].is_word = true;
  }
  // Calculate fail for tries.
  deque<int> bfs = {0};
  while (!bfs.empty()) {
    int cur = bfs.front();
    bfs.pop_front();
    for (auto& kv : tries[cur].children) {
      char c = kv.first;
      int nxt = kv.second;
      bfs.push_back(nxt);
      if (cur == 0) {
        continue;
      }
      int match = tries[cur].fail;
      while (match != 0 && tries[match].children.count(c) == 0) {
        match = tries[match].fail;
      }
      if (tries[match].children.count(c)) {
        tries[nxt].fail = tries[match].children[c];
      } else {
        tries[nxt].fail = 0;
      }
    }
  }
  // Do match.
  int match = 0;
  for (int i = 0; i < str.size(); ++i) {
    char c = str[i];
    while (tries[match].fail != 0 && tries[match].children.count(c) == 0) {
      match = tries[match].fail;
    }
    if (tries[match].children.count(c)) {
      match = tries[match].children[c];
    }
    if (tries[match].is_word) {
      return i - tries[match].len + 1;
    }
  }
  return -1;
}

void debug_tries(const vector<Trie>& tries) {
  for (int i = 0; i < tries.size(); ++i) {
    printf("trie: %d len: %d fail: %d\n", i, tries[i].len, tries[i].fail);
    for (const auto& kv : tries[i].children) {
      printf("children: %c %d\n", kv.first, kv.second);
    }
  }
}

int main() {
  assert(kmp("aabaabaa", "aba") == 1);
  assert(kmp("aabaabaa", "aabaa") == 0);
  assert(kmp("abababa", "aa") == -1);

  assert(ac("abcdefghi", {"def", "de", "fgh", "f", "g", "i"}) == 3);
  assert(ac("abcdshihihis", {"he", "she", "his", "hers", "shit"}) == 9);
  assert(ac("aababbababbbababaaa", {"aaa", "abaaa", "ababaaa"}) == 12);
  assert(ac("alfaltafaltllalamalame",
            {"all", "fall", "fatal", "llama", "lame"}) == 18);
  assert(ac("pippipiippitepwoihdadhu",
            {"pipe", "pet", "item", "temper", "perpetual"}) == -1);

  return 0;
}
