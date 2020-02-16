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


# :warning: Graph/HeavyLightDecomposition/HeavyLightDecomposition.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#fc6138b77671bed00efddeeda38c6975">Graph/HeavyLightDecomposition</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/HeavyLightDecomposition/HeavyLightDecomposition.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-27 20:17:55+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct HLD {
    static const int MAXLOG = 20;
    int V, E = 0;
    vector<int> dep, sz, pathidx, child, idx;
    vector<vector<int>> edge, paths, dbl;
    HLD(int V) : V(V) {
        edge.resize(V);
        paths.resize(V);
        dep = sz = pathidx = child = idx = vector<int>(V, 0);
        dbl.resize(MAXLOG + 1, vector<int>(V, 0));
    }
    void add_edge(int a, int b) {
        edge[a].emplace_back(b);
        edge[b].emplace_back(a);
        ++E;
    }
    void dfs(int cur, int prv) {
        dbl[0][cur] = prv;
        sz[cur] = 1;
        child[cur] = idx[cur] = -1;
        pathidx[cur] = cur;
        dep[cur] = (prv == -1) ? 0 : (dep[prv] + 1);
        for (int i = 0; i < edge[cur].size(); ++i) if (edge[cur][i] != prv) {
            int nxt = edge[cur][i];
            dfs(nxt, cur);
            sz[cur] += sz[nxt];
            if (child[cur] == -1 or sz[nxt] > sz[child[cur]]) {
                child[cur] = nxt;
                idx[cur] = i;
            }
        }
    }
    void dfs2(int cur, int prv) {
        if (prv != -1 and child[prv] == cur) pathidx[cur] = pathidx[prv];
        paths[pathidx[cur]].emplace_back(cur);
        for (auto& nxt: edge[cur]) if (nxt != prv) dfs2(nxt, cur);
    }
    int lca(int u, int v) {
        if (dep[u] > dep[v]) swap(u, v);
        for (int i = MAXLOG - 1; i >= 0; --i) if (dep[v] - dep[u] >= 1 << i) v = dbl[i][v];
        for (int i = MAXLOG - 1; i >= 0; --i) if (dbl[i][u] != dbl[i][v]) {
            u = dbl[i][u];
            v = dbl[i][v];
        }
        return (u == v) ? u : dbl[0][u];
    }
    void build(int root = 0) {
        dfs(root, root);
        dfs2(root, root);
        for (int i = 0; i < MAXLOG; ++i) {
            for (int j = 0; j < V; ++j) {
                dbl[i + 1][j] = dbl[i][dbl[i][j]];
            }
        }
    }
};

/*
    > Heavy-Light Decomposition
        * 木上のクエリをセグ木で処理できるようにするやつ
        * 基本的に頂点にコストがあるタイプのクエリを処理できる
        * 辺上にコストがあるときは, depが大きい方に大して処理するとよい
    $ Variables
        *     dep : 頂点の深さ
        *      sz : 頂点の部分木の大きさ
        * pathidx : 頂点が属するpathのidx (始点の頂点番号)
        *   child : 頂点の子のidx (なければ-1)
        *     idx : HeavyEdgeを繋げるためのやつ
        *    edge : グラフ
        *   paths : 各pathに属する点のvector
        *     dbl : LCA用のダブリングテーブル
    $ Functions
        @ 前処理
            HLD hld(100100);        // 100100頂点の木
            hld.add_edge(2, 6);     // 頂点2, 6間の無向辺を追加
            hld.build();            // いろいろbuildする
        @ クエリ
            hld.lca(a, b);          // 頂点a, bのLCA
            SegmentTree seg[100100];
            for (int i = 0; i < V; ++i)
                if (hld.pathidx[i] == i)
                    seg[i] = SegmentTree(hld.paths[i].size() + 2, init, func);
            query(u, v);            // 頂点u, v間のクエリ
            seg[hld.pathidx[u]].replace(hld.dep[u] - hld.dep[hld.pathidx[u]], val);
                                    // 頂点uに対するコスト変更クエリ
            遅延セグメント木のときはqueryみたいにすればいい
*/

// 単位元
const int INIT = 0;
const int MAXN = 100100;
HLD hld(MAXN);
SegmentTree<int> seg[MAXN];

