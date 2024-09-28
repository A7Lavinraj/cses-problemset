#include <bits/stdc++.h>
#ifdef DEBUG
#include "/home/lavinraj/career/code-library/debug.cpp"
#else
#define dbg(x...) 32
#endif

using namespace std;

void print(){cout << "\n";}template<typename T, typename...types> void print(const T& first, const types&...args) {cout << first << " "; print(args...);}

vector<string> recurse(int N) {
  if (N == 1)
    return {"0", "1"};

  vector<string> sub_problem = recurse(N - 1);
  vector<string> current_problem;

  for (int i = 0; i < int(sub_problem.size()); i++) {
    string temp = sub_problem[i];
    temp = '0' + sub_problem[i];
    current_problem.push_back(temp);
  }

  for (int i = int(sub_problem.size()) - 1; i >= 0; i--) {
    string temp;
    temp = '1' + sub_problem[i];
    current_problem.push_back(temp);
  }

  return current_problem;
}

int main() { 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;
  vector<string> answer = recurse(N);

  for (string &s : answer) {
    print(s);
  }

  return 0;
}
