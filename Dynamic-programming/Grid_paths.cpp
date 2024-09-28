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

const int MOD = int(1e9) + 7;
const int mxN = 1000;
int dp[mxN + 1][mxN + 1];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  vector<string> grid(N);
  memset(dp, 0, sizeof(dp));

  for (int i = 0; i < N; i++)
    cin >> grid[i];

  dp[1][1] = grid[0][0] != '*';

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (grid[i - 1][j - 1] != '*')
        dp[i][j] = (dp[i][j] + dp[i - 1][j] + dp[i][j - 1]) % MOD;
    }
  }

  cout << dp[N][N] << endl;

  return 0;
}
