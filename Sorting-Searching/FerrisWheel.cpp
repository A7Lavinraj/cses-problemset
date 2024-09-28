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

  int N, X;
  cin >> N >> X;
  vector<int> children(N);

  for (int i = 0; i < N; i++)
    cin >> children[i];

  sort(children.begin(), children.end());
  int answer = 0, low = 0, high = N - 1;

  while(low <= high) {
    if (children[low] + children[high] <= X)
      answer++, low++, high--;
    else 
      answer++, high--;
  }

  print(answer);

  return 0;
}
