template <class T, T merge(T, T)> struct ST{
    T sz = 1;
    const T LOCAL_INF = (T(LINF) == int(LINF) ? INF : LINF);
    vector<T> arr;

    T clamp(T val) {return max(0, min(val, sz - 1));} 

    T build_tree_full(T pointer){
        if (pointer >= sz - 1) return arr[pointer];
        T child_a = build_tree_full(2 * pointer + 1);
        T child_b = build_tree_full(2 * pointer + 2);

        arr[pointer] = merge(child_a, child_b);
        return arr[pointer];
    }

    void streefy(vector<T>& v){
        while (sz < v.size()) sz <<= 1;
        arr.assign(2 * sz, LOCAL_INF);
        for (T i = 0; i < v.size(); i++) arr[sz - 1 + i] = v[i];
        
        build_tree_full(0);
    }
    
    T query(T l, T r) {return query(l, r, 0, 0, sz - 1);}

    T query(T l, T r, T node = 0, T node_l = 0, T node_r = sz - 1) {
        if (r < node_l || l > node_r) return LOCAL_INF; 
        if (l <= node_l && node_r <= r) return arr[node]; 

        T mid = (node_l + node_r) / 2;
        return merge(
            query(l, r, 2*node + 1, node_l, mid),
            query(l, r, 2*node + 2, mid + 1, node_r)
        );
    }

    void update(T idx, T val){
        idx = sz - 1 + clamp(idx);
        arr[idx] = val;

        while (idx > 0){
            idx = (idx - 1) / 2;
            arr[idx] = merge(arr[2 * idx + 1], arr[2 * idx + 2]);
        }
    }

    void transform_and_rebuild(function<T(T)> func) {
        for (T i = 0; i < sz; i++) {
            arr[sz - 1 + i] = func(arr[sz - 1 + i]);
        }
        build_tree_full(0);
    }
};
