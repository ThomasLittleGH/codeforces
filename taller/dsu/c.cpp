#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
#include <string.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repx(i, a, n) for (int i = (int)a; i < (int)(n); i++)
#define repb(i, n) for (int i = n - 1; i >= 0; i--)
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ms(arr, val) memset(arr, val, sizeof(arr))

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0);
	if ((int)name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

const int MAXN = 1e5 + 1;
const int MOD = 1e9 + 7;

void solve(){
    int n, k, m; cin >> n >> k >> m;
    vector<string> words(n);
    vector<int> price(n);
    vector<int> aux(n);

    rep(i, n) cin >> words[i];
    rep(i, n) cin >> price[i];

    rep(_, k){
        int gs; cin >> gs;
        int cheapest = 1e9 + 1;        
    
        rep(i, gs){
            cin >> aux[i]; aux[i]--;
            cheapest = min(cheapest, price[aux[i]]);
        }
        
        rep(i, gs) price[aux[i]] = cheapest;
    }
    
    map<string, int> wmap;
    rep(i, n) wmap[words[i]] =  price[i];

    ll o = 0;
    string s;
    rep(i, m){
        cin >> s;
        o += wmap[s];
    }
        
    cout << o << el;
}

int main() {
    FastIO;
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}


