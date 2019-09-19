/*
・SuffixArray
    > 構築 : O(NlogN)   [N : 文字列長]
    > クエリ : O(MlogN) [M : パターン長]
[使用例]
SuffixArray sa(S);          // 文字列Sに対するSuffixArrayを構築
sa.lower_upper_bound(T);    // 文字列Tを含む接尾辞のindexの下限と上限を返す
*/

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
    void debug() {
        for (int i = 0; i < size(); ++i) {
            cerr << i << " : " << s.substr(SA[i]) << endl;
        }
    }
};
