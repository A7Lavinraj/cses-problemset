#include <bits/stdc++.h>
using namespace std;

const int MOD = int(1e9) + 7;
const int mxN = int(1e5), mxM = 100;
int dp[mxN + 1][mxM + 1];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;
  vector<int> arr(N);

  for (int i = 0; i < N; i++)
    cin >> arr[i];

  for (int i = 1; i <= M; i++)
    if (arr[0] == 0 || arr[0] == i)
      dp[1][i] = 1;

  for (int i = 2; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (arr[i - 1] != j && arr[i - 1] != 0)
        dp[i][j] = 0;
      else
        for (int range = j - 1; range <= j + 1; range++) {
          if (range > 0 && range <= M)
            dp[i][j] = (dp[i][j] + dp[i - 1][range]) % MOD;
        }
    }
  }

  int ans = 0;

  for (int i = 1; i <= M; i++)
    ans = (ans + dp[N][i]) % MOD;

  cout << ans << '\n';

  return 0;
}
