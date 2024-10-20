#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define ld long double
#define vt vector
#define pb push_back
 
#define all(c) c.begin(), c.end()
#define sz(x) (int)(x).size();
#define debug(ans) cout << '[' << ans << ']' << " ";
 
template<class T> void scan(T& x) {
	cin >> x;
}
void scan(double& d) {
	string t;
	scan(t);
	d=stod(t);
}
void scan(long double& d) {
	string t;
	scan(t);
	d=stold(t);
}
template<class H, class... T> void scan(H& h, T&... t) {
	scan(h);
	scan(t...);
}
void print(){
	cout << "\n";
}
template<typename T, typename...types>
void print(const T& first, const types&...args) {
	cout << first << " ";
	print(args...);
}
 
#define PI 3.141592653589793238
#define SOL 299792458
#define MOD 10000007
 
const int N=1e5+10;
 
void solve(){
	ll n;
	scan(n);
	cout << n;
	while(n>1) {
		if(n%2==0) {
			n/=2;
		}
		else {
			n=n*3+1;
		}
		cout << " " << n;
	}
}
 
int main() { 
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	solve();
	return 0;
}
