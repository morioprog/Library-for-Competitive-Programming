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


# :warning: String/SuffixArray.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#27118326006d3829667a400ad23d5d98">String</a>
* <a href="{{ site.github.repository_url }}/blob/master/String/SuffixArray.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-27 20:20:28+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct SuffixArray {
    vector<int> SA;
    string s;
    SuffixArray(string &s) : s(s) {
        SA.resize(s.size());
        iota(begin(SA), end(SA), 0);
        sort(begin(SA), end(SA), [&](int a, int b) {
            return (s[a] == s[b]) ? a > b : s[a] < s[b];
        });
        vector<int> classes(s.size()), c(s.begin(), s.end()), cnt(s.size());
        for (int l = 1; l < s.size(); l <<= 1) {
            for (int i = 0; i < s.size(); i++) {
                if (i > 0 and c[SA[i - 1]] == c[SA[i]]
                          and   SA[i - 1] + l < s.size()
                          and c[SA[i - 1] + l / 2] == c[SA[i] + l / 2]) {
                    classes[SA[i]] = classes[SA[i - 1]];
                } else {
                    classes[SA[i]] = i;
                }
            }
            iota(begin(cnt), end(cnt), 0);
            copy(begin(SA), end(SA), begin(c));
            for (int i = 0; i < s.size(); i++) {
                int s1 = c[i] - l;
                if (s1 >= 0) SA[cnt[classes[s1]]++] = s1;
            }
            classes.swap(c);
        }
    }
    bool lt_substr(const string &t, int si = 0, int ti = 0) {
        int sn = (int)s.size(), tn = (int)t.size();
        while (si < sn and ti < tn) {
            if (s[si] < t[ti]) return true;
            if (s[si] > t[ti]) return false;
            ++si, ++ti;
        }
        return si >= sn and ti < tn;
    }
    int lower_bound(const string &t) {
        int low = -1, high = (int)SA.size();
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (lt_substr(t, SA[mid])) low = mid;
            else high = mid;
        }
        return high;
    }
    pair<int, int> lower_upper_bound(string &t) {
        int idx = lower_bound(t);
        int low = idx - 1, high = (int)SA.size();
        t.back()++;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (lt_substr(t, SA[mid])) low = mid;
            else high = mid;
        }
        t.back()--;
        return make_pair(idx, high);
    }
    void print() {
        for (int i = 0; i < size(); ++i) {
            cerr << i << " : " << s.substr(SA[i]) << endl;
        }
    }
};

/*
・SuffixArray
    > 構築 : O(NlogN)   [N : 文字列長]
    > クエリ : O(MlogN) [M : パターン長]
[使用例]
SuffixArray sa(S);          // 文字列Sに対するSuffixArrayを構築
sa.lower_upper_bound(T);    // 文字列Tを含む接尾辞のindexの下限と上限を返す
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "String/SuffixArray.cpp"
struct SuffixArray {
    vector<int> SA;
    string s;
    SuffixArray(string &s) : s(s) {
        SA.resize(s.size());
        iota(begin(SA), end(SA), 0);
        sort(begin(SA), end(SA), [&](int a, int b) {
            return (s[a] == s[b]) ? a > b : s[a] < s[b];
        });
        vector<int> classes(s.size()), c(s.begin(), s.end()), cnt(s.size());
        for (int l = 1; l < s.size(); l <<= 1) {
            for (int i = 0; i < s.size(); i++) {
                if (i > 0 and c[SA[i - 1]] == c[SA[i]]
                          and   SA[i - 1] + l < s.size()
                          and c[SA[i - 1] + l / 2] == c[SA[i] + l / 2]) {
                    classes[SA[i]] = classes[SA[i - 1]];
                } else {
                    classes[SA[i]] = i;
                }
            }
            iota(begin(cnt), end(cnt), 0);
            copy(begin(SA), end(SA), begin(c));
            for (int i = 0; i < s.size(); i++) {
                int s1 = c[i] - l;
                if (s1 >= 0) SA[cnt[classes[s1]]++] = s1;
            }
            classes.swap(c);
        }
    }
    bool lt_substr(const string &t, int si = 0, int ti = 0) {
        int sn = (int)s.size(), tn = (int)t.size();
        while (si < sn and ti < tn) {
            if (s[si] < t[ti]) return true;
            if (s[si] > t[ti]) return false;
            ++si, ++ti;
        }
        return si >= sn and ti < tn;
    }
    int lower_bound(const string &t) {
        int low = -1, high = (int)SA.size();
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (lt_substr(t, SA[mid])) low = mid;
            else high = mid;
        }
        return high;
    }
    pair<int, int> lower_upper_bound(string &t) {
        int idx = lower_bound(t);
        int low = idx - 1, high = (int)SA.size();
        t.back()++;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (lt_substr(t, SA[mid])) low = mid;
            else high = mid;
        }
        t.back()--;
        return make_pair(idx, high);
    }
    void print() {
        for (int i = 0; i < size(); ++i) {
            cerr << i << " : " << s.substr(SA[i]) << endl;
        }
    }
};

/*
・SuffixArray
    > 構築 : O(NlogN)   [N : 文字列長]
    > クエリ : O(MlogN) [M : パターン長]
[使用例]
SuffixArray sa(S);          // 文字列Sに対するSuffixArrayを構築
sa.lower_upper_bound(T);    // 文字列Tを含む接尾辞のindexの下限と上限を返す
*/

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

