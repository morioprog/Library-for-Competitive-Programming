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


# :warning: Other/Conversion.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#6311ae17c1ee52b36e68aaf4ad066387">Other</a>
* <a href="{{ site.github.repository_url }}/blob/master/Other/Conversion.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-31 01:49:29+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
inline unsigned long long toInt(string s) {
    unsigned long long v;
    istringstream sin(s);
    sin >> v;
    return v;
}
template<typename T> inline string toString(T x) {
    ostringstream sout;
    sout << x;
    return sout.str();
}
template<typename T> inline void ntos(const T &n, string &s) {
    stringstream stream;
    stream << n;
    stream >> s;
}
template<typename T> inline void ston(const string &s, T &n) {
    stringstream stream(s);
    stream >> n;
}

/*
・文字列と整数同士の変換
[使用例]
toInt("222") / 2    // == 111
toString(222) + 2   // == 224
int n = 9876; string t; ntos(n, t);     // t == "9876"
string s = "1234"; int m; ston(s, m);   // m == 1234
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Other/Conversion.cpp"
inline unsigned long long toInt(string s) {
    unsigned long long v;
    istringstream sin(s);
    sin >> v;
    return v;
}
template<typename T> inline string toString(T x) {
    ostringstream sout;
    sout << x;
    return sout.str();
}
template<typename T> inline void ntos(const T &n, string &s) {
    stringstream stream;
    stream << n;
    stream >> s;
}
template<typename T> inline void ston(const string &s, T &n) {
    stringstream stream(s);
    stream >> n;
}

/*
・文字列と整数同士の変換
[使用例]
toInt("222") / 2    // == 111
toString(222) + 2   // == 224
int n = 9876; string t; ntos(n, t);     // t == "9876"
string s = "1234"; int m; ston(s, m);   // m == 1234
*/

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

