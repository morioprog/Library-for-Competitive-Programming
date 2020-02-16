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


# :warning: Math/Combination/Pascal.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7693cf03c5044439a6fc880063ee3289">Math/Combination</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/Combination/Pascal.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-31 01:49:29+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
unsigned long long comb(unsigned long long n, unsigned int r) {
    if (r == 0) return 1;
    if (n < 0) return comb(-n + r - 1, r) * (r % 2 ? -1 : 1);
    if (n == 0 || r < 0 || n < r) return 0;
    unsigned long long ret = 1;
    for (unsigned long long i = 1; i <= r; ++i) (ret *= n--) /= i;
    return ret;
}

/*
・nが大きい(rが小さい)ときの組み合わせ
    > クエリ O(r)
[使用例] comb(n, r);     // nCr
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Math/Combination/Pascal.cpp"
unsigned long long comb(unsigned long long n, unsigned int r) {
    if (r == 0) return 1;
    if (n < 0) return comb(-n + r - 1, r) * (r % 2 ? -1 : 1);
    if (n == 0 || r < 0 || n < r) return 0;
    unsigned long long ret = 1;
    for (unsigned long long i = 1; i <= r; ++i) (ret *= n--) /= i;
    return ret;
}

/*
・nが大きい(rが小さい)ときの組み合わせ
    > クエリ O(r)
[使用例] comb(n, r);     // nCr
*/

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

