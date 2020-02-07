#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <bits/stdc++.h>
using namespace std;

#include "UnionFind.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    while (Q--) {
        int T, U, V;
        cin >> T >> U >> V;
        if (T == 0) uf.unite(U, V);
        else        cout << uf.same(U, V) << endl;
    }
}
