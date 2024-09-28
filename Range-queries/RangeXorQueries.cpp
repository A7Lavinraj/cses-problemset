#include <bits/stdc++.h>
#ifdef DEBUG
#include "/home/lavinraj/career/cp/code-library/debug.cpp"
#else
#define dbg(x...)
#endif
#define len(x) int((x).size())

using namespace std;

int main() { 
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, Q;
  cin >> N >> Q;
  vector<int> arr(N);

  for (int i = 0; i < N; i++)
    cin >> arr[i];

  vector<int> pref_xor(N + 1);
  pref_xor[0] = 0;

  for (int i = 1; i <= N; i++)
    pref_xor[i] = pref_xor[i - 1] ^ arr[i - 1];

  while(Q--) {
    int a, b;
    cin >> a >> b;

    cout << (pref_xor[b] ^ pref_xor[a - 1]) << '\n';
  }

  return 0;
}
