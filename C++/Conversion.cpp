/*
・文字列と整数同士の変換
[使用例]
cout << toInt("222") / 2 << endl;   // 111
cout << toString(222)+2 << endl;    // 224
ll n = 9876; string t;
ntos(n,t);  // t = "9876"
string s = "1234"; ll m;
ston(s,m);  // m = 1234
*/
inline ll toInt(string s){ll v;istringstream sin(s);sin >> v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout << x;return sout.str();}
template<typename T> inline void ntos(const T &n,string &s){stringstream stream; stream << n; stream >> s;}
template<typename T> inline void ston(const string &s,T &n){stringstream stream(s); stream >> n;}
