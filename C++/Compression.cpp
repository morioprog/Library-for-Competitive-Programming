/*
・座標圧縮
  > O(NlogN)
[備考] 各数字の対応関係が欲しいときは, 引数にmapを入れてコメントアウトを外す.
[使用例]
1. 引数にmapを入れない場合
vl com = compress(v);
2. 引数にmapを入れる場合
map<ll,int> rev;
vl com = compress(v, rev);
*/

// template<typename T> vector<T> compress(vector<T> ord, map<T,int> &rev) {
template<typename T> vector<T> compress(vector<T> ord) { map<T,int> rev;
  vector<T> com = ord;
  sort(com.begin(), com.end());
  com.erase(unique(com.begin(), com.end()), com.end());
  for (int i = 0; i < com.size(); ++i) rev[com[i]] = i;
  vector<T> ret; for (auto& e : ord) ret.emplace_back(rev[e]);
  return ret;
}
