#include <iostream>
#include <vector>
#include <cmath>

#include <functional>



template<class T>
struct MagicCompare {
    typedef MagicCompare<T> MT;

    template<class S>
    friend std::ostream& operator <<(std::ostream&, MT);

    T val;
    std::function<bool()> prev {[](){ return true;}};


    MagicCompare()=delete;
    MagicCompare(T v): val { v }, prev {[](){ return true;} } { }
    MagicCompare(T v, std::function<bool()> f): val { v }, prev { f } { }

    MT operator ==(MT o) { return {o.val, [&](){return ((o.val)==val)&&o.prev()&&prev();} }; }
    MT operator !=(MT o) { return {o.val, [&](){((o.val)!=val)||(!o.prev())||(!prev());} };}
    MT operator <(MT o) { return {o.val, [&](){return (val<(o.val))&&prev()&&o.prev();}};}
    MT operator >(MT o) { return {o.val, [&](){return (val>(o.val))&&prev()&&o.prev();}};}
    MT operator <=(MT o) { return {o.val, [&](){return (val<=(o.val))&&prev()&&o.prev();}};}
    MT operator >=(MT o) { return {o.val, [&](){return (val>=(o.val))&&prev()&&o.prev();}};}

    operator T() { return val; }
    operator bool() { return prev(); }
    void operator ++() { ++val; }
    void operator +=(T v) { val+=v; }
    MT operator *(MT o) { return { val*o.val, [&](){return prev()&&o.prev;} }; }
};

template<typename T>
std::ostream& operator << (std::ostream& os, MagicCompare<T> g) { os << g.val; return os; }

template<typename T, typename S = T> bool operator==(MagicCompare<T> i, S g) {return i.prev()&&(i.val==g);}
template<typename T, typename S = T> bool operator!=(MagicCompare<T> i, T g) {return !(i==g);}
template<typename T, typename S = T>  bool operator==(S i, MagicCompare<T> g) {return g.prev()&&(g.val==i);}
template<typename T, typename S = T>  bool operator!=(S i, MagicCompare<T> g) {return !(i==g);}

template<typename T> MagicCompare<T> operator <(T i, MagicCompare<T> g) { return { g.val, [&](){ return g.prev()&&(i<g.val); } }; }
template<typename T> MagicCompare<T> operator >(T i, MagicCompare<T> g) { return { g.val, [&](){ return g.prev()&&(i>g.val); } }; }
template<typename T> MagicCompare<T> operator <=(T i, MagicCompare<T> g) { return { g.val, [&](){ return g.prev()&&(i<=g.val); } }; }
template<typename T> MagicCompare<T> operator >=(T i, MagicCompare<T> g) { return { g.val, [&](){ return g.prev()&&(i>=g.val); } }; }

template<typename T> bool operator <(MagicCompare<T> i, T g) { return i.prev()&&(i.val<g); }
template<typename T> bool operator >(MagicCompare<T> i, T g) { return i.prev()&&(i.val>g); }
template<typename T> bool operator <=(MagicCompare<T> i, T g) { return i.prev()&&(i.val<=g); }
template<typename T> bool operator >=(MagicCompare<T> i, T g) { return i.prev()&&(i.val>=g); }

template<typename T> MagicCompare<T> operator *(T i, MagicCompare<T> g) {return {g.val*i, g.prev};}
template<typename T> MagicCompare<T> operator *(MagicCompare<T> i, T g) {return {g*i.val, i.prev};}


int main() {
    using Integer = MagicCompare<int>;
    //std::vector<int> interval;
    /** output natural numbers i,
     *  with 0 < i < 5, 5 < i^2 < 17

    using Integer = MagicCompare<int>;
    std::vector<int> interval;
    for (Integer i = 0; i < 5; ++i) {
        if (5 < (i * i) < 17) {
            std::cout<<i<<std::endl;
            interval.push_back(i);
        }
    }
    for (int x = 3; x <= 4; x += 1) {
        std::cout<< (x == interval[x - 3]) << std::endl;
    }*/
    Integer a = 3;
    std::cout<< (4 < a);

    /*using Float = MagicCompare<double>;
    std::vector<double> interval;
    for (Float x = 0; x < 1.0; x += 0.01) {
        if (sin(x) < (exp(x) * x) < cos(x)) {
            interval.push_back(x);
        }
    }
    for (int x = 1; x <= 51; x += 1) {
        std::cout << (x == round(100 * interval[x - 1]));
    }*/

    return 0;
}
