
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

ll dfs(vector<vector<int>>& arr, vector<vector<bool>>& seen, int& m, int& n, int i, int j){
    ll stn = ;
    for (auto [dx, dy] : vector<pii>{{1,0},{-1,0},{0,1},{0,-1}}){
        int ni = i + dx;
        int nj = j + dy;

        if (ni < 0 || nj < 0 || ni >= m || nj >= n) continue;
        if (seen[ni][nj]) continue;
        seen[ni][nj] = true;

        stn += dfs(arr, seen, m, n, ni, nj);
    }
    return stn;
}

void solve(){
    int m, n; cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));
    vector<vector<bool>> seen(m, vector<bool>(n, false));

    rep(i, m)
        rep(j, n) 
            cin >> arr[i][j];
    
    ll out = 0;
    rep(i, m) rep(j, n){
        if (!seen[i][j]) out = max(dfs(arr, seen, m, n, i, j), out);
    }
    cout << out << el;
}

int main() {
    FastIO;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}


