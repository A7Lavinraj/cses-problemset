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

  int X, N;
  cin >> X >> N;
  set<int> positions;
  multiset<int> lengths;

  positions.insert(0);
  positions.insert(X);
  lengths.insert(X - 0);

  for (int i = 0; i < N; i++) {
    int added;
    cin >> added;
    positions.insert(added);

    auto iter = positions.find(added);
    int previous_value = *prev(iter);
    int next_value = *next(iter);

    lengths.erase(lengths.find(next_value - previous_value));
    lengths.insert(added - previous_value);
    lengths.insert(next_value - added);

    cout << *lengths.rbegin() << ' ';
  }

  return 0;
}
