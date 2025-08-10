template <class T, T merge(T, T), T lazy_op(T, T)> struct ST{
    T sz = 1;
    const T LOCAL_INF = (T(LINF) == int(LINF) ? INF : LINF);
    vector<T> st_arr, lazy;

    T clamp(T val) {return max(0, min(val, sz - 1));} 

    T build_tree_full(T pointer){
        if (pointer >= sz - 1) return st_arr[pointer];
        T child_a = build_tree_full(2 * pointer + 1);
        T child_b = build_tree_full(2 * pointer + 2);

        st_arr[pointer] = merge(child_a, child_b);
        return st_arr[pointer];
    }
   
    void push(T l, T r, T node){
        if (lazy[node] == 0) return;
        
        st_arr[node] = lazy_op(lazy[node], st_arr[node]);
        if (l != r){     
            lazy[2*node + 1] = lazy_op(lazy[node], lazy[2*node + 1]);
            lazy[2*node + 2] = lazy_op(lazy[node], lazy[2*node + 2]);
        }
        lazy[node] = 0;
    }

    void streefy(vector<T>& v){
        while (sz < v.size()) sz <<= 1;
        st_arr.assign(2 * sz, LOCAL_INF);
        lazy.assign(2 * sz, 0);
        for (T i = 0; i < v.size(); i++) st_arr[sz - 1 + i] = v[i];
        
        build_tree_full(0);
    }
    
    T query(T l, T r) {return query(l, r, 0, 0, sz - 1);}

    T query(T l, T r, T node, T node_l, T node_r) {
        if (r < node_l || l > node_r) return LOCAL_INF;
        push(node_l, node_r, node);

        if (l <= node_l && node_r <= r) return st_arr[node]; 

        T mid = (node_l + node_r) / 2;
        T L = query(l, r, 2*node + 1, node_l, mid); 
        T R = query(l, r, 2*node + 2, mid + 1, node_r);
        return merge(L, R);
    }

    void update(T l, T r, T val) {return update(l, r, val, 0, 0, sz - 1);}

    void update(T l, T r, T val, T node, T node_l, T node_r) {
        push(node_l, node_r, node);
        if (r < node_l || l > node_r || l > r) return;

        if (l <= node_l && node_r <= r) {
            lazy[node] = lazy_op(lazy[node], val);
            push(node_l, node_r, node);
            return;
        }
        T mid = (node_l + node_r) / 2;
        update(l, r, val, 2*node + 1, node_l, mid);
        update(l, r, val, 2*node + 2, mid + 1, node_r);
        st_arr[node] = merge(st_arr[2*node + 1], st_arr[2*node + 2]);
    }
};
