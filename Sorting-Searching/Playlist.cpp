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
  vector<int> songs(N);

  for (int i = 0; i < N; i++)
    cin >> songs[i];

  int ans = 1, last_index = 0;
  map<int, int> seen;

  for (int i = 0; i < N; i++)
    seen[songs[i]] = -1;

  for (int i = 0; i < N; i++) {
    if (seen[songs[i]] != -1) {
      last_index = max(last_index, seen[songs[i]] + 1);
    }

    seen[songs[i]] = i;
    ans = max(ans, i + 1 - last_index);
  }

  cout << (last_index == 0 ? N : ans) << '\n';

  return 0;
}
