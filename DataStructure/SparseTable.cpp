template<typename T> struct SparseTable {
    vector< vector< T > > st;
    SparseTable() {}
    SparseTable(const vector< T > &v) {
        int b = 0;
        while ((1 << b) <= v.size()) ++b;
        st.assign(b, vector< T >(1LL << b));
        for (int i = 0; i < v.size(); ++i) st[0][i] = v[i];
        for (int i = 1; i < b; ++i) {
            for (int j = 0; j + (1LL << i) <= (1LL << b); ++j) {
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1LL << (i - 1))]);
            }
        }
    }
    inline T query(int l, int r) {
        int b = 32 - __builtin_clz(r - l) - 1;
        return (min(st[b][l], st[b][r - (1LL << b)]));
    }
};

/*
・SparseTable
    > 前処理 O(NlogN)
    > query O(1)
[備考] 静的な配列における, 任意区間の最小値を定数時間で求められるデータ構造.
[使用例]
SparseTable<int> st(V);     // V(vector<int>)で初期化し, 前処理を行う
st.query(l, r);             // 半開区間[l, r)における最小値
*/
