#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<long long>> dp(n, vector<long long>(n, 0));

  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int len = 0; len < n; len++) {
    for (int i = 0; i < n - len; i++) {
      if (len == 0)
        dp[i][i] = a[i];
      else if (len == 1)
        dp[i][i + len] = max(a[i], a[i + len]);
      else
        dp[i][i + len] =
            max(a[i] + min(dp[i + 2][i + len], dp[i + 1][i + len - 1]),
                a[i + len] + min(dp[i + 1][i + len - 1], dp[i][i + len - 2]));
    }
  }

  cout << dp[0][n - 1] << '\n';

  return 0;
}
