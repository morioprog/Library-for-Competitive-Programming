/*
・重み付きUnionFind木
    > O(α(n))
[使用例]
WeightedUnionFind uf(V);    // 頂点数Vの重み付きUnionFind木を宣言
uf.unite(a, b, w);          // 点a, b([0, n))が同じ集合に属し, それらの間の重みがwである (すでに同じだったらfalseを返す)
uf.same(a, b);              // 点a, bが同じ集合に属するか確認
uf.find(a);                 // 点aが属する集合を求める
uf.diff(a, b);              // 点a, bの間の重みを求める
*/

template<typename T> struct WeightedUnionFind {
    vector<int> parent, rank;
    vector< T > diff_weight;
    WeightedUnionFind(int n = 1, T SUM_UNITY = 0) { init(n, SUM_UNITY); }
    void init(int n = 1, T SUM_UNITY = 0) {
        parent.resize(n); rank.resize(n); diff_weight.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }
    int find(int x) {
        if (parent[x] == x) return x;
        int ret = find(parent[x]);
        diff_weight[x] += diff_weight[parent[x]];
        return parent[x] = ret;
    }
    bool unite(int x, int y, T w) {
        w += weight(x); w -= weight(y);
        x = find(x);    y = find(y);
        if (x == y) return false;
        if (rank[x] <  rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        parent[y] = x;
        diff_weight[y] = w;
        return true;
    }
    T weight(int x) { find(x); return diff_weight[x]; }
    T diff(int x, int y) { return weight(y) - weight(x); }
    bool same(int x, int y) { return find(x) == find(y); }
};
