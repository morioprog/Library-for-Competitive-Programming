#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <bits/stdc++.h>
using namespace std;

#include "../../DataStructure/SparseTable.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for (auto& e: A) cin >> e;
    SparseTable<int> st(A);

    while (Q--) {
        int L, R;
        cin >> L >> R;
        cout << st.query(L, R) << endl;
    }
}
