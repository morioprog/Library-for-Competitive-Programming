/*
・Segment Tree Beats
[備考] 任意の区間に対するchminクエリなどを, O(logN)で処理できるデータ構造
[使用例]
SegmentTreeBeats seg(N);
seg.update_min(l, r, x);    // [l, r)をxにchmin
seg.update_max(l, r, x);    // [l, r)をxにchmax
seg.add_val(l, r, x);       // [l, r)にxを加算
seg.update_val(l, r, x);    // [l, r)をxに変更
seg.query_max(l, r);        // [l, r)の最大値
seg.query_min(l, r);        // [l, r)の最小値
seg.query_sum(l, r);        // [l, r)の総和
[参考] https://gist.github.com/tjkendev/20e7f96b9262f7a5d739bdc978c075bd
*/

struct SegmentTreeBeats {
    static const int_fast64_t INF = 1LL << 60;
    struct Node {
        Node *left, *right;
        int_fast64_t max_v, smax_v, max_c;
        int_fast64_t min_v, smin_v, min_c;
        int_fast64_t sum;
        int_fast64_t len, ladd, lval;

        Node() : left(0), right(0), ladd(0), lval(INF) {}

        void init(int_fast64_t x) {
            max_v = min_v = sum = x;
            smax_v = -INF; smin_v = INF;
            max_c = min_c = 1;
        }

        void init_empty() {
            max_v = smax_v = -INF;
            min_v = smin_v = INF;
            max_c = min_c = 0;
        }

        void update_max(int_fast64_t x) {
            sum += (x - max_v) * max_c;
            /* */if (max_v ==  min_v) max_v =  min_v = x;
            else if (max_v == smin_v) max_v = smin_v = x;
            else                      max_v = x;
            if (lval != INF and x < lval) lval = x;
        }

        void update_min(int_fast64_t x) {
            sum += (x - min_v) * min_c;
            /* */if (max_v ==  min_v) max_v =  min_v = x;
            else if (max_v == smin_v) min_v = smax_v = x;
            else                      min_v = x;
            if (lval != INF and lval < x) lval = x;
        }

        void addall(int_fast64_t x) {
            max_v += x;
            if (smax_v != -INF) smax_v += x;
            min_v += x;
            if (smin_v != INF) smin_v += x;
            sum += len * x;
            if (lval != INF) lval += x;
            else             ladd += x;
        }

        void updateall(int_fast64_t x) {
            max_v = min_v = x;
            smax_v = -INF; smin_v = INF;
            max_c = min_c = len;
            sum = len * x;
            lval = x; ladd = 0;
        }

        void push() {
            if (lval != INF) {
                 left -> updateall(lval);
                right -> updateall(lval);
                lval = INF;
                return;
            }
            if (ladd != 0) {
                 left -> addall(ladd);
                right -> addall(ladd);
                ladd = 0;
            }
            if (max_v < left -> max_v)   left -> update_max(max_v);
            if (left -> min_v < min_v)   left -> update_min(min_v);
            if (max_v < right -> max_v) right -> update_max(max_v);
            if (right -> min_v < min_v) right -> update_min(min_v);
        }

        void update() {
            sum = left -> sum + right -> sum;
            if (left -> max_v < right -> max_v) {
                max_v = right -> max_v;
                max_c = right -> max_c;
                smax_v = max(left -> max_v, right -> smax_v);
            } else if (left -> max_v > right -> max_v) {
                max_v = left -> max_v;
                max_c = left -> max_c;
                smax_v = max(left -> smax_v, right -> max_v);
            } else {
                max_v = left -> max_v;
                max_c = left -> max_c + right -> max_c;
                smax_v = max(left -> smax_v, right -> smax_v);
            }
            if (left -> min_v < right -> min_v) {
                min_v = left -> min_v;
                min_c = left -> min_c;
                smin_v = min(left -> smin_v, right -> min_v);
            } else if (left -> min_v > right -> min_v) {
                min_v = right -> min_v;
                min_c = right -> min_c;
                smin_v = min(left -> min_v, right -> smin_v);
            } else {
                min_v = left -> min_v;
                min_c = left -> min_c + right -> min_c;
                smin_v = min(left -> smin_v, right -> smin_v);
            }
        }
    };

    int n, n0;
    Node *root;

