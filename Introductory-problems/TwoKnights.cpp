#include <bits/stdc++.h>
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

int main() { 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;

  auto calc = [](ll n) -> ll {
    ll k = n * n;
    return n > 2 ? k * (k - 1) / 2 - 4 * (n - 1) * (n - 2) : k * (k - 1) / 2;
  };

  For (i, 1, n + 1) {
    print(calc(i));
  }

  return 0;
}
