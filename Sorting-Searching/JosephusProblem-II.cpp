#include <bits/stdc++.h>
#ifdef DEBUG
#include "/home/lavinraj/career/cp/code-library/debug.cpp"
#else
#define dbg(x...)
#endif
#define len(x) int((x).size())

// policy based data structure (ordered set).
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void recurse(ordered_set &children, int K, int index) {
  if (children.size() == 1) {
    cout << *children.find_by_order(0);
    return;
  }

  index = (index + K) % (int)children.size();

  auto node = children.find_by_order(index);
  cout << *node << ' ';
  children.erase(node);

  recurse(children, K, index);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, K;
  cin >> N >> K;
  ordered_set children;

  for (int i = 1; i <= N; i++)
    children.insert(i);

  recurse(children, K, 0);

  return 0;
}
