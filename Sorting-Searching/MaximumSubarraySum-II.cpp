#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define len(x) int((x).size())
#define endl '\n'

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v)
    os << sep << x, sep = ", ";
  return os << '}';
}

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
#ifdef DEBUG
#define dbg(...)                                                               \
  cerr << "line: " << __LINE__ << " (" << #__VA_ARGS__ << "):",                \
      dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, A, B;
  cin >> N >> A >> B;
  vector<ll> a(N);

  for (int i = 0; i < N; i++)
    cin >> a[i];

  vector<ll> pref(N + 1, 0);

  for (int i = 0; i < N; i++)
    pref[i + 1] = pref[i] + a[i];

  set<pair<ll, int>> max_sum;

  for (int i = A; i <= B; i++)
    max_sum.insert({pref[i], i});

  ll ans = LONG_LONG_MIN;

  for (int i = 1; i <= N - A + 1; i++) {
    ans = max(ans, max_sum.rbegin()->first - pref[i - 1]);
    max_sum.erase({pref[i + A - 1], i + A - 1});

    if (i + B <= N)
      max_sum.insert({pref[i + B], i + B});
  }

  cout << ans << endl;

  return 0;
}
