#include <bits/stdc++.h>
#ifdef DEBUG
#include "/home/lavinraj/career/code-library/debug.cpp"
#else
#define dbg(x...) 32
#endif

using namespace std;

void print(){cout << "\n";}template<typename T> void print(vector<T> &v) {for (auto &x : v) cout << x << " "; print();}template<typename T, typename...types> void print(const T& first, const types&...args) {cout << first << " "; print(args...);}

int64_t minDifference(vector<int>& apples, int index, int64_t sum, const int64_t& total) {
  if (index == int(apples.size()))
    return abs(total - 2 * sum);

  return min({abs(total - 2 * sum), minDifference(apples, index + 1, sum + apples[index], total), minDifference(apples, index + 1, sum, total)});
}

int main() { 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;
  vector<int> apples(N);

  for (int i = 0; i < N; i++)
    cin >> apples[i];

  const int64_t total = accumulate(apples.begin(), apples.end(), int64_t(0));

  print(minDifference(apples, 0, 0, total));

  return 0;
}
