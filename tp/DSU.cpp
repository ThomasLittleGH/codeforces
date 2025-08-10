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

    bool depth_union(int node_u, int node_v){
        node_u = find(node_u);
        node_v = find(node_v);
        if (node_u == node_v) return false;

        if (depth[node_u] < depth[node_v]) swap(node_u, node_v);

        parent[node_v] = node_u;
        if (depth[node_u] == depth[node_v]) depth[node_u]++;
        return true;
    }

    bool size_union(int node_u, int node_v){
        node_u = find(node_u);
        node_v = find(node_v);
        if (node_u == node_v) return false;
        
        if (size[node_u] < size[node_v]) swap(node_u, node_v);

        parent[node_v] = node_u;
        
        size[node_u] += size[node_v];
        return true;
    }
};
