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

  int N;
  cin >> N;
  vector<ll> arr(N);

  for (int i = 0; i < N; i++)
    cin >> arr[i];

  sort(arr.begin(), arr.end());

  auto calc = [&](ll x) -> ll {
    ll res = 0;

    for (int i = 0; i < N; i++)
      res += abs(arr[i] - x);

    return res;
  };

  cout << calc(arr[N / 2]) << '\n';

  return 0;
}
