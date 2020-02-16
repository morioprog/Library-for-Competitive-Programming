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


# :warning: Graph/ShortestPath/BellmanFord.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#63e7c27a061fb3fc2cf460abce6a2012">Graph/ShortestPath</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/ShortestPath/BellmanFord.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-10 12:53:05+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<typename T> vector< T > BellmanFord(Edges< T > &edges, int vertex, int from) {
    const auto INF = numeric_limits< T >::max() / 10;
    vector< T > dist(vertex, INF);
    dist[from] = 0;
    for (int i = 0; i < vertex - 1; ++i) {
        for (auto &e : edges) {
            if (dist[e.from] == INF) continue;
            dist[e.to] = min(dist[e.to], dist[e.from] + e.weight);
        }
    }
    for (auto &e : edges) {
        if (dist[e.from] == INF) continue;
        if (dist[e.from] + e.weight < dist[e.to]) return vector< T >();
    }
    return dist;
}

/*
・ベルマンフォード法
    > O(E * V) [E:辺の数, V:頂点の数]
[備考] グラフ(負辺が存在してもよい)に対する単一始点全点間最短路を求めるアルゴリズム
      負閉路が存在しているかの判定も可能 -> 存在していたら空列を返す
[注意] 結果を足し合わせる際, INFの大きさに注意
[使用例]
Edges<int> edges;                       // 全ての辺 (重さ: int)
add_to_edges(edges, a, b, c);           // 辺集合edgesに, 始点a, 終点b, 重さcの辺を追加
auto bf = BellmanFord(edges, V, s);     // 辺edges, 頂点数Vのグラフにおける, 始点sからの最短路
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/ShortestPath/BellmanFord.cpp"
template<typename T> vector< T > BellmanFord(Edges< T > &edges, int vertex, int from) {
    const auto INF = numeric_limits< T >::max() / 10;
    vector< T > dist(vertex, INF);
    dist[from] = 0;
    for (int i = 0; i < vertex - 1; ++i) {
        for (auto &e : edges) {
            if (dist[e.from] == INF) continue;
            dist[e.to] = min(dist[e.to], dist[e.from] + e.weight);
        }
    }
    for (auto &e : edges) {
        if (dist[e.from] == INF) continue;
        if (dist[e.from] + e.weight < dist[e.to]) return vector< T >();
    }
    return dist;
}

/*
・ベルマンフォード法
    > O(E * V) [E:辺の数, V:頂点の数]
[備考] グラフ(負辺が存在してもよい)に対する単一始点全点間最短路を求めるアルゴリズム
      負閉路が存在しているかの判定も可能 -> 存在していたら空列を返す
[注意] 結果を足し合わせる際, INFの大きさに注意
[使用例]
Edges<int> edges;                       // 全ての辺 (重さ: int)
add_to_edges(edges, a, b, c);           // 辺集合edgesに, 始点a, 終点b, 重さcの辺を追加
auto bf = BellmanFord(edges, V, s);     // 辺edges, 頂点数Vのグラフにおける, 始点sからの最短路
*/

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

