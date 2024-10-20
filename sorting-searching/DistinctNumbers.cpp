#include <bits/stdc++.h>
#ifdef DEBUG
#include "/home/lavinraj/career/cp/code-library/debug.cpp"
#else
#define dbg(x...) 32
#endif

#define len(x) int((x).size())
#define ll int64_t

using namespace std;

void print(){cout << "\n";}template<typename T, typename...types> void print(const T& first, const types&...args) {cout << first << " "; print(args...);}

int main() { 
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  set<int> unique;

  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
    unique.insert(value);
  }

  print((int)unique.size());

  return 0;
}
