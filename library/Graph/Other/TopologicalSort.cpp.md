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


# :warning: Graph/Other/TopologicalSort.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b52c23127d7c9f83ad18f1dce376656">Graph/Other</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/Other/TopologicalSort.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-10 12:53:05+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<typename T> bool TopologicalSort(const Graph< T > &g, vector<int> &order) {
    int V = g.size();
    vector<int> color(V);
    function<bool(int)> visit = [&](int v) {
        color[v] = 1;
        for (auto& e: g[v]) {
            if (color[e.to] == 2) continue;
            if (color[e.to] == 1) return false;
            if (!visit(e.to)) return false;
        }
        order.push_back(v); color[v] = 2;
        return true;
    };
    for (int i = 0; i < V; ++i) if (!color[i] and !visit(i)) return false;
    reverse(order.begin(), order.end());
    return true;
}

/*
・トポロジカルソート
    > O(E + V) [E:辺の数, V:頂点の数]
[備考] グラフの位相的順序を求める.
[使用例]
vector<int> ts;             // トポロジカルソートの結果を格納するvector.
TopologicalSort(g, ts);     // グラフgのトポロジカルソートの結果をtsに格納. 返り値はトポロジカルソート可能か否か.
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/Other/TopologicalSort.cpp"
template<typename T> bool TopologicalSort(const Graph< T > &g, vector<int> &order) {
    int V = g.size();
    vector<int> color(V);
    function<bool(int)> visit = [&](int v) {
        color[v] = 1;
        for (auto& e: g[v]) {
            if (color[e.to] == 2) continue;
            if (color[e.to] == 1) return false;
            if (!visit(e.to)) return false;
        }
        order.push_back(v); color[v] = 2;
        return true;
    };
    for (int i = 0; i < V; ++i) if (!color[i] and !visit(i)) return false;
    reverse(order.begin(), order.end());
    return true;
}

/*
・トポロジカルソート
    > O(E + V) [E:辺の数, V:頂点の数]
[備考] グラフの位相的順序を求める.
[使用例]
vector<int> ts;             // トポロジカルソートの結果を格納するvector.
TopologicalSort(g, ts);     // グラフgのトポロジカルソートの結果をtsに格納. 返り値はトポロジカルソート可能か否か.
*/

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

