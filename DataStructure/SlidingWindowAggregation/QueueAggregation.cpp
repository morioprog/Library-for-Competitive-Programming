template <typename T> struct QueueAggregation {
    using F = function<T(T, T)>;
    stack<pair<T, T>> st_f, st_b;   // {val, sum}
    F func;
    QueueAggregation(const F f) : func(f) {}
    bool empty() const { return st_f.empty() and st_b.empty(); }
    int   size() const { return st_f.size()   +  st_b.empty(); }
    T query() {
        assert(not empty());
        if (st_f.empty()) return st_b.top().second;
        if (st_b.empty()) return st_f.top().second;
        return func(st_f.top().second, st_b.top().second);
    }
    void push(const T &x) {
        if (st_b.empty()) {
            st_b.emplace(x, x);
        } else {
            T merged = func(st_b.top().second, x);
            st_b.emplace(x, merged);
        }
    }
    void pop() {
        assert(not empty());
        if (st_f.empty()) {
            st_f.emplace(st_b.top().first, st_b.top().first);
            st_b.pop();
            while (not st_b.empty()) {
                T merged = func(st_b.top().first, st_f.top().second);
                st_f.emplace(st_b.top().first, merged);
                st_b.pop();
            }
        }
        st_f.pop();
    }
};

/*
・Queue Aggregation
[備考] 全体をマージしたものを返せるQueue. 半群が乗る.
[使用例]
QueueAggregation swag([](int a, int b){ return min(a, b); });   // minでマージする
swag.push(x);                                                   // xをpush
swag.pop();                                                     // queueからpop
swag.query();                                                   // 全体をマージしたものを返す
*/