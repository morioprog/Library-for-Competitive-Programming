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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: Graph/Template.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/Template.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-10 12:53:05+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<typename T> struct Edge {
    int from, to;
    T weight;
    Edge() : from(0), to(0), weight(0) {}
    Edge(int f, int t, T w) : from(f), to(t), weight(w) {}
};
template<typename T> using Edges = vector< Edge< T > >;
template<typename T> using Graph = vector< Edges< T > >;
template<typename T> void     add_edge(Graph< T > &g, int from, int to, T w = 1) { g[from].emplace_back(from, to, w); g[to].emplace_back(to, from, w); }
template<typename T> void      add_arc(Graph< T > &g, int from, int to, T w = 1) { g[from].emplace_back(from, to, w); }
template<typename T> void add_to_edges(Edges< T > &e, int from, int to, T w = 1) { e.emplace_back(from, to, w); }

/*
・グラフ用テンプレート
    > Dijkstra
    > BellmanFord
    > WarshallFloyd
    > Kruskal
[応用] 単一終点最短路問題は, すべての有向辺を逆向きに張り替えると, 単一始点最短路問題に帰着できる.
[使用例]
Graph<int> g(V);                // 頂点数V, 重さの型がintのグラフを宣言
add_edge(g, a, b, c);           // グラフgに, 始点a, 終点b, 重さcの無向辺を追加
add_arc(g, a, b, c);            // グラフgに, 始点a, 終点b, 重さcの有向辺を追加
add_to_edges(edges, a, b, c);   // 辺集合edgesに, 始点a, 終点b, 重さcの辺を追加
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/Template.cpp"
template<typename T> struct Edge {
    int from, to;
    T weight;
    Edge() : from(0), to(0), weight(0) {}
    Edge(int f, int t, T w) : from(f), to(t), weight(w) {}
};
template<typename T> using Edges = vector< Edge< T > >;
template<typename T> using Graph = vector< Edges< T > >;
template<typename T> void     add_edge(Graph< T > &g, int from, int to, T w = 1) { g[from].emplace_back(from, to, w); g[to].emplace_back(to, from, w); }
template<typename T> void      add_arc(Graph< T > &g, int from, int to, T w = 1) { g[from].emplace_back(from, to, w); }
template<typename T> void add_to_edges(Edges< T > &e, int from, int to, T w = 1) { e.emplace_back(from, to, w); }

/*
・グラフ用テンプレート
    > Dijkstra
    > BellmanFord
    > WarshallFloyd
    > Kruskal
[応用] 単一終点最短路問題は, すべての有向辺を逆向きに張り替えると, 単一始点最短路問題に帰着できる.
[使用例]
Graph<int> g(V);                // 頂点数V, 重さの型がintのグラフを宣言
add_edge(g, a, b, c);           // グラフgに, 始点a, 終点b, 重さcの無向辺を追加
add_arc(g, a, b, c);            // グラフgに, 始点a, 終点b, 重さcの有向辺を追加
add_to_edges(edges, a, b, c);   // 辺集合edgesに, 始点a, 終点b, 重さcの辺を追加
*/

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

