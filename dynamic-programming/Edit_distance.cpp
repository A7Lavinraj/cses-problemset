#include <bits/stdc++.h>
using namespace std;

const int mxN = int(5e3);
const int INF = int(1e9);
int dp[mxN + 1][mxN + 1];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s, t;
  cin >> s >> t;

  for (int i = 1; i <= (int)s.size(); i++)
    dp[i][0] = i;

  for (int i = 1; i <= (int)t.size(); i++)
    dp[0][i] = i;

  for (int i = 1; i <= (int)s.size(); i++)
    for (int j = 1; j <= (int)t.size(); j++) {
      dp[i][j] = INF;

      if (s[i - 1] == t[j - 1])
        dp[i][j] = dp[i - 1][j - 1];
      else
        dp[i][j] =
            min({dp[i][j] - 1, dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) +
            1;
    }

  cout << dp[(int)s.size()][(int)t.size()];

  return 0;
}
