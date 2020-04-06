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


# :heavy_check_mark: DataStructure/SparseTable.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/SparseTable.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-07 23:30:45+09:00


* see: <a href="https://judge.yosupo.jp/problem/staticrmq">https://judge.yosupo.jp/problem/staticrmq</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/SparseTable.cpp.html">DataStructure/SparseTable.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <bits/stdc++.h>
using namespace std;

#include "SparseTable.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for (auto& e: A) cin >> e;
    SparseTable<int> st(A);

    while (Q--) {
        int L, R;
        cin >> L >> R;
        cout << st.query(L, R) << endl;
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/SparseTable.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <bits/stdc++.h>
using namespace std;

#line 1 "DataStructure/SparseTable.cpp"
template<typename T> struct SparseTable {
    vector< vector< T > > st;
    SparseTable() {}
    SparseTable(const vector< T > &v) {
        int b = 0;
        while ((1 << b) <= v.size()) ++b;
        st.assign(b, vector< T >(1LL << b));
        for (int i = 0; i < v.size(); ++i) st[0][i] = v[i];
        for (int i = 1; i < b; ++i) {
            for (int j = 0; j + (1LL << i) <= (1LL << b); ++j) {
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1LL << (i - 1))]);
            }
        }
    }
    inline T query(int l, int r) {
        int b = 32 - __builtin_clz(r - l) - 1;
        return (min(st[b][l], st[b][r - (1LL << b)]));
    }
};

/*
・SparseTable
    > 前処理 O(NlogN)
    > query O(1)
[備考] 静的な配列における, 任意区間の最小値を定数時間で求められるデータ構造.
[使用例]
SparseTable<int> st(V);     // V(vector<int>)で初期化し, 前処理を行う
st.query(l, r);             // 半開区間[l, r)における最小値
*/
#line 7 "DataStructure/SparseTable.test.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for (auto& e: A) cin >> e;
    SparseTable<int> st(A);

    while (Q--) {
        int L, R;
        cin >> L >> R;
        cout << st.query(L, R) << endl;
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

