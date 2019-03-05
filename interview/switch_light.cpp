#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
  }
  cout << endl;
}

vector<vector<int>> inputs = {{0, 2, 3, 4, 1, 5, 7, 6},
                              {2, 3, 5, 4, 1, 0},
                              {9, 7, 5, 6, 8, 2, 3, 1, 4, 0}};

vector<int> func(const vector<int>& input, const vector<int>& test) {
  assert(input.size() == test.size());
  vector<int> res(input.size(), 0);
  for (int i = 0; i < test.size(); ++i) {
    if (test[i]) {
      res[input[i]] = 1;
    }
  }
  return res;
}

vector<int> solution(int data) {
  const vector<int>& input = inputs[data];
  int len = 1;
  while (len < input.size()) {
    len *= 2;
  }
  vector<int> grp;
  for (int i = 0; i < input.size(); ++i) {
    grp.push_back(i);
  }
  for (len /= 2; len > 0; len /= 2) {
    vector<int> test(input.size(), 0);
    for (int i = 0, j = 1; i < input.size(); ++i) {
      if (i % len == 0)
        j = !j;
      test[i] = j;
    }
    vector<int> ret = func(input, test);
    vector<int> grp2 = grp;
    for (int bgn = 0; bgn < input.size(); bgn += 2 * len) {
      int end = min(bgn + 2 * len, (int)input.size());
      int l = bgn;
      int r = min(end, bgn + len);
      for (int j = bgn; j < end; ++j) {
        if (ret[grp[j]] == 0) {
          grp2[l++] = grp[j];
        } else {
          grp2[r++] = grp[j];
        }
      }
    }
    swap(grp, grp2);
  }
  return grp;
}

int main() {
  for (int i = 0; i < inputs.size(); ++i) {
    vector<int> res = solution(i);
    print(inputs[i]);
    print(res);
    if (res == inputs[i]) {
      cout << "good!" << endl;
    }
  }
  return 0;
}
