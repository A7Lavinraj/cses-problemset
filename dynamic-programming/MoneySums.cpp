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

  set<int> unique;
  unique.insert(a[0]);

  for (int i = 1; i < n; i++) {
    vector<int> temp;

    for (auto it : unique)
      temp.push_back(it + a[i]);

    for (int j = 0; j < (int)temp.size(); j++)
      unique.insert(temp[j]);

    unique.insert(a[i]);
  }

  cout << (int)unique.size() << '\n';

  for (auto it : unique)
    cout << it << ' ';

  cout << '\n';

  return 0;
}
