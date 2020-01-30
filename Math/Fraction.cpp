template<typename T> struct Fraction {
    T numer, denom;
    T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
    Fraction(T n = 0, T d = 1) {
        T g = gcd(n, d);
        assert(d != 0);
        numer = n / g, denom = d / g;
        if (denom < 0) numer *= -1, denom *= -1;
    }
    Fraction operator+(const Fraction &f) const { return Fraction(numer * f.denom + denom * f.numer, denom * f.denom); }
    Fraction operator-(const Fraction &f) const { return Fraction(numer * f.denom - denom * f.numer, denom * f.denom); }
    Fraction operator*(const Fraction &f) const { return Fraction(numer * f.numer, denom * f.denom); }
    Fraction operator/(const Fraction &f) const { return Fraction(numer * f.denom, denom * f.numer); }
    Fraction &operator+=(const Fraction &f) { return *this = *this + f; }
    Fraction &operator-=(const Fraction &f) { return *this = *this - f; }
    Fraction &operator*=(const Fraction &f) { return *this = *this * f; }
    Fraction &operator/=(const Fraction &f) { return *this = *this / f; }
    Fraction operator~() const { return Fraction(denom, numer); }
    bool operator==(const Fraction &f) const { return numer == f.numer and denom == f.denom; }
    bool operator!=(const Fraction &f) const { return numer != f.numer  or denom != f.denom; }
    bool operator< (const Fraction &f) const { return numer * f.denom <  f.numer * denom; }
    bool operator<=(const Fraction &f) const { return numer * f.denom <= f.numer * denom; }
    bool operator> (const Fraction &f) const { return numer * f.denom >  f.numer * denom; }
    bool operator>=(const Fraction &f) const { return numer * f.denom >= f.numer * denom; }
    explicit operator T()      const { assert(denom == 1); return numer; }
    explicit operator double() const { return (double) numer / denom; }
    friend ostream &operator<<(ostream &os, const Fraction <T> &f) {
        return os << f.numer << " / " << f.denom;
    }
};

/*
・Fraction
[備考] 分数演算のための構造体
[使用例]
Fraction<int> f(2, 6);      // 2/6 = 1/3の値を持つ
double(f);                  // 0.3333333
*/
