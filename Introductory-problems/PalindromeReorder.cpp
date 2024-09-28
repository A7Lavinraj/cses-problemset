#include <bits/stdc++.h>
#ifdef DEBUG
#include "/home/lavinraj/career/code-library/debug.cpp"
#else
#define dbg(x...) 32
#endif
 
#define ll long long
#define sz(x) (int)x.size()
 
using namespace std;
 
const int INF32 = int(1e9) + 7;
const long long INF64 = (long long)1e18 + 7;
 
void print(){cout << "\n";}template<typename T, typename...types> void print(const T& first, const types&...args) {cout << first << " "; print(args...);}
 
int main() { 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 
  string s;
  cin >> s;
 
  unordered_map<char, int> mp;
  for (int i = 0; i < sz(s); i++) {
    mp[s[i]]++;
  }
 
  int cnt_odd = 0;
 
  for (auto i : mp) {
    cnt_odd += i.second & 1;
  }
 
  if (sz(s) & 1 && cnt_odd > 1) {
    print("NO SOLUTION");
    return 0;
  }
 
  if (sz(s) % 2 == 0 && cnt_odd != 0) {
    print("NO SOLUTION");
    return 0;
  }

  pair<char, int> odd_pair;
  string answer;

  for (auto i : mp) {
    if ((i.second & 1) == 0) {
      for (int j = 0; j < i.second / 2; j++) {
        answer.push_back(i.first);
        cout << i.first;
      }
    }
    else odd_pair = i;
  }

  for (int i = 0; i < odd_pair.second; i++) {
    cout << odd_pair.first;
  }

  for (int i = sz(answer) - 1; i >= 0; i--) {
    cout << answer[i];
  }

  return 0;
}
