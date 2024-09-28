#include <bits/stdc++.h>
#ifdef DEBUG
#include "/home/lavinraj/career/cp/code-library/debug.cpp"
#else
#define dbg(x...)
#endif
#define len(x) int((x).size())
#define ll int64_t

using namespace std;

int main() { 
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, Q;
  cin >> N >> Q;
  vector<ll> arr(N);

  for (int i = 0; i < N; i++)
    cin >> arr[i];

  vector<ll> pref_sum(N + 1);
  pref_sum[0] = 0;

  for (int i = 1; i <= N; i++)
    pref_sum[i] = pref_sum[i - 1] + arr[i - 1];

  while(Q--) {
    int a, b;
    cin >> a >> b;

    cout << pref_sum[b] - pref_sum[a - 1] << '\n';
  }

  return 0;
}
