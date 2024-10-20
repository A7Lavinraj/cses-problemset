#include <bits/stdc++.h>
using namespace std;
 
// Alias
#define ll long long
#define sz(a) (int)a.size()
 
// Constants
const long double PI = 3.141592653589793238;
const int MOD = 1e9+7;
 
// personal variadic funtion
void print(){
	cout << "\n";
}
template<typename T, typename...types>
void print(const T& first, const types&...args) {
	cout << first << " ";
	print(args...);
}
 
// DEBUG
void DBG() {
    cerr << ' ';
}
template<typename head, typename...tail>
void DBG(const head& start, const tail&...end) {
    cerr << ' ' << start;
    DBG(end...);
}
template<typename P1, typename P2>
void DBG(pair<P1, P2>& p) {
    cerr << " {";
    DBG(p.first, p.second);
    cerr << "} ";
}
template<typename V>
void DBG(vector<V>& v) {
    cerr << "[";
    for (V i : v) {
        DBG(i);
    }
    cerr << ']' << '\n';
}
template<typename S>
void DBG(set<S>& s) {
    cerr << "[";
    for (S i : s) {
        DBG(i);
    }
    cerr << ']' << '\n';
}
template<typename US>
void DBG(unordered_set<US>& s) {
    cerr << "[";
    for (US i : s) {
        DBG(i);
    }
    cerr << ']' << '\n';
}
template<typename MS>
void DBG(multiset<MS>& s) {
    cerr << "[";
    for (MS i : s) {
        DBG(i);
    }
    cerr << ']' << '\n';
}
template<typename K, typename V>
void DBG(map<K, V>& mp) {
    cerr << "[";
    for (auto i : mp) {
        DBG(i);
    }
    cerr << "]" << '\n';
}
#ifdef LAVIN_DEBUG
#define dbg(x...) cerr << "LINE(" << __LINE__ << ") -> [" << #x << "]: "; DBG(x);
#else
#define dbg(x...) 0
#endif
 
// Binary Exponentiation
int _pow(int a, ll b){
	int ans = 1;
	while(b>0){
		if(b&1){
			ans = (ans * 1LL * a)%MOD;
		}
		a = (a*1LL*a)%MOD;
		b>>=1;
	}
	return ans;
}
 
// LCM
int lcm(int a, int b){
	return (a*b)/__gcd(a, b);
}
 
// log(a) to the base (b)
int _log(int a, int b){
	return log2(a)/log2(b);
}
 
void solve(){
    int n;
    cin >> n;
    if (n == 1) {
        print(1);
        return;
    }
    if (n <= 3) {
        print("NO SOLUTION");
        return;
    }
    if (n == 4) {
        print("3 1 4 2");
        return;
    }
    for (int i = n; i > 0; i -= 2) {
        cout << i << ' ';
    }
    for (int i = n - 1; i > 0; i -= 2) {
        cout << i << ' ';
    }
    print();
}
 
int main() { 
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1, i = 1;
	//cin >> t;
 	while(t--) {
		//cout << "Case #" << i++ << ": ";
		solve();
	}
 
	return 0;
}