    void _update_min(int_fast64_t x, int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a || nd -> max_v <= x) return;
        if (a <= l && r <= b && nd -> smax_v < x) {
            nd -> update_max(x);
            return;
        }
        nd -> push();
        _update_min(x, a, b, nd ->  left, l, (l + r) >> 1);
        _update_min(x, a, b, nd -> right, (l + r) >> 1, r);
        nd -> update();
    }

    void _update_max(int_fast64_t x, int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a || x <= nd -> min_v) return;
        if (a <= l && r <= b && x < nd -> smin_v) {
            nd -> update_min(x);
            return;
        }
        nd -> push();
        _update_max(x, a, b, nd ->  left, l, (l + r) >> 1);
        _update_max(x, a, b, nd -> right, (l + r) >> 1, r);
        nd -> update();
    }

    void _add_val(int_fast64_t x, int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            nd -> addall(x);
            return;
        }
        nd -> push();
        _add_val(x, a, b, nd ->  left, l, (l + r) >> 1);
        _add_val(x, a, b, nd -> right, (l + r) >> 1, r);
        nd -> update();
    }

    void _update_val(int_fast64_t x, int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            nd -> updateall(x);
            return;
        }
        nd -> push();
        _update_val(x, a, b, nd ->  left, l, (l + r) >> 1);
        _update_val(x, a, b, nd -> right, (l + r) >> 1, r);
        nd -> update();
    }

    int_fast64_t _query_max(int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a) return -INF;
        if (a <= l && r <= b) return nd -> max_v;
        nd -> push();
        int_fast64_t lv = _query_max(a, b, nd ->  left, l, (l + r) >> 1);
        int_fast64_t rv = _query_max(a, b, nd -> right, (l + r) >> 1, r);
        return max(lv, rv);
    }

    int_fast64_t _query_min(int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a) return INF;
        if (a <= l && r <= b) return nd -> min_v;
        nd -> push();
        int_fast64_t lv = _query_min(a, b, nd ->  left, l, (l + r) >> 1);
        int_fast64_t rv = _query_min(a, b, nd -> right, (l + r) >> 1, r);
        return min(lv, rv);
    }

    int_fast64_t _query_sum(int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a) return 0;
        if (a <= l && r <= b) return nd -> sum;
        nd -> push();
        int_fast64_t lv = _query_sum(a, b, nd ->  left, l, (l + r) >> 1);
        int_fast64_t rv = _query_sum(a, b, nd -> right, (l + r) >> 1, r);
        return lv + rv;
    }

    SegmentTreeBeats(int n, int_fast64_t val = 0) : n(n) {
        n0 = 1; while (n0 < n) n0 <<= 1;
        Node *nds = new Node[2 * n0];
        root = nds;
        nds[0].len = n0;
        for (int i = 0; i < n0 - 1; ++i) {
            nds[i].left = &nds[2 * i + 1];
            nds[i].right = &nds[2 * i + 2];
            nds[2 * i + 1].len = nds[2 * i + 2].len = nds[i].len >> 1;
        }
        for (int i = 0; i <  n; ++i) nds[n0 - 1 + i].init(val);
        for (int i = n; i < n0; ++i) nds[n0 - 1 + i].init_empty();
        for (int i = n0 - 2; i >= 0; i--) nds[i].update();
    }
    
    SegmentTreeBeats(int n, vector<int_fast64_t> a) : n(n) {
        n0 = 1; while (n0 < n) n0 <<= 1;
        Node *nds = new Node[2 * n0];
        root = nds;
        nds[0].len = n0;
        for (int i = 0; i < n0 - 1; ++i) {
            nds[i].left = &nds[2 * i + 1];
            nds[i].right = &nds[2 * i + 2];
            nds[2 * i + 1].len = nds[2 * i + 2].len = nds[i].len >> 1;
        }
        assert(n == (int)a.size());
        for (int i = 0; i <  n; ++i) nds[n0 - 1 + i].init(a[i]);
        for (int i = n; i < n0; ++i) nds[n0 - 1 + i].init_empty();
        for (int i = n0 - 2; i >= 0; i--) nds[i].update();
    }

    void update_min(int a, int b, int_fast64_t x) { _update_min(x, a, b, root, 0, n0); }
    void update_max(int a, int b, int_fast64_t x) { _update_max(x, a, b, root, 0, n0); }
    void    add_val(int a, int b, int_fast64_t x) {    _add_val(x, a, b, root, 0, n0); }
    void update_val(int a, int b, int_fast64_t x) { _update_val(x, a, b, root, 0, n0); }
    int_fast64_t query_max(int a, int b) { return _query_max(a, b, root, 0, n0); }
    int_fast64_t query_min(int a, int b) { return _query_min(a, b, root, 0, n0); }
    int_fast64_t query_sum(int a, int b) { return _query_sum(a, b, root, 0, n0); }
};
