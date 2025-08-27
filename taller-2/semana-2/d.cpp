
#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
#include <string.h>
# include <queue>

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
    int n, m, d; cin >> n >> m >> d;
    vector<vector<int>> mat(n, vector<int>(m));

    int min_val = 1e9;
    rep(i, n) rep(j ,m){ cin >> mat[i][j]; min_val = min(min_val, mat[i][j]); }

    int last_val = -1;
    int prom = 0; 
    rep(i, n) rep(j, m){
        mat[i][j] -= min_val;
        if (last_val == -1) last_val = mat[i][j] % d;
        if (last_val != mat[i][j] % d){
            cout << -1 << el;
            return;
        }
        
        mat[i][j] /= d;
        prom += mat[i][j];
    }
    
    prom += 1;
    prom /= n*m;

    ll mov = 0;

    rep(i, n) rep(j, m) mov += abs(prom - mat[i][j]);

    cout << mov << el;
}

int main() {
    FastIO;
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}


