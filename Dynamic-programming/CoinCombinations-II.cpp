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

const int mxN = 1e6;
const int MOD = int(1e9) + 7;
int dp[mxN + 1];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, X;
  cin >> N >> X;
  vector<int> coins(N);
  memset(dp, 0, sizeof(dp));

  for (int i = 0; i < N; i++)
    cin >> coins[i];

  dp[0] = 1;

  for (int j = 0; j < N; j++)
    for (int i = 1; i <= X; i++)
      if (coins[j] <= i)
        dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;

  cout << dp[X] << endl;

  return 0;
}
