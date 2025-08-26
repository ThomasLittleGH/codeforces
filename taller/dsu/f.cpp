
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


struct DSU {
    vector<int> parent, size;
    vector<ll> mass;
    
    DSU(int n, vector<int>& arr){
        parent = vector<int>(n);
        size = vector<int>(n, 1);
        mass = vector<ll>(n);

        rep(i, n) mass[i] = arr[i];

        rep(i, n) parent[i] = i;
    }

    int find(int node){
        if (parent[node] != node) parent[node] = find(parent[node]);
        return parent[node];
    }

    ll gm(int node){
        return mass[find(node)];
    }

    bool size_union(int node_u, int node_v){
        node_u = find(node_u);
        node_v = find(node_v);
        if (node_u == node_v) return false;
        
        if (size[node_u] < size[node_v]) swap(node_u, node_v);

        parent[node_v] = node_u;
        
        size[node_u] += size[node_v];
        mass[node_u] += mass[node_v];
        return true;
    }
};

void solve(){
    int n; cin >> n;
    vector<int> sz(n); rep(i, n) cin >> sz[i];
    vector<ll> mov(n), out(n); rep(i, n) cin >> mov[i];
    vector<bool> en(n, false);

    DSU dsu(n, sz);

    ll largest = 0;
    repb(i, n){
        out[i] = largest;
        int added_idx = mov[i] - 1;
        en[added_idx] = true;

        if (added_idx > 0 && en[added_idx - 1]) dsu.size_union(added_idx, added_idx - 1);
        if (added_idx < n - 1 && en[added_idx + 1]) dsu.size_union(added_idx, added_idx + 1);
        largest = max(largest, dsu.gm(added_idx));
    }

    rep(i, n) cout << out[i] << el;
}

int main() {
    FastIO;
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}


