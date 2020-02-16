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


# :warning: Math/Prime/Eratosthenes.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#231e1df35934043e4793dedc0bd652e6">Math/Prime</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/Prime/Eratosthenes.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-10 12:53:05+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
vector<bool> Eratosthenes(const int n) {
    vector<bool> r(n + 1, true);
    for (int i = 2; i * i <= n; ++i) {
        if (r[i]) {
            for (int j = i * 2; j <= n; j += i) r[j] = false;
        }
    }
    if (r.size() > 2) {
        r[0] = r[1] = false;
    } else if (r.size() > 1) {
        r[0] = false;
    }
    return r;
}

/*
・エラトステネスの篩
    > O(NloglogN)
[使用例] vector<bool> prime = Eratosthenes(100000);
[備考] nが10^6以下のときに使うべき.
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Math/Prime/Eratosthenes.cpp"
vector<bool> Eratosthenes(const int n) {
    vector<bool> r(n + 1, true);
    for (int i = 2; i * i <= n; ++i) {
        if (r[i]) {
            for (int j = i * 2; j <= n; j += i) r[j] = false;
        }
    }
    if (r.size() > 2) {
        r[0] = r[1] = false;
    } else if (r.size() > 1) {
        r[0] = false;
    }
    return r;
}

/*
・エラトステネスの篩
    > O(NloglogN)
[使用例] vector<bool> prime = Eratosthenes(100000);
[備考] nが10^6以下のときに使うべき.
*/

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

