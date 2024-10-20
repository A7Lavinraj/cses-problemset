#include <bits/stdc++.h>
#ifdef DEBUG
#include "/home/lavinraj/career/code-library/debug.cpp"
#else
#define dbg(x...) 32
#endif

#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define LOOP(i, low, high, shift) for (ll i = low; (low == high ? false : (low < high ? i < high : i >= high)); (low < high ? i += shift : i -= shift))
#define LOOP1(high) LOOP(i, 0, high, 1)
#define LOOP2(i, high) LOOP(i, 0, high, 1)
#define LOOP3(i, low, high) LOOP(i, low, high, 1)
#define LOOP4(i, low, high, shift) LOOP(i, low, high, shift)
#define FIFTH_ARG(a, b, c, d, e, ...) e
#define GET_LOOP(...) FIFTH_ARG(__VA_ARGS__, LOOP4, LOOP3, LOOP2, LOOP1)
#define For(...) GET_LOOP(__VA_ARGS__)(__VA_ARGS__)

using namespace std;

void print(){cout << "\n";}template<typename T, typename...types> void print(const T& first, const types&...args) {cout << first << " "; print(args...);}

template <typename T> void print(vector<T> output) {
  for (T iterator : output) {
    cout << iterator << " ";
  }
  cout << "\n";
}

int main() { 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;

  if (n * (n + 1) / 2 % 2) {
    print("NO");
    return 0;
  }

  vector<int> a, b;
  int j = 0;

  if (n % 4) {
    j = 3;
  }
  else {
    j = 4;
  }

  For ((n - 1) / 4) {
    a.push_back(4 * i + 1 + j);
    a.push_back(4 * i + 4 + j);
    b.push_back(4 * i + 2 + j);
    b.push_back(4 * i + 3 + j);
  }

  if (n % 4) {
    a.push_back(1);
    a.push_back(2);
    b.push_back(3);
  }
  else {
    a.push_back(1);
    a.push_back(4);
    b.push_back(3);
    b.push_back(2);
  }

  print("YES");
  print(sz(a));
  print(a);
  print(sz(b));
  print(b);

  return 0;
}
