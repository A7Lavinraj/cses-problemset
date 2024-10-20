#include <bits/stdc++.h>
#ifdef DEBUG
#include "/home/lavinraj/career/cp/code-library/debug.cpp"
#else
#define dbg(x...)
#endif
#define len(x) int((x).size())

using namespace std;

// policy based data structure (ordered set).
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() { 
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  vector<array<int, 3>> ranges(N);
  vector<array<int, 2>> answer(N);
  ordered_set<array<int, 2>> boundaries;

  for (int i = 0; i < N; i++) {
    cin >> ranges[i][0] >> ranges[i][1];
    ranges[i][2] = i;
  }

  sort(ranges.begin(), ranges.end(), [](auto a, auto b) -> bool {
    if (a[0] == b[0])
      return a[1] > b[1];

    return a[0] < b[0];
  });

  for (int i = 0; i < N; i++) {
    boundaries.insert({ranges[i][1], -1 * i});
    answer[ranges[i][2]][1] = boundaries.size() - boundaries.order_of_key({ranges[i][1], -1 * i}) - 1;
  }

  boundaries.clear();

  for (int i = N - 1; i >= 0; i--) {
    boundaries.insert({ranges[i][1], -1 * i});
    answer[ranges[i][2]][0] = boundaries.order_of_key({ranges[i][1], -1 * i});
  }

  for (int i = 0; i < N; i++) 
    cout << answer[i][0] << ' ';
  cout << '\n';

  for (int i = 0; i < N; i++)
    cout << answer[i][1] << ' ';
  cout << '\n';

  return 0;
}
