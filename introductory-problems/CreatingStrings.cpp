#include <bits/stdc++.h>
#ifdef DEBUG
#include "/home/lavinraj/career/code-library/debug.cpp"
#else
#define dbg(x...) 32
#endif

using namespace std;

void print(){cout << "\n";}template<typename T> void print(vector<T> &v) {for (auto &x : v) cout << x << " "; print();}template<typename T, typename...types> void print(const T& first, const types&...args) {cout << first << " "; print(args...);}

int main() { 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string S;
  cin >> S;

  sort(S.begin(), S.end());

  set<string> answer;

  do {
    answer.insert(S);
  } while(next_permutation(S.begin(), S.end()));

  print(int(answer.size()));

  for (string s : answer) {
    print(s);
  }

  return 0;
}
