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

  int N, Q;
  cin >> N >> Q;
  vector<string> forest(N);

  for (int i = 0; i < N; i++)
    cin >> forest[i];
  
  vector<vector<int>> pref_sum(N, vector<int>(N, 0));

  auto bound = [&](int i, int j) -> int {
    if (!(i < N && i >= 0 && j < N && j >= 0))
      return 0;

    return pref_sum[i][j];
  };

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      pref_sum[i][j] = int(forest[i][j] == '*') + bound(i - 1, j) - bound(i - 1, j - 1) + bound(i, j - 1); 

  while(Q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--, b--, c--, d--;

    cout << (pref_sum[c][d] - bound(a - 1, d) - bound(c, b - 1) + bound(a - 1, b - 1)) << '\n';
  }

  return 0;
}