int query(int u, int v) {
    int ret = INIT;
    if (hld.dep[u] < hld.dep[v]) swap(u, v);
    while (hld.pathidx[u] != hld.pathidx[v]) {
        ret += seg[hld.pathidx[u]].query(
            0,
            1 + hld.dep[u] - hld.dep[hld.pathidx[u]]
        );          // merge
        u = hld.dbl[0][hld.pathidx[u]];
    }
    if (u != v) {
        ret += seg[hld.pathidx[u]].query(
            1 + hld.dep[v] - hld.dep[hld.pathidx[u]],
            1 + hld.dep[u] - hld.dep[hld.pathidx[u]]
        );          // merge
    }
    return ret;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/HeavyLightDecomposition/HeavyLightDecomposition.cpp"
struct HLD {
    static const int MAXLOG = 20;
    int V, E = 0;
    vector<int> dep, sz, pathidx, child, idx;
    vector<vector<int>> edge, paths, dbl;
    HLD(int V) : V(V) {
        edge.resize(V);
        paths.resize(V);
        dep = sz = pathidx = child = idx = vector<int>(V, 0);
        dbl.resize(MAXLOG + 1, vector<int>(V, 0));
    }
    void add_edge(int a, int b) {
        edge[a].emplace_back(b);
        edge[b].emplace_back(a);
        ++E;
    }
    void dfs(int cur, int prv) {
        dbl[0][cur] = prv;
        sz[cur] = 1;
        child[cur] = idx[cur] = -1;
        pathidx[cur] = cur;
        dep[cur] = (prv == -1) ? 0 : (dep[prv] + 1);
        for (int i = 0; i < edge[cur].size(); ++i) if (edge[cur][i] != prv) {
            int nxt = edge[cur][i];
            dfs(nxt, cur);
            sz[cur] += sz[nxt];
            if (child[cur] == -1 or sz[nxt] > sz[child[cur]]) {
                child[cur] = nxt;
                idx[cur] = i;
            }
        }
    }
    void dfs2(int cur, int prv) {
        if (prv != -1 and child[prv] == cur) pathidx[cur] = pathidx[prv];
        paths[pathidx[cur]].emplace_back(cur);
        for (auto& nxt: edge[cur]) if (nxt != prv) dfs2(nxt, cur);
    }
    int lca(int u, int v) {
        if (dep[u] > dep[v]) swap(u, v);
        for (int i = MAXLOG - 1; i >= 0; --i) if (dep[v] - dep[u] >= 1 << i) v = dbl[i][v];
        for (int i = MAXLOG - 1; i >= 0; --i) if (dbl[i][u] != dbl[i][v]) {
            u = dbl[i][u];
            v = dbl[i][v];
        }
        return (u == v) ? u : dbl[0][u];
    }
    void build(int root = 0) {
        dfs(root, root);
        dfs2(root, root);
        for (int i = 0; i < MAXLOG; ++i) {
            for (int j = 0; j < V; ++j) {
                dbl[i + 1][j] = dbl[i][dbl[i][j]];
            }
        }
    }
};

/*
    > Heavy-Light Decomposition
        * 木上のクエリをセグ木で処理できるようにするやつ
        * 基本的に頂点にコストがあるタイプのクエリを処理できる
        * 辺上にコストがあるときは, depが大きい方に大して処理するとよい
    $ Variables
        *     dep : 頂点の深さ
        *      sz : 頂点の部分木の大きさ
        * pathidx : 頂点が属するpathのidx (始点の頂点番号)
        *   child : 頂点の子のidx (なければ-1)
        *     idx : HeavyEdgeを繋げるためのやつ
        *    edge : グラフ
        *   paths : 各pathに属する点のvector
        *     dbl : LCA用のダブリングテーブル
    $ Functions
        @ 前処理
            HLD hld(100100);        // 100100頂点の木
            hld.add_edge(2, 6);     // 頂点2, 6間の無向辺を追加
            hld.build();            // いろいろbuildする
        @ クエリ
            hld.lca(a, b);          // 頂点a, bのLCA
            SegmentTree seg[100100];
            for (int i = 0; i < V; ++i)
                if (hld.pathidx[i] == i)
                    seg[i] = SegmentTree(hld.paths[i].size() + 2, init, func);
            query(u, v);            // 頂点u, v間のクエリ
            seg[hld.pathidx[u]].replace(hld.dep[u] - hld.dep[hld.pathidx[u]], val);
                                    // 頂点uに対するコスト変更クエリ
            遅延セグメント木のときはqueryみたいにすればいい
*/

// 単位元
const int INIT = 0;
const int MAXN = 100100;
HLD hld(MAXN);
SegmentTree<int> seg[MAXN];

int query(int u, int v) {
    int ret = INIT;
    if (hld.dep[u] < hld.dep[v]) swap(u, v);
    while (hld.pathidx[u] != hld.pathidx[v]) {
        ret += seg[hld.pathidx[u]].query(
            0,
            1 + hld.dep[u] - hld.dep[hld.pathidx[u]]
        );          // merge
        u = hld.dbl[0][hld.pathidx[u]];
    }
    if (u != v) {
        ret += seg[hld.pathidx[u]].query(
            1 + hld.dep[v] - hld.dep[hld.pathidx[u]],
            1 + hld.dep[u] - hld.dep[hld.pathidx[u]]
        );          // merge
    }
    return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

