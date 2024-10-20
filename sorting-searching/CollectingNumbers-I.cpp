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
  vector<array<int, 2>> arr;

  for (int i = 0; i < N; i++) {
    int value;
    cin >> value;

    arr.push_back({value, i});
  }

  sort(arr.begin(), arr.end());
  int rounds = 0;

  for (int i = 1; i < N; i++)
    rounds += arr[i][1] < arr[i - 1][1];

  cout << rounds + 1 << '\n';

  return 0;
}
