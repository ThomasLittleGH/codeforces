
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

const int INF = INT32_MAX;
const int MAXN = 1e5 + 1;
const int MOD = 1e9 + 7;

struct DSU {
    vector<int> parent;
    
    DSU(int n){
        parent = vector<int>(n);
        rep(i, n) parent[i] = i;
    }

    int p_find(int node){
        if (parent[node] != node) parent[node] = p_find(parent[node]);
        return parent[node];
    }

    bool p_union(int node_u, int node_v){
        node_u = p_find(node_u);
        node_v = p_find(node_v);
        
        if (node_u == node_v) return false;

        if (parent[node_u] < parent[node_v]) swap(node_u, node_v);

        parent[node_v] = node_u;
        return true;
    }
};

void solve(){
    int n, m; cin >> n;
    vector<int> cup(n);
    vector<int> cur(n, 0);
    rep(i, n) cin >> cup[i];
    cin >> m;
    DSU dsu(n);
    rep(i, m){
        int consulta; cin >> consulta;
        if (consulta == 2){
            int k; cin >> k; k--;
            cout << cur[k] << el;
            continue;
        }

        int p, x; cin >> p >> x; p--;
        
        int rem = x;
        while (rem){
            int parent = dsu.p_find(p);
            int rem_p = cup[parent] - cur[parent];
            
            if (rem <= rem_p){
                cur[parent] += rem;
                rem -= rem;
            } else {
                cur[parent] += rem_p;
                rem -= rem_p;
            }

            if (parent == n - 1) break;
            if (cur[parent] == cup[parent]) dsu.p_union(parent, parent + 1);
        }
    }
}

int main() {
    FastIO;
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}


