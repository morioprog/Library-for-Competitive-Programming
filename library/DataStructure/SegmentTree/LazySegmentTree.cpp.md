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


# :warning: DataStructure/SegmentTree/LazySegmentTree.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ba25ef4d7b0991fa924689ca03193499">DataStructure/SegmentTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/SegmentTree/LazySegmentTree.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-10 12:53:05+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <typename Monoid, typename OperatorMonoid = Monoid> struct LazySegmentTree {
    typedef function< Monoid(Monoid, Monoid) > F;
    typedef function< Monoid(Monoid, OperatorMonoid) > G;
    typedef function< OperatorMonoid(OperatorMonoid, OperatorMonoid) > H;
    typedef function< OperatorMonoid(OperatorMonoid, int) > P;
    int sz;
    F f; G g; H h; P p;
    Monoid d1; OperatorMonoid d0;
    vector< Monoid > dat;
    vector< OperatorMonoid > laz;
    LazySegmentTree(int n, F f, G g, H h, Monoid d1, OperatorMonoid d0,
        vector< Monoid > v = vector< Monoid >(), P p = [] (OperatorMonoid a, int b) { return a; })
        : f(f), g(g), h(h), d1(d1), d0(d0), p(p) {
        sz = 1; while (sz < n) sz <<= 1;
        dat.assign(2 * sz - 1, d1);
        laz.assign(2 * sz - 1, d0);
        if (n == (int)v.size()) build(n, v);
    }
    void build(int n, vector<Monoid> &v) {
        for (int i = 0; i < n; ++i) dat[i + sz - 1] = v[i];
        for (int i = sz - 2; i >= 0; --i) dat[i] = f(dat[2 * i + 1], dat[2 * i + 2]);
    }
    inline void eval(int len, int k) {
        if (laz[k] == d0) return;
        if (2 * k + 1 < 2 * sz - 1) {
            laz[2 * k + 1] = h(laz[2 * k + 1], laz[k]);
            laz[2 * k + 2] = h(laz[2 * k + 2], laz[k]);
        }
        dat[k] = g(dat[k], p(laz[k], len));
        laz[k] = d0;
    }
    Monoid update(int a, int b, OperatorMonoid x, int k, int l, int r) {
        eval(r - l, k);
        if (r <= a or b <= l) return dat[k];
        if (a <= l and r <= b) {
            laz[k] = h(laz[k], x);
            return g(dat[k], p(laz[k], r - l));
        }
        return dat[k] = f(update(a, b, x, 2 * k + 1, l, (l + r) / 2), update(a, b, x, 2 * k + 2, (l + r) / 2, r));
    }
    Monoid update(int a, int b, OperatorMonoid x) {
        return update(a, b, x, 0, 0, sz);
    }
    Monoid query(int a, int b, int k, int l, int r) {
        eval(r - l, k);
        if (r <= a or b <= l) return d1;
        if (a <= l and r <= b) return dat[k];
        Monoid vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        Monoid vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return f(vl, vr);
    }
    Monoid query(int a, int b) {
        return query(a, b, 0, 0, sz);
    }
    Monoid operator[](const int &k) {
        return query(k, k + 1);
    }
};

