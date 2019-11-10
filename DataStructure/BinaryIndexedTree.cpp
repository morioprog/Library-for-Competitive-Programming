template<typename T> struct BinaryIndexedTree {
    vector< T > data;
    BinaryIndexedTree(int sz) { data.assign(++sz, 0); }
    T sum(int k) {
        if (k < 0) return T(0);
        T ret = 0;
        for (++k; k > 0; k -= k & -k) ret += data[k];
        return (ret);
    }
    T sum(int l, int r) {
        assert(l <= r);
        return sum(r - 1) - sum(l - 1);
    }
    void add(int k, T x) {
        for (++k; k < data.size(); k += k & -k) data[k] += x;
    }
};

/*
・Binary Indexed Tree (Fenwick Tree)
    > O(logN)
[備考] ある要素に値を加える操作と, 区間和を求める操作に関してlogNで行うデータ構造
[使用例]
BinaryIndexedTree<int> bit(N);      // 要素数NのBIT
bit.add(k, x);                      // 要素kに値xを加算
bit.sum(k);                         // 閉区間[0, k]の和を求める
bit.sum(l, r);                      // 半開区間[l, r)の和を求める
*/
