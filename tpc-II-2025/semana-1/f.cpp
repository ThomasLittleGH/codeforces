
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

//const int INF = INT32_MAX;
const int MAXN = 1e5 + 1;
const int MOD = 1e9 + 7;

vector<string> grid;

bool bfs(int n, int line, int column){
    bool o = (line == 1 && column == n - 1 ? true : false);
    for (auto [dl, dc] : vector<pii>{{0,1},{1,0},{1,1},{-1,1}}){
        if (line + dl < 0 || line + dl == 2 || column + dc == n || grid[line + dl][column + dc] == '1') continue;
        grid[line + dl][column + dc] = '1';
        o |= bfs(n, line + dl, column + dc);
    }
    return o;
}

void solve(){
    int n; cin >> n;
    grid = vector<string>(2);

    rep(i, 2) cin >> grid[i];
    cout << (bfs(n, 0, 0) ? "YES" : "NO") << el;
}

int main() {
    FastIO;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}


