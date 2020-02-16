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


# :warning: DataStructure/UnionFind/WeightedUnionFind.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#b443a6615f54d47cc94a593840724581">DataStructure/UnionFind</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/UnionFind/WeightedUnionFind.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-10 12:53:05+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/UnionFind/WeightedUnionFind.cpp"
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

