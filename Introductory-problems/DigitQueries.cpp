#include <bits/stdc++.h>
#ifdef DEBUG
#include "/home/lavinraj/career/code-library/debug.cpp"
#else
#define dbg(x...) 32
#endif
#define len(x) int((x).size())

using namespace std;

void print(){cout << "\n";}template<typename T, typename...types> void print(const T& first, const types&...args) {cout << first << " "; print(args...);}

int64_t power_of_10(int64_t number) {
  int64_t result = 1;

  for (int64_t i = 0; i < number; i++) 
    result *= 10;

  return result;
}

int64_t char_at(int64_t position) {
  if (position < 9)
    return position + 1;

  int64_t length = 1;
  while(9 * power_of_10(length - 1) * length < position) {
    position -= 9 * power_of_10(length - 1) * length;
    length++;
  }

  string S = to_string(power_of_10(length - 1) + position / length);

  return S[position % length] - '0';
}

int main() { 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int64_t Q;
  cin >> Q;

  while(Q--) {
    int64_t position;
    cin >> position;

    print(char_at(position - 1));
  }

  return 0;
}
