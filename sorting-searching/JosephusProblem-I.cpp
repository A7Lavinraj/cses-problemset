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

  int N;
  cin >> N;
  vector<int> children(N);

  for (int i = 0; i < N; i++)
    children[i] = i + 1;

  while (len(children) > 1) {
    vector<int> survivors;

    for (int i = 0; i < len(children); i++) {
      if (i & 1)
        cout << children[i] << ' ';
      else
        survivors.push_back(children[i]);
    }

    if (children.size() % 2 == 0)
      children = survivors;

    else {
      int starter = survivors.back();

      survivors.pop_back();
      children.clear();
      children.push_back(starter);

      for (int s : survivors)
        children.push_back(s);
    }
  }

  cout << children[0] << '\n';

  return 0;
}
