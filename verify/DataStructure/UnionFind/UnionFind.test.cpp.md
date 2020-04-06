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


# :heavy_check_mark: DataStructure/UnionFind/UnionFind.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#b443a6615f54d47cc94a593840724581">DataStructure/UnionFind</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/UnionFind/UnionFind.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-07 23:35:22+09:00


* see: <a href="https://judge.yosupo.jp/problem/unionfind">https://judge.yosupo.jp/problem/unionfind</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/DataStructure/UnionFind/UnionFind.cpp.html">DataStructure/UnionFind/UnionFind.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <bits/stdc++.h>
using namespace std;

#include "UnionFind.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    while (Q--) {
        int T, U, V;
        cin >> T >> U >> V;
        if (T == 0) uf.unite(U, V);
        else        cout << uf.same(U, V) << endl;
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/UnionFind/UnionFind.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <bits/stdc++.h>
using namespace std;

#line 1 "DataStructure/UnionFind/UnionFind.cpp"
struct UnionFind {
    vector<int> parent;
    int __size;
    UnionFind(int size_) : parent(size_, -1), __size(size_) {}
    bool unite(int x, int y) {
        if ((x = find(x)) != (y = find(y))) {
            if (parent[y] < parent[x]) swap(x, y);
            parent[x] += parent[y];
            parent[y] = x;
            __size--;
            return true;
        }
        return false;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int find(int x) { return parent[x] < 0 ? x : parent[x] = find(parent[x]); }
    int size(int x) { return -parent[find(x)]; }
    int size() { return __size; }
};

/*
・UnionFind木
    > O(α(n))
[使用例]
UnionFind uf(V);    // 頂点数VのUnionFind木を宣言
uf.unite(a, b);     // 点a, b([0, n))が同じ集合に属する (すでに同じだったらfalseを返す)
uf.same(a, b);      // 点a, bが同じ集合に属するか確認
uf.find(a);         // 点aが属する集合を求める
uf.size(a);         // 点aが属する集合の要素の数を求める
*/
#line 7 "DataStructure/UnionFind/UnionFind.test.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    while (Q--) {
        int T, U, V;
        cin >> T >> U >> V;
        if (T == 0) uf.unite(U, V);
        else        cout << uf.same(U, V) << endl;
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

