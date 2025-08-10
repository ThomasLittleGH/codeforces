void get_depth(int node, int parent, vector<int>& depth, vector<vector<int>>& adj){
    depth[node] = (parent == -1 ? 0 : depth[parent]) + 1; // Assume depth[0] = 0;
    for (auto fr : adj[node]){
        if (fr == parent) continue;
        get_depth(fr, node, depth, adj);
    }
}

vector<vector<ll>> binary_lifiting(int n, vector<int>& parent){
    const int LOG = 25;
    vector<vector<ll>> up(LOG, vector<ll>(n));
    rep(i, n) up[0][i] = parent[i];

    repx(k, 1, LOG){
        rep(i, n){
            if (up[k-1][i] == -1) up[k][i] = -1;
            else up[k][i] = up[k-1][up[k-1][i]];
        }
    }

    return up;
}

int get_kth_ancestor(int node, int k, vector<vector<ll>>& up){
    int factor = 0;
    while (k){ // Early exit is stupid for 1e1
        if (k&1) node = up[factor][node];
        factor++;
        k >>= 1;
    }

    return node;
}

int LCA(int node_u, int node_v, vector<vector<ll>>& up, vector<int>& depth){
    const int LOG = 25;
    if (depth[node_u] < depth[node_v]) swap(node_u, node_v);

    int depth_difference = depth[node_u] - depth[node_v];
    node_u = get_kth_ancestor(node_u, depth_difference, up);

    if (node_u == node_v) return node_u;
    
    repb(i, LOG - 1){
        if (up[i][node_u] != -1 && up[i][node_u] != up[i][v]) {
            node_u = up[i][node_u];
            v = up[i][v];
        }
    }

    return up[0][node_u];
}
