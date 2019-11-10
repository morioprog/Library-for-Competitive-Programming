inline uint_fast64_t toInt(string s) {
    uint_fast64_t v;
    istringstream sin(s);
    sin >> v;
    return v;
}
template<typename T> inline string toString(T x) {
    ostringstream sout;
    sout << x;
    return sout.str();
}
template<typename T> inline void ntos(const T &n, string &s) {
    stringstream stream;
    stream << n;
    stream >> s;
}
template<typename T> inline void ston(const string &s, T &n) {
    stringstream stream(s);
    stream >> n;
}

/*
・文字列と整数同士の変換
[使用例]
toInt("222") / 2    // == 111
toString(222) + 2   // == 224
int n = 9876; string t; ntos(n, t);     // t == "9876"
string s = "1234"; int m; ston(s, m);   // m == 1234
*/
