template<typename T> struct SegmentTree {
    using F = function< T(T, T) >;
    vector< T > seg;
    int size;       // データの数以上の最小の2冪, 最下段のデータの個数
    const F func;
    const T M1;
    SegmentTree(int n, const F f, const T &M) : func(f), M1(M) {
        size = 1; while (size < n) size <<= 1;
        seg.resize(2 * size - 1, M1);
    }
    void set(int k, T x) {
        seg[k + size - 1] = x;
    }
    void build() {
        for (int i = size - 2; i >= 0; --i) {
            // iの子は, (2 * i + 1, 2 * i + 2)
            seg[i] = func(seg[2 * i + 1], seg[2 * i + 2]);
        }
    }
    void update(int k, T x) {
        // kをseg内の添字に対応させる <- (size - 1)を足す
        k += size - 1;
        seg[k] = x;
        while (k > 0) {
            k = (k - 1) / 2;
            seg[k] = func(seg[2 * k + 1], seg[2 * k + 2]);
        }
    }
    void add(int k, T x) {
        // kをseg内の添字に対応させる <- (size - 1)を足す
        k += size - 1;
        seg[k] += x;
        while (k > 0) {
            k = (k - 1) / 2;
            seg[k] = func(seg[2 * k + 1], seg[2 * k + 2]);
        }
    }
    T query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = size;
        if (r <= a || l >= b) return M1;
        if (l >= a && r <= b) return seg[k];
        T f_l = query(a, b, 2 * k + 1, l, (l + r) / 2);
        T f_r = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return func(f_l, f_r);
    }
    void debug() {
        for (int i = 0; i < 2 * size - 1; ++i) {
            cerr << seg[i] << " \n"[i == 2 * size - 2];
        }
    }
};

/*
・セグメント木
    >         build O(N)
    > query, update O(logN)
[備考] 結合律, 単位元を持つ二項演算を, 任意の区間に関してlogNで行うデータ構造
[使用例]
SegmentTree<int> seg(N, [](int a, int b){ return a + b; }, 0 );     // 区間和
SegmentTree<int> seg(N, [](int a, int b){ return min(a,b); }, INF); // 区間min
seg.set(k, x);      // 要素kに値xを設定
seg.build();        // 上のセグメントに値を設定
seg.update(k, x);   // 要素kを値xに変更
seg.add(k, x);      // 要素kに値xを加算
seg.query(l, r);    // 半開区間[l, r)に対する二項演算の結果を返す
*/
