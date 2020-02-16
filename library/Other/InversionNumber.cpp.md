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


# :warning: Other/InversionNumber.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#6311ae17c1ee52b36e68aaf4ad066387">Other</a>
* <a href="{{ site.github.repository_url }}/blob/master/Other/InversionNumber.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-31 01:49:29+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<typename T> long long InversionNumber(vector< T > &v) {
    long long sz = v.size(), ret = 0;
    vector< T > rev, v_cp = v; sort(v_cp.begin(), v_cp.end());
    for (auto &e : v) rev.emplace_back(lower_bound(v_cp.begin(), v_cp.end(), e) - v_cp.begin());
    BinaryIndexedTree< T > bit(sz);
    for (int i = 0; i < sz; ++i) {
        ret += i - bit.sum(rev[i]);
        bit.add(rev[i], 1);
    }
    return ret;
}

/*
・転倒数 (Inversion Number)
    > O(NlogN)
[備考] i < j かつ a_i > a_j となる組(i, j)の個数. バブルソートのスワップ回数と等しい.
[注意] BinaryIndexedTreeを上で定義しておくこと.
[使用例]
vector<int> v = {3, 1, 5, 4, 2};
InversionNumber(v);     // == 5 : vの転倒数
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Other/InversionNumber.cpp"
template<typename T> long long InversionNumber(vector< T > &v) {
    long long sz = v.size(), ret = 0;
    vector< T > rev, v_cp = v; sort(v_cp.begin(), v_cp.end());
    for (auto &e : v) rev.emplace_back(lower_bound(v_cp.begin(), v_cp.end(), e) - v_cp.begin());
    BinaryIndexedTree< T > bit(sz);
    for (int i = 0; i < sz; ++i) {
        ret += i - bit.sum(rev[i]);
        bit.add(rev[i], 1);
    }
    return ret;
}

/*
・転倒数 (Inversion Number)
    > O(NlogN)
[備考] i < j かつ a_i > a_j となる組(i, j)の個数. バブルソートのスワップ回数と等しい.
[注意] BinaryIndexedTreeを上で定義しておくこと.
[使用例]
vector<int> v = {3, 1, 5, 4, 2};
InversionNumber(v);     // == 5 : vの転倒数
*/

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

