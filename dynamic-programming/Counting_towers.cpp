#include <bits/stdc++.h>
using namespace std;

const int mxN = int(1e6);
const int MOD = int(1e9) + 7;
long long dp[mxN + 1][2];

void solve() {
  int n;
  cin >> n;
  dp[n][0] = 1;
  dp[n][1] = 1;

  for (int i = n - 1; ~i; i--) {
    dp[i][0] = (2LL * dp[i + 1][0] + dp[i + 1][1]) % MOD;
    dp[i][1] = (4LL * dp[i + 1][1] + dp[i + 1][0]) % MOD;
  }

  cout << (dp[1][0] + dp[1][1]) % MOD << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tests = 1;
  cin >> tests;

  for (int i = 1; i <= tests; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }

  return 0;
}
