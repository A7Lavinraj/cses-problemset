#include <bits/stdc++.h>
#ifdef DEBUG
#include "/home/lavinraj/career/cp/code-library/debug.cpp"
#else
#define dbg(x...) 32
#endif
#define len(x) int((x).size())

using namespace std;

int main() { 
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, K;
  cin >> N >> K;
  vector<array<int, 2>> hotel(N);
  vector<int> groups(K);

  for (int i = 0; i < N; i++)
    cin >> hotel[i][0], hotel[i][1] = i;
  for (int i = 0; i < K; i++)
    cin >> groups[i];

  sort(hotel.begin(), hotel.end(), [](auto a, auto b) -> bool { return a[0] <= b[0]; });

  for (int i = 0; i < K; i++) {
    auto it = lower_bound(hotel.begin(), hotel.end(), {groups[i], 0});
    if (it == hotel.end())
      cout << 0 << ' ';
    else {
      cout << it[1] + 1 << ' ';
      hotel.erase(it);
    }
  }

  return 0;
}
