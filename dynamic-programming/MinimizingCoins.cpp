#include <bits/stdc++.h>
#ifdef DEBUG
#include "/home/lavinraj/career/cp/code-library/debug.cpp"
#else
#define dbg(x...)
#endif
#define len(x) int((x).size())

using namespace std;

const int INF = 1e9 + 7;
const int mxN = 1e7 + 7;
int64_t dp[mxN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, X;
  cin >> N >> X;
  vector<int> coins(N);

  for (int i = 0; i < N; i++)
    cin >> coins[i];

  for (int i = 1; i <= X; i++) {
    dp[i] = INF;
    for (int j = 0; j < N; j++)
      if (coins[j] <= i)
        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
  }

  if (dp[X] == INF)
    cout << -1 << '\n';
  else
    cout << dp[X] << '\n';

  return 0;
}
