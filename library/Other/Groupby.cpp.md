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


# :warning: Other/Groupby.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#6311ae17c1ee52b36e68aaf4ad066387">Other</a>
* <a href="{{ site.github.repository_url }}/blob/master/Other/Groupby.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-10 12:53:05+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<typename T> vector< pair< T, int > > groupby(const vector< T > &vec) {
    vector< pair< T, int > > ret;
    int piv = -1;
    for (auto &e: vec) {
        if (piv == -1 or ret[piv].first != e) ++piv, ret.emplace_back(make_pair(e, 1));
        else ++(ret[piv].second);
    }
    return ret;
}

/*
・ランレングス圧縮
[備考] stringについて用いる場合は, vector<char>に以下のようにして一旦移し替える.
      string str;
      vector<char> vec(str.begin(), str.end());
[使用例]
vector<int> vec = {1, 5, 5, 7, 7, 7, 7};
auto gb = groupby(vec);     // {{1, 1}, {5, 2}, {7, 4}}
[蛇足] 命名はPythonに準拠
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Other/Groupby.cpp"
template<typename T> vector< pair< T, int > > groupby(const vector< T > &vec) {
    vector< pair< T, int > > ret;
    int piv = -1;
    for (auto &e: vec) {
        if (piv == -1 or ret[piv].first != e) ++piv, ret.emplace_back(make_pair(e, 1));
        else ++(ret[piv].second);
    }
    return ret;
}

/*
・ランレングス圧縮
[備考] stringについて用いる場合は, vector<char>に以下のようにして一旦移し替える.
      string str;
      vector<char> vec(str.begin(), str.end());
[使用例]
vector<int> vec = {1, 5, 5, 7, 7, 7, 7};
auto gb = groupby(vec);     // {{1, 1}, {5, 2}, {7, 4}}
[蛇足] 命名はPythonに準拠
*/

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