/*
・遅延評価セグメント木
    > query, update O(logN)
[引数]
LazySegmentTree<Monoid, OperatorMonoid> seg(sz, f, g, h, d1, d0, v, p);
> sz : 要素数
>  f : 要素と要素をマージする関数
>  g : 要素に作用素を作用させる関数
>  h : 作用素と作用素をマージする関数
> d1 : 要素のモノイド
> d0 : 作用素のモノイド
>  v : 初期化用の配列
>  p : 区間に対する操作が要素数に比例して変化する場合 ( p(a, b) = g(a, a, ..., a) [aはb個] )
[備考]
以下の3つの条件を満たすときに使える
1. g(f(a, b), c) = f(g(a, c), g(b, c))
( 1'. g(f(a, b), p(c, d)) = f(g(a, p(c, d / 2)), g(b, p(c, d / 2))) )
2. g(g(a, b), c) = g(a, h(b, c))
3. g(a, d0) = a
[典型例]
> 区間加算 -> 区間和
LazySegmentTree<ll> seg(N, plus<ll>(), plus<ll>(), plus<ll>(), 0, 0, vector<ll>(N, 0), multiplies<ll>());
> 区間加算 -> 区間最小
LazySegmentTree<ll> seg(N, [](ll a, ll b){ return min(a, b); }, plus<ll>(), plus<ll>(), INFF, 0);
> 区間更新 -> 区間和
LazySegmentTree<ll> seg(N, plus<ll>(), [](ll a, ll b){ return b; }, [](ll a, ll b){ return b; }, 0, INFF, vector<ll>(N, 0), multiplies<ll>());
> 区間更新 -> 区間最小
LazySegmentTree<ll> seg(N, [](ll a,ll b){ return min(a,b); }, [](ll a, ll b){ return b; }, [](ll a, ll b){ return b; }, INFF, INFF);
[使用例]
seg.update(l, r, x);        // 半開区間[l, r)に作用素xを作用
seg.query(l, r);            // 半開区間[l, r)に対する演算の結果
seg[k];                     // k番目の要素を取得
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/SegmentTree/LazySegmentTree.cpp"
template <typename Monoid, typename OperatorMonoid = Monoid> struct LazySegmentTree {
    typedef function< Monoid(Monoid, Monoid) > F;
    typedef function< Monoid(Monoid, OperatorMonoid) > G;
    typedef function< OperatorMonoid(OperatorMonoid, OperatorMonoid) > H;
    typedef function< OperatorMonoid(OperatorMonoid, int) > P;
    int sz;
    F f; G g; H h; P p;
    Monoid d1; OperatorMonoid d0;
    vector< Monoid > dat;
    vector< OperatorMonoid > laz;
    LazySegmentTree(int n, F f, G g, H h, Monoid d1, OperatorMonoid d0,
        vector< Monoid > v = vector< Monoid >(), P p = [] (OperatorMonoid a, int b) { return a; })
        : f(f), g(g), h(h), d1(d1), d0(d0), p(p) {
        sz = 1; while (sz < n) sz <<= 1;
        dat.assign(2 * sz - 1, d1);
        laz.assign(2 * sz - 1, d0);
        if (n == (int)v.size()) build(n, v);
    }
    void build(int n, vector<Monoid> &v) {
        for (int i = 0; i < n; ++i) dat[i + sz - 1] = v[i];
        for (int i = sz - 2; i >= 0; --i) dat[i] = f(dat[2 * i + 1], dat[2 * i + 2]);
    }
    inline void eval(int len, int k) {
        if (laz[k] == d0) return;
        if (2 * k + 1 < 2 * sz - 1) {
            laz[2 * k + 1] = h(laz[2 * k + 1], laz[k]);
            laz[2 * k + 2] = h(laz[2 * k + 2], laz[k]);
        }
        dat[k] = g(dat[k], p(laz[k], len));
        laz[k] = d0;
    }
    Monoid update(int a, int b, OperatorMonoid x, int k, int l, int r) {
        eval(r - l, k);
        if (r <= a or b <= l) return dat[k];
        if (a <= l and r <= b) {
            laz[k] = h(laz[k], x);
            return g(dat[k], p(laz[k], r - l));
        }
        return dat[k] = f(update(a, b, x, 2 * k + 1, l, (l + r) / 2), update(a, b, x, 2 * k + 2, (l + r) / 2, r));
    }
    Monoid update(int a, int b, OperatorMonoid x) {
        return update(a, b, x, 0, 0, sz);
    }
    Monoid query(int a, int b, int k, int l, int r) {
        eval(r - l, k);
        if (r <= a or b <= l) return d1;
        if (a <= l and r <= b) return dat[k];
        Monoid vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        Monoid vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return f(vl, vr);
    }
    Monoid query(int a, int b) {
        return query(a, b, 0, 0, sz);
    }
    Monoid operator[](const int &k) {
        return query(k, k + 1);
    }
};

/*
・遅延評価セグメント木
    > query, update O(logN)
[引数]
LazySegmentTree<Monoid, OperatorMonoid> seg(sz, f, g, h, d1, d0, v, p);
> sz : 要素数
>  f : 要素と要素をマージする関数
>  g : 要素に作用素を作用させる関数
>  h : 作用素と作用素をマージする関数
> d1 : 要素のモノイド
> d0 : 作用素のモノイド
>  v : 初期化用の配列
>  p : 区間に対する操作が要素数に比例して変化する場合 ( p(a, b) = g(a, a, ..., a) [aはb個] )
[備考]
以下の3つの条件を満たすときに使える
1. g(f(a, b), c) = f(g(a, c), g(b, c))
( 1'. g(f(a, b), p(c, d)) = f(g(a, p(c, d / 2)), g(b, p(c, d / 2))) )
2. g(g(a, b), c) = g(a, h(b, c))
3. g(a, d0) = a
[典型例]
> 区間加算 -> 区間和
LazySegmentTree<ll> seg(N, plus<ll>(), plus<ll>(), plus<ll>(), 0, 0, vector<ll>(N, 0), multiplies<ll>());
> 区間加算 -> 区間最小
LazySegmentTree<ll> seg(N, [](ll a, ll b){ return min(a, b); }, plus<ll>(), plus<ll>(), INFF, 0);
> 区間更新 -> 区間和
LazySegmentTree<ll> seg(N, plus<ll>(), [](ll a, ll b){ return b; }, [](ll a, ll b){ return b; }, 0, INFF, vector<ll>(N, 0), multiplies<ll>());
> 区間更新 -> 区間最小
LazySegmentTree<ll> seg(N, [](ll a,ll b){ return min(a,b); }, [](ll a, ll b){ return b; }, [](ll a, ll b){ return b; }, INFF, INFF);
[使用例]
seg.update(l, r, x);        // 半開区間[l, r)に作用素xを作用
seg.query(l, r);            // 半開区間[l, r)に対する演算の結果
seg[k];                     // k番目の要素を取得
*/

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

