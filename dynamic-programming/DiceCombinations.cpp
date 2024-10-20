#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int mxN = 1e6 + 7;

long long dp[mxN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  dp[0] = 1;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= min(6, i); j++)
      dp[i] = (dp[i] + dp[i - j]) % MOD;
  }

  cout << dp[N];

  return 0;
}
