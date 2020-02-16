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


# :warning: DataStructure/CumulativeSum/CumulativeSum2D.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#767aa3a8651144736ca7f91920f93f07">DataStructure/CumulativeSum</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/CumulativeSum/CumulativeSum2D.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-31 01:49:29+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<typename T = long long> struct CumulativeSum2D {
    vector< vector< T > > data;
    CumulativeSum2D(int H, int W) : data(H + 1, vector<T>(W + 1, 0)) {}
    void add(int x, int y, int z) {
        ++x, ++y;
        if (x >= data.size() || y >= data[0].size()) return;
        data[x][y] += z;
    }
    void build() {
        for(int i = 1; i < data.size(); ++i) {
            for(int j = 1; j < data[i].size(); ++j) {
                data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
            }
        }
    }
    T query(int sx, int sy, int gx, int gy) {
        return (data[gx][gy] - data[sx][gy] - data[gx][sy] + data[sx][sy]);
    }
};

/*
・2次元累積和
    >     build O(H * W)
    > add,query O(1)
[使用例]
CumulativeSum2D<int> acc(H, W);     // acc[H + 1][W + 1]
acc.add(L, R, x);                   // 要素(L, R)に値xを加える
acc.build();                        // 累積和を取る
acc.query(a, b, c, d);              // [a, b]から(c, d)までの和
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/CumulativeSum/CumulativeSum2D.cpp"
template<typename T = long long> struct CumulativeSum2D {
    vector< vector< T > > data;
    CumulativeSum2D(int H, int W) : data(H + 1, vector<T>(W + 1, 0)) {}
    void add(int x, int y, int z) {
        ++x, ++y;
        if (x >= data.size() || y >= data[0].size()) return;
        data[x][y] += z;
    }
    void build() {
        for(int i = 1; i < data.size(); ++i) {
            for(int j = 1; j < data[i].size(); ++j) {
                data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
            }
        }
    }
    T query(int sx, int sy, int gx, int gy) {
        return (data[gx][gy] - data[sx][gy] - data[gx][sy] + data[sx][sy]);
    }
};

/*
・2次元累積和
    >     build O(H * W)
    > add,query O(1)
[使用例]
CumulativeSum2D<int> acc(H, W);     // acc[H + 1][W + 1]
acc.add(L, R, x);                   // 要素(L, R)に値xを加える
acc.build();                        // 累積和を取る
acc.query(a, b, c, d);              // [a, b]から(c, d)までの和
*/

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

