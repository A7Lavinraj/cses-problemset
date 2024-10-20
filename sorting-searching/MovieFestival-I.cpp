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
  vector<array<int, 2>> movies(N);

  for (int i = 0; i < N; i++)
    cin >> movies[i][0] >> movies[i][1];

  sort(movies.begin(), movies.end(), [](array<int, 2> a, array<int, 2> b) -> bool {
    return a[1] < b[1];
  });

  int ans = 1, ptr = 0;

  for (int i = 1; i < N; i++) {
    if (movies[ptr][1] <= movies[i][0]) {
      ans++;
      ptr = i;
    }
  }

  cout << ans << '\n';

  return 0;
}
