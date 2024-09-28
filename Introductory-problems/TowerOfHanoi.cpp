#include <bits/stdc++.h>
#ifdef DEBUG
#include "/home/lavinraj/career/code-library/debug.cpp"
#else
#define dbg(x...) 32
#endif

using namespace std;

void print(){cout << "\n";}template<typename T> void print(vector<T> &v) {for (auto &x : v) cout << x << " "; print();}template<typename T, typename...types> void print(const T& first, const types&...args) {cout << first << " "; print(args...);}

void towerOfHanoi(int N, int from, int to, int aux) {
  if (N == 0) 
    return;

  towerOfHanoi(N - 1, from, aux, to);

  print(from, to);

  towerOfHanoi(N - 1, aux, to, from);
}

int main() { 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  print((1 << N) - 1);

  towerOfHanoi(N, 1, 3, 2);

  return 0;
}
