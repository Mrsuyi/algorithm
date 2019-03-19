#include <iostream>
#include <vector>

using namespace std;

// a > b
// gcd of a/b
int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

// a > b
// d = gcd(a, b), a * x + b * y = d
void exgcd(int a, int b, int& d, int& x, int& y) {
  if (b) {
    exgcd(b, a % b, d, y, x);
    y -= x * (a / b);
  } else {
    d = a, x = 1, y = 0;
  }
}

int main() {
  return 0;
}
