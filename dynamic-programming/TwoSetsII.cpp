#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int total_sum = (n * (n + 1)) / 2;

  if (total_sum % 2) {
    cout << 0 << '\n';
  } else {
    int segment_sum = total_sum / 2;
    vector<long long> dp(segment_sum + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
      for (int j = segment_sum; j >= i; j--)
        dp[j] = (dp[j] + dp[j - i]) % MOD;

    cout << (dp[segment_sum] * 500000004) % MOD << '\n';
  }

  return 0;
}
