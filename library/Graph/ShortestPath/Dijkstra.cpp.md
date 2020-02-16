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


# :warning: Graph/ShortestPath/Dijkstra.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#63e7c27a061fb3fc2cf460abce6a2012">Graph/ShortestPath</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/ShortestPath/Dijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-10 12:53:05+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<typename T> vector< T > Dijkstra(Graph< T > &g, int from) {
    const auto INF = numeric_limits< T >::max() / 10;
    vector< T > dist(g.size(), INF);
    dist[from] = 0;
    using P = pair< T, int >;
    priority_queue< P, vector< P >, greater< P > > que;
    que.emplace(dist[from], from);
    while (not que.empty()) {
        T weight; int idx;
        tie(weight, idx) = que.top(); que.pop();
        if (dist[idx] < weight) continue;
        for (auto &e : g[idx]) {
            auto next_weight = weight + e.weight;
            if (dist[e.to] <= next_weight) continue;
            dist[e.to] = next_weight;
            que.emplace(dist[e.to], e.to);
        }
    }
    return dist;
}

/*
・ダイクストラ法
    > O(ElogV) [E:辺の数, V:頂点の数]
[備考] 負辺の存在しないグラフに対する単一始点全点間最短路を求めるアルゴリズム
[注意] 結果を足し合わせる際, INFの大きさに注意
[使用例] auto dij = Dijkstra(g, s);     // グラフgにおける, 始点sからの最短路
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/ShortestPath/Dijkstra.cpp"
template<typename T> vector< T > Dijkstra(Graph< T > &g, int from) {
    const auto INF = numeric_limits< T >::max() / 10;
    vector< T > dist(g.size(), INF);
    dist[from] = 0;
    using P = pair< T, int >;
    priority_queue< P, vector< P >, greater< P > > que;
    que.emplace(dist[from], from);
    while (not que.empty()) {
        T weight; int idx;
        tie(weight, idx) = que.top(); que.pop();
        if (dist[idx] < weight) continue;
        for (auto &e : g[idx]) {
            auto next_weight = weight + e.weight;
            if (dist[e.to] <= next_weight) continue;
            dist[e.to] = next_weight;
            que.emplace(dist[e.to], e.to);
        }
    }
    return dist;
}

/*
・ダイクストラ法
    > O(ElogV) [E:辺の数, V:頂点の数]
[備考] 負辺の存在しないグラフに対する単一始点全点間最短路を求めるアルゴリズム
[注意] 結果を足し合わせる際, INFの大きさに注意
[使用例] auto dij = Dijkstra(g, s);     // グラフgにおける, 始点sからの最短路
*/

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

