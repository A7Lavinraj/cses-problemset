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

  int N, Q;
  cin >> N >> Q;
  vector<int> arr(N + 1), indexOf(N + 1);

  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
    indexOf[arr[i]] = i;
  }

  int rounds = 0;

  for (int i = 1; i < N; i++)
    rounds += indexOf[i] > indexOf[i + 1];

  set<array<int, 2>> inversions;

  while(Q--) {
    int i, j;
    cin >> i >> j;

    if (arr[i] + 1 <= N)
      inversions.insert({arr[i], arr[i] + 1});

    if (arr[i] - 1 > 0)
      inversions.insert({arr[i] - 1, arr[i]});

    if (arr[j] + 1 <= N)
      inversions.insert({arr[j], arr[j] + 1});

    if (arr[j] - 1 > 0)
      inversions.insert({arr[j] - 1, arr[j]});

    for (auto it : inversions)
      rounds -= indexOf[it[0]] > indexOf[it[1]];

    swap(arr[i], arr[j]);
    indexOf[arr[i]] = i;
    indexOf[arr[j]] = j;

    for (auto it : inversions)
      rounds += indexOf[it[0]] > indexOf[it[1]];

    inversions.clear();

    cout << rounds + 1 << '\n';
  }

  return 0;
}
