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

const int INF = INT32_MAX;
const int MAXN = 1e5 + 1;
const int MOD = 1e9 + 7;

struct DSU {
    vector<int> parent, depth, size;
    
    DSU(int n){
        parent = vector<int>(n);
        depth = vector<int>(n, 0);
        size = vector<int>(n, 1);

        rep(i, n) parent[i] = i;
    }

    int find(int node){
        if (parent[node] != node) parent[node] = find(parent[node]);
        return parent[node];
    }

    bool size_union(int node_u, int node_v){
        node_u = find(node_u);
        node_v = find(node_v);
        if (node_u == node_v) return false;;
        
        if (size[node_u] < size[node_v]) swap(node_u, node_v);

        parent[node_v] = node_u;
        
        size[node_u] += size[node_v];
        return true;
    }
};

void solve(){
    int n; cin >> n;
    bool visited[26]; ms(visited, false);
    DSU dsu(26);

    string s;
    rep(i, n){
        cin >> s;
        for (char c : s){
            visited[c - 'a'] = true;
            for (char c_2 : s){
                if (c != c_2){
                    dsu.size_union(c - 'a', c_2 - 'a');
                }
            }
        }
    }

    set<int> roots;
    rep(i, 26) if (visited[i]) roots.insert(dsu.find(i));
    cout << roots.size() << el;
}

int main() {
    FastIO;
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}


