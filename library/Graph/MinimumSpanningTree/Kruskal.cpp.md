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


# :warning: Graph/MinimumSpanningTree/Kruskal.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#f8a1cf37a37022434f9ae23f04a9bb06">Graph/MinimumSpanningTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/MinimumSpanningTree/Kruskal.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-10 12:53:05+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<typename T> T Kruskal(Edges< T > &edges, int V) {
    sort(begin(edges), end(edges), [](const Edge< T > &a, const Edge< T > &b) {
        return (a.weight < b.weight);
    });
    UnionFind tree(V);
    T ret = 0;
    for (auto &e : edges) if (tree.unite(e.from, e.to)) ret += e.weight;
    return ret;
}

/*
・Kruskal法
    > O(ElogV) [E:辺の数, V:頂点の数]
[備考] 最小全域木を求めるアルゴリズム.
      UnionFindで, 閉路を作らないように辺を重みが小さい順に加えていく.
[注意] UnionFindを上で定義しておくこと.
[使用例]
Edges<int> edges;           // 全ての辺 (重さ: int)
add_to_edges(edges,a,b,c);  // 辺集合edgesに, 始点a, 終点b, 重さcの辺を追加
Kruskal(edges,V);           // 辺edges, 頂点数Vのグラフにおける最小全域木の重さ
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/MinimumSpanningTree/Kruskal.cpp"
template<typename T> T Kruskal(Edges< T > &edges, int V) {
    sort(begin(edges), end(edges), [](const Edge< T > &a, const Edge< T > &b) {
        return (a.weight < b.weight);
    });
    UnionFind tree(V);
    T ret = 0;
    for (auto &e : edges) if (tree.unite(e.from, e.to)) ret += e.weight;
    return ret;
}

/*
・Kruskal法
    > O(ElogV) [E:辺の数, V:頂点の数]
[備考] 最小全域木を求めるアルゴリズム.
      UnionFindで, 閉路を作らないように辺を重みが小さい順に加えていく.
[注意] UnionFindを上で定義しておくこと.
[使用例]
Edges<int> edges;           // 全ての辺 (重さ: int)
add_to_edges(edges,a,b,c);  // 辺集合edgesに, 始点a, 終点b, 重さcの辺を追加
Kruskal(edges,V);           // 辺edges, 頂点数Vのグラフにおける最小全域木の重さ
*/

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

