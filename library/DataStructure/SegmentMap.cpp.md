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


# :warning: DataStructure/SegmentMap.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/SegmentMap.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-31 01:49:29+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct SegmentMap : public map<long long, long long> {
    bool flagToMergeAdjacentSegment;
    SegmentMap(bool flagToMergeAdjacentSegment) : flagToMergeAdjacentSegment(flagToMergeAdjacentSegment) {}
    auto get(long long p) const {
        auto it = upper_bound(p);
        if (it == begin() or (--it)->second < p) return end();
        return it;
    }
    void insert(long long l, long long r) {
        auto itl = upper_bound(l), itr = upper_bound(r + flagToMergeAdjacentSegment);
        if (itl != begin()) {
            if ((--itl)->second < l - flagToMergeAdjacentSegment) ++itl;
        }
        if (itl != itr) {
            l = min(l, itl->first);
            r = max(r, prev(itr)->second);
            erase(itl, itr);
        }
        (*this)[l] = r;
    }
    void remove(long long l, long long r) {
        auto itl = upper_bound(l), itr = upper_bound(r);
        if (itl != begin()) {
            if ((--itl)->second < l) ++itl;
        }
        if (itl == itr) return;
        int tl = min(l, itl->first), tr = max(r, prev(itr)->second);
        erase(itl, itr);
        if (tl < l) (*this)[tl] = l - 1;
        if (r < tr) (*this)[r + 1] = tr;
    }
    bool same(long long p, long long q) const {
        const auto&& it = get(p);
        return it != end() and it->first <= q and q <= it->second;
    }
};

/*
・SegmentMap
[備考] 区間をmapで管理するやつ
[注意] 以下で扱う区間は全て閉区間
[使用例]
SegmentMap mp(flag);    // flagがtrueなら, [l, c]と[c + 1, r]をマージする
mp.get(p);              // pを含む区間を返す(存在しないならmp.end())
mp.insert(l, r);        // 閉区間[l, r]を追加する
mp.remove(l, r);        // 閉区間[l, r]を取り除く
mp.same(p, q);          // 2点p, qが同じ区間にあればtrue
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/SegmentMap.cpp"
struct SegmentMap : public map<long long, long long> {
    bool flagToMergeAdjacentSegment;
    SegmentMap(bool flagToMergeAdjacentSegment) : flagToMergeAdjacentSegment(flagToMergeAdjacentSegment) {}
    auto get(long long p) const {
        auto it = upper_bound(p);
        if (it == begin() or (--it)->second < p) return end();
        return it;
    }
    void insert(long long l, long long r) {
        auto itl = upper_bound(l), itr = upper_bound(r + flagToMergeAdjacentSegment);
        if (itl != begin()) {
            if ((--itl)->second < l - flagToMergeAdjacentSegment) ++itl;
        }
        if (itl != itr) {
            l = min(l, itl->first);
            r = max(r, prev(itr)->second);
            erase(itl, itr);
        }
        (*this)[l] = r;
    }
    void remove(long long l, long long r) {
        auto itl = upper_bound(l), itr = upper_bound(r);
        if (itl != begin()) {
            if ((--itl)->second < l) ++itl;
        }
        if (itl == itr) return;
        int tl = min(l, itl->first), tr = max(r, prev(itr)->second);
        erase(itl, itr);
        if (tl < l) (*this)[tl] = l - 1;
        if (r < tr) (*this)[r + 1] = tr;
    }
    bool same(long long p, long long q) const {
        const auto&& it = get(p);
        return it != end() and it->first <= q and q <= it->second;
    }
};

/*
・SegmentMap
[備考] 区間をmapで管理するやつ
[注意] 以下で扱う区間は全て閉区間
[使用例]
SegmentMap mp(flag);    // flagがtrueなら, [l, c]と[c + 1, r]をマージする
mp.get(p);              // pを含む区間を返す(存在しないならmp.end())
mp.insert(l, r);        // 閉区間[l, r]を追加する
mp.remove(l, r);        // 閉区間[l, r]を取り除く
mp.same(p, q);          // 2点p, qが同じ区間にあればtrue
*/

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

