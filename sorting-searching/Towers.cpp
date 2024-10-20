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
  vector<int> cubes(N);

  for (int i = 0; i < N; i++)
    cin >> cubes[i];

  multiset<int> towers;
  int ans = 0;

  for (int i = 0; i < N; i++) {
    auto itr = towers.upper_bound(cubes[i]);

    if (itr == towers.end()) {
      ans++;
      towers.insert(cubes[i]);
    } else {
      towers.erase(itr);
      towers.insert(cubes[i]);
    }
  }

  cout << len(towers) << '\n';

  return 0;
}
