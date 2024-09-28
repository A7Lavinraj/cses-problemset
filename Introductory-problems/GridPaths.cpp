#include <bits/stdc++.h>
#ifdef DEBUG
#include "/home/lavinraj/career/cp/code-library/debug.cpp"
#else
#define dbg(x...) 32
#endif
#define len(x) int((x).size())

using namespace std;

void print(){cout << "\n";}template<typename T, typename...types> void print(const T& first, const types&...args) {cout << first << " "; print(args...);}

int answer;
string s;
bool vis[7][7];

bool inbounds(int x, int y){
    return 0 <= x && x < 7 && 0 <= y && y < 7;
}

void recurse(int x, int y, int i){
    if(i == 48 || (x == 6 && y == 0)){
        answer += (i == 48 && (x == 6 && y == 0));
        return;
    }

    if((!inbounds(x+1, y) || vis[x+1][y]) && (!inbounds(x-1, y) || vis[x-1][y]))
        if(inbounds(x, y-1) && !vis[x][y-1] && inbounds(x, y+1) && !vis[x][y+1])
            return;
    if((!inbounds(x, y+1) || vis[x][y+1]) && (!inbounds(x, y-1) || vis[x][y-1]))
        if(inbounds(x+1, y) && !vis[x+1][y] && inbounds(x-1, y) && !vis[x-1][y])
            return;

    vis[x][y] = true;
    if(s[i] == 'D' || s[i] == '?')
        if(inbounds(x+1, y) && !vis[x+1][y])
            recurse(x+1, y, i+1);
    if(s[i] == 'U' || s[i] == '?')
        if(inbounds(x-1, y) && !vis[x-1][y])
            recurse(x-1, y, i+1);
    if(s[i] == 'R' || s[i] == '?')
        if(inbounds(x, y+1) && !vis[x][y+1])
            recurse(x, y+1, i+1);
    if(s[i] == 'L' || s[i] == '?')
        if(inbounds(x, y-1) && !vis[x][y-1])
            recurse(x, y-1, i+1);
    vis[x][y] = false;
}

int main() { 
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> s;

  recurse(0, 0, 0);
  print(answer);

  return 0;
}
