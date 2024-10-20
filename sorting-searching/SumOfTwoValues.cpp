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

  int N, X;
  cin >> N >> X;
  vector<int> arr(N);
  map<int, int> freq;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    freq[arr[i]]++;
  }

  auto find = [&](int x, int index) -> int {
    for (int i = 0; i < N; i++)
      if (arr[i] == x && index != i)
        return i;

    return -1;
  };

  for (int i = 0; i < N; i++) {
    if (freq[X - arr[i]] > 0) {
      if (X == 2 * arr[i] && freq[arr[i]] == 1)
        continue;

      int index = find(X - arr[i], i);

      if (index == -1)
        continue;

      cout << i + 1 << " " << index + 1 << '\n';
      return 0;
    }
  }

  cout << "IMPOSSIBLE\n";

  return 0;
}
