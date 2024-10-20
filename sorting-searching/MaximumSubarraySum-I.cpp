#include <bits/stdc++.h>
#ifdef DEBUG
#include "/home/lavinraj/career/cp/code-library/debug.cpp"
#else
#define dbg(x...)
#endif
#define len(x) int((x).size())
#define ll int64_t

using namespace std;

const ll INF = 1e18;

int main() { 
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  vector<int> arr(N);

  for (int i = 0; i < N; i++)
    cin >> arr[i];

  ll ans = -INF, maxSoFar = -INF;

  for (int i = 0; i < N; i++) {
    maxSoFar = max(arr[i] + 0LL, maxSoFar + arr[i] + 0LL);
    ans = max(ans, maxSoFar);
  }

  cout << ans << '\n';

  return 0;
}
