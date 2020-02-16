---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: DataStructure/SegmentTree/SegmentTree.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ba25ef4d7b0991fa924689ca03193499">DataStructure/SegmentTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/SegmentTree/SegmentTree.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-27 20:20:28+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
    void print() {
        for (int i = 0; i < 2 * size - 1; ++i) {
            cerr << seg[i] << " ";
            if (!((i + 2) & (i + 1))) cerr << endl;
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/SegmentTree/SegmentTree.cpp"
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
    void print() {
        for (int i = 0; i < 2 * size - 1; ++i) {
            cerr << seg[i] << " ";
            if (!((i + 2) & (i + 1))) cerr << endl;
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

