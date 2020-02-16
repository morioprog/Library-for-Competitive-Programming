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


# :warning: Other/Compression.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#6311ae17c1ee52b36e68aaf4ad066387">Other</a>
* <a href="{{ site.github.repository_url }}/blob/master/Other/Compression.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-10 12:53:05+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// template<typename T> vector<T> compress(vector<T> ord, map<T, int> &rev) {
template<typename T> vector<T> compress(vector<T> ord) { map<T, int> rev;
    vector< T > com = ord;
    sort(com.begin(), com.end());
    com.erase(unique(com.begin(), com.end()), com.end());
    for (int i = 0; i < com.size(); ++i) rev[com[i]] = i;
    vector< T > ret; for (auto& e : ord) ret.emplace_back(rev[e]);
    return ret;
}

/*
・座標圧縮
    > O(NlogN)
[備考] 各数字の対応関係が欲しいときは, 引数にmapを入れてコメントアウトを外す.
[使用例]
1. 引数にmapを入れない場合
vector<long long> com = compress(v);
2. 引数にmapを入れる場合
map<long long, int> rev;
vector<long long> com = compress(v, rev);
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Other/Compression.cpp"
// template<typename T> vector<T> compress(vector<T> ord, map<T, int> &rev) {
template<typename T> vector<T> compress(vector<T> ord) { map<T, int> rev;
    vector< T > com = ord;
    sort(com.begin(), com.end());
    com.erase(unique(com.begin(), com.end()), com.end());
    for (int i = 0; i < com.size(); ++i) rev[com[i]] = i;
    vector< T > ret; for (auto& e : ord) ret.emplace_back(rev[e]);
    return ret;
}

/*
・座標圧縮
    > O(NlogN)
[備考] 各数字の対応関係が欲しいときは, 引数にmapを入れてコメントアウトを外す.
[使用例]
1. 引数にmapを入れない場合
vector<long long> com = compress(v);
2. 引数にmapを入れる場合
map<long long, int> rev;
vector<long long> com = compress(v, rev);
*/

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

