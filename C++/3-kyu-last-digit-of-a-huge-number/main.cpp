#include <list>
#include <cmath>
#include <iostream>
#include <iomanip>

//using namespace std;

#include <string>

int last_digit(const std::string &str1, const std::string &str2) {
    if (str2=="0") return 1;

    int base { *--str1.end() - '0' }, exp { (str2.size() == 1) ?
            *--str2.end() - '0' :
            std::stoi(str2.substr(str2.size()-2, 2)) };

    return (long long) std::pow(base, 4 + exp%4) % 10LL;
}

//inline auto iPow = [](long long i, long long g) -> long long { return (!i && !g) ? 1 : std::pow(i, g); };
typedef unsigned long long ll;

int last_digit(std::list<int> array) {
    if (array.empty()) return 1;
    else if (auto a = array.begin(); *a%10==1 || *a%10==5 || *a%10==6) return *a%10;

    auto m = std::modulus<ll>();

    ll exp { (ll) array.back() };
    for (auto i = ----array.end(); i != array.begin(); i--) {std::cout<<"exp: "<<exp<<"\ti: "<<*i<<"\t";
        if (exp)
            exp = (exp<=2)&&*i%4!=2 ? m(*i,4)*std::pow(m(*i,4), (3+exp)%4) : 0;
        else exp = 1;
    }

    std::cout << "\texp:" << exp << '\t';
    return array.front()||exp ? m(std::pow(m(array.front(),10), 4+m(exp,4)),10) : 1;
}

int main() {
    std::cout <<
              "last_digit({})" << "\nres:" << (last_digit({})==1) << '.' << std::endl << std::endl <<
              "last_digit({0, 0})" << "\nres:" << (last_digit({0, 0})==1) << '.' << std::endl << std::endl <<
              "last_digit({0,0,0}) "<< "\nres:" << (last_digit({0,0,0})==0) << '.' << std::endl << std::endl <<
              "last_digit({1,2})" << "\nres:" << (last_digit({01, 2})==1) << '.' << std::endl << std::endl <<
              "last_digit({3,4,5})" << "\nres:" << (last_digit({3, 4, 5})==1)<< '.'  << std::endl << std::endl <<
              "last_digit({4,3,6})" << "\nres:" << (last_digit({4,3,6})==4) << '.' << std::endl << std::endl <<
              "last_digit({7,6,21})"<< "\nres:" << (last_digit({7,6,21})==1) << '.' << std:: endl << std::endl <<
              "last_digit({12,30,21})"<< "\nres:" << (last_digit({12,30,21})==6)<< '.'  << std::endl << std::endl <<
              "last_digit({2,2,2,0})"<< "\nres:" << (last_digit({2,2,2,0})==4) << '.' << std:: endl << std::endl <<
              "last_digit({937640,767456,981242})"<< "\nres:" << (last_digit({7,6,21})==0)<< '.'  << std::endl<< std::endl <<
              "last_digit({123232,694022,140249})"<< "\nres:" << (last_digit({7,6,21})==6) << '.' << std::endl<< std::endl <<
              "last_digit({499942,898102,846073})"<< "\nres:" << (last_digit({7,6,21})==6)<< '.'  << std::endl;
}