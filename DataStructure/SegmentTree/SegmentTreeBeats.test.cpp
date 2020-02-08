#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include <bits/stdc++.h>
using namespace std;

#include "SegmentTreeBeats.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<long long> A(N);
    for (auto& e: A) cin >> e;

    SegmentTreeBeats seg(N, A);

    while (Q--) {
        int T, L, R;
        cin >> T >> L >> R;
        if (T == 0) {
            long long B;  cin >> B;
            seg.update_min(L, R, B);
        } else if (T == 1) {
            long long B;  cin >> B;
            seg.update_max(L, R, B);
        } else if (T == 2) {
            long long B;  cin >> B;
            seg.add_val(L, R, B);
        } else {
            cout << seg.query_sum(L, R) << endl;
        }
    }
}
