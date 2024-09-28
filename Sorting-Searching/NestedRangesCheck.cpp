#include <bits/stdc++.h>
#ifdef DEBUG
#include "/home/lavinraj/career/cp/code-library/debug.cpp"
#else
#define dbg(x...)
#endif
#define len(x) int((x).size())

using namespace std;

int main() { 
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  vector<array<int, 3>> ranges(N);

  for (int i = 0; i < N; i++) {
    cin >> ranges[i][0] >> ranges[i][1];
    ranges[i][2] = i;
  }

  sort(ranges.begin(), ranges.end(), [](auto a, auto b) -> bool {
    if (a[0] == b[0])
      return a[1] > b[1];

    return a[0] < b[0];
  });

  vector<array<bool, 2>> answer(N, {0, 0});
  int limit = 0;

  for (int i = 0; i < N; i++) {
    answer[ranges[i][2]][1] = ranges[i][1] <= limit;
    limit = max(limit, ranges[i][1]);
  }

  limit = int(1e9) + 7;

  for (int i = N - 1; i >= 0; i--) {
    answer[ranges[i][2]][0] = ranges[i][1] >= limit;
    limit = min(limit, ranges[i][1]);
  }

  for (int i = 0; i < N; i++)
    cout << answer[i][0] << ' ';

  cout << '\n';

  for (int i = 0; i < N; i++)
    cout << answer[i][1] << ' ';

  return 0;
}
