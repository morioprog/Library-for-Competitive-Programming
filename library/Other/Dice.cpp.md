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


# :warning: Other/Dice.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#6311ae17c1ee52b36e68aaf4ad066387">Other</a>
* <a href="{{ site.github.repository_url }}/blob/master/Other/Dice.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-10 12:53:05+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// 下にy, 右にx
enum { R, U, L, D };
int dx[] = { 1,  0, -1, 0 };
int dy[] = { 0, -1,  0, 1 };

struct Dice {
    int T, N, E, S, W, B;
    int table[6][6] = {
        { 0, 3, 5, 2, 4, 0 },
        { 4, 0, 1, 6, 0, 3 },
        { 2, 6, 0, 0, 1, 5 },
        { 5, 1, 0, 0, 6, 2 },
        { 3, 0, 6, 1, 0, 4 },
        { 0, 4, 2, 5, 3, 0 }
    };
    Dice(int T, int S) : T(T), S(S) { build(); }
    void build() {
        E = table[T - 1][S - 1];
        tie(N, W, B) = make_tuple(7 - S, 7 - E, 7 - T);
        // swap(E, W);  // もう1種類のサイコロの場合
    }
    void rot(int dir) {
        if (dir == R) tie(T, S) = make_pair(W, S);
        if (dir == U) tie(T, S) = make_pair(S, B);
        if (dir == L) tie(T, S) = make_pair(E, S);
        if (dir == D) tie(T, S) = make_pair(N, T);
        // tie(T, S) = (vector<pair<int,int>>){{W, S}, {S, B}, {E, S}, {N, T}}[dir];
        build();
    }
    int get(int m) {
        return (vector<int>){E, N, W, S}[m];
    }
};

/*
・サイコロ
[使用例]
Dice dc(T, S);      // TとSが下図のような位置関係のサイコロを作成
dc.rot(R);          // 右方向に回転
dc.get(idx);        // 側面の目を返す(ループを回すときに使う) ここでは{R, U, L, D}の順
       _______
      /\      \           N(U)
     /  \   T  \           |            4
    /    \______\  W(L) - T,B - E(R)  2 1 5 6
    \ S  /      /          |            3
     \  /   E  /          S(D)
      \/______/
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Other/Dice.cpp"
// 下にy, 右にx
enum { R, U, L, D };
int dx[] = { 1,  0, -1, 0 };
int dy[] = { 0, -1,  0, 1 };

struct Dice {
    int T, N, E, S, W, B;
    int table[6][6] = {
        { 0, 3, 5, 2, 4, 0 },
        { 4, 0, 1, 6, 0, 3 },
        { 2, 6, 0, 0, 1, 5 },
        { 5, 1, 0, 0, 6, 2 },
        { 3, 0, 6, 1, 0, 4 },
        { 0, 4, 2, 5, 3, 0 }
    };
    Dice(int T, int S) : T(T), S(S) { build(); }
    void build() {
        E = table[T - 1][S - 1];
        tie(N, W, B) = make_tuple(7 - S, 7 - E, 7 - T);
        // swap(E, W);  // もう1種類のサイコロの場合
    }
    void rot(int dir) {
        if (dir == R) tie(T, S) = make_pair(W, S);
        if (dir == U) tie(T, S) = make_pair(S, B);
        if (dir == L) tie(T, S) = make_pair(E, S);
        if (dir == D) tie(T, S) = make_pair(N, T);
        // tie(T, S) = (vector<pair<int,int>>){{W, S}, {S, B}, {E, S}, {N, T}}[dir];
        build();
    }
    int get(int m) {
        return (vector<int>){E, N, W, S}[m];
    }
};

/*
・サイコロ
[使用例]
Dice dc(T, S);      // TとSが下図のような位置関係のサイコロを作成
dc.rot(R);          // 右方向に回転
dc.get(idx);        // 側面の目を返す(ループを回すときに使う) ここでは{R, U, L, D}の順
       _______
      /\      \           N(U)
     /  \   T  \           |            4
    /    \______\  W(L) - T,B - E(R)  2 1 5 6
    \ S  /      /          |            3
     \  /   E  /          S(D)
      \/______/
*/

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

