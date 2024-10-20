#include <bits/stdc++.h>
#ifdef DEBUG
#include "/home/lavinraj/career/cp/code-library/debug.cpp"
#else
#define dbg(x...) 32
#endif
#define len(x) int((x).size())
#define ll int64_t

using namespace std;

int main() { 
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  vector<array<int, 2>> customers;

  for (int i = 0; i < N; i++) {
    int arrival, departure;
    cin >> arrival >> departure;

    customers.push_back({arrival, +1});
    customers.push_back({departure, -1});
  }

  sort(customers.begin(), customers.end(), [](array<int, 2> a, array<int, 2> b) -> bool {
    return a[0] < b[0];
  });

  for (int i = 1; i < 2 * N; i++)
    customers[i][1] += customers[i - 1][1];

  int ans = INT_MIN;

  for (int i = 0; i < 2 * N; i++)
    ans = max(ans, customers[i][1]);

  cout << ans << '\n';

  return 0;
}
