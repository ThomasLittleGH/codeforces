
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

void solve(){
    int a, b; string sa, sb;
    cin >> a >> sa >> b >> sb;

    string pre = "", pos = "", o = "";
    o.resize(a + b);
    pre.resize(b);
    pos.resize(b);

    int ppre = 0, ppos = 0;
    string in; cin >> in;
    
    rep(i, b){
        if (in[i] == 'D') pos[ppos++] = sb[i];
        else pre[ppre++] = sb[i];
    }
    
    repb(i, ppre) o[ppre - i - 1] = pre[i];
    rep(i, a) o[ppre + i] = sa[i];
    rep(i, ppos) o[ppre + a + i] = pos[i];

    cout << o << el;
}

int main() {
    FastIO;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}


