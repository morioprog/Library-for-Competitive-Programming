template<typename T = int_fast64_t> struct CumulativeSum {
    vector< T > data;
    CumulativeSum(int sz, T init = 0) : data(sz, init) {}
    void add(int k, T x) {
        data[k] += x;
        // data[k] ^= x;
    }
    void build() {
        for (int i = 1; i < (int)data.size(); ++i) {
            data[i] += data[i - 1];
            // data[i] ^= data[i - 1];
        }
    }
    T query(int k) {
        if (k < 0) return 0;
        return data[min(k, (int)data.size() - 1)];
    }
    T query(int l, int r) {
        T ret = (data[min(r - 1, (int)data.size() - 1)]);
        if (l > 0) ret -= (data[min(l - 1, (int)data.size() - 1)]);
        // if (l > 0) ret ^= (data[min(l - 1, (int)data.size() - 1)]);
        return ret;
    }
    T operator[](const int &k) {
        return data[k];
    }
    void debug() {
        for (int i = 0; i < (int)data.size(); ++i) cerr << data[i] << ' ';
        cerr << endl;
    }
};

/*
・1次元累積和
    >     build O(N)
    > add,query O(1)
[応用例] 加減算をそれぞれXORにすると, 累積XOR
[使用例]
CumulativeSum<int> acc(N);  // 要素数Nの累積和用の配列
acc.add(k, x);              // 要素kに値xを加える
acc.build();                // 累積和を取る
acc.query(k);               // 閉区間[0, k]の和
acc.query(l, r);            // 半開区間[l, r)の和
acc[k];                     // 要素kを取得
*/
