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


# :warning: Graph/BipartiteGraph/BipartiteGraphCheck.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ddc24df04f6fe78c2fc801ef08553b61">Graph/BipartiteGraph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/BipartiteGraph/BipartiteGraphCheck.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-10 12:53:05+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <typename T> bool isBipartiteGraph(const Graph< T > &g) {
    int V = g.size();
    vector<int> color(V, 0);
    bool ret = true;
    function<void(int, int)> dfs = [&](int i, int clr) {
        if (color[i] != 0) return;
        color[i] = clr;
        for (auto& e: g[i]) {
            if (color[e.to] == 0) dfs(e.to, -clr);
            else if (color[e.to] == clr) ret = false;
        }
    };
    dfs(0, 1);
    return ret;
    int cnt = 0;
    for (auto& e: color) if (e == 1) ++cnt;
    return ret ? -1 : cnt;
}

/*
・二部グラフの判定
    > O(E+V) [E:辺の数, V:頂点の数]
[備考] 二部グラフならtrueを返す.
[使用例] isBipartiteGraph(g);
[その他] 二部グラフだった際に, 片方の集合の大きさが知りたい場合は, return retを削除して, intを返すようにする.
        その場合は, 二部グラフならばその集合の大きさを, そうでない場合は-1を返す.
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/BipartiteGraph/BipartiteGraphCheck.cpp"
template <typename T> bool isBipartiteGraph(const Graph< T > &g) {
    int V = g.size();
    vector<int> color(V, 0);
    bool ret = true;
    function<void(int, int)> dfs = [&](int i, int clr) {
        if (color[i] != 0) return;
        color[i] = clr;
        for (auto& e: g[i]) {
            if (color[e.to] == 0) dfs(e.to, -clr);
            else if (color[e.to] == clr) ret = false;
        }
    };
    dfs(0, 1);
    return ret;
    int cnt = 0;
    for (auto& e: color) if (e == 1) ++cnt;
    return ret ? -1 : cnt;
}

/*
・二部グラフの判定
    > O(E+V) [E:辺の数, V:頂点の数]
[備考] 二部グラフならtrueを返す.
[使用例] isBipartiteGraph(g);
[その他] 二部グラフだった際に, 片方の集合の大きさが知りたい場合は, return retを削除して, intを返すようにする.
        その場合は, 二部グラフならばその集合の大きさを, そうでない場合は-1を返す.
*/

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

