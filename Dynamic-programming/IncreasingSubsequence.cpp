#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);

  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<int> lis = {a[0]};

  for (int i = 0; i < n; i++) {
    auto itr = lower_bound(lis.begin(), lis.end(), a[i]);

    if (a[i] > lis.back())
      lis.push_back(a[i]);
    else
      *itr = a[i];
  }

  cout << (int)lis.size() << '\n';

  return 0;
}
