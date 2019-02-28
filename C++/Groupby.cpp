/*
・groupby
[備考] stringについて用いる場合は, vector<char>に以下のようにして一旦移し替える.
      string str;
      vector<char> vec(str.begin(), str.end());
[使用例]
vector<int> vec = {1, 2, 2, 3, 3, 3, 3};
auto gb = groupby(vec);                       // {{1, 1}, {2, 2}, {3, 4}}
*/

template<typename T> vector< pair< T, int > > groupby(const vector< T > &vec) {
  vector< pair< T,int > > ret;
  int piv = -1;
  for (auto& e: vec) {
    if (piv == -1 || ret[piv].first != e) ++piv, ret.emplace_back(make_pair(e, 1));
    else ++(ret[piv].second);
  }
  return ret;
}
