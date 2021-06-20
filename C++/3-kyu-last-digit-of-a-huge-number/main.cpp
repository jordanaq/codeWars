#include <list>
#include <cmath>
#include <iostream>

//using namespace std;

#include <string>

int last_digit(const std::string &str1, const std::string &str2) {
    if (str2=="0") return 1;

    int base { *--str1.end() - '0' }, exp { (str2.size() == 1) ?
            *--str2.end() - '0' :
            std::stoi(str2.substr(str2.size()-2, 2)) };

    std::cout<< (long long) std::pow(base, 4 + exp%4) % 10LL;
}

int last_digit(std::list<int> array) {
    if (array.empty()) return 1;

    int last_digit = *std::end(array);
    for (auto i = --std::end(array); i != std::begin(array); i++) {
        if (!last_digit) last_digit = *i;

        last_digit = pow(*i,last_digit%4);
    }

    return last_digit % 10;
}

int main() {
    std::cout <<
              "last_digit({})" << '\t' << (last_digit({})==1) << std::endl <<
              "last_digit({0, 0})" << '\t' << (last_digit({0, 0})==1) << std::endl <<
              "last_digit({0,0,0}) "<< '\t' << (last_digit({0,0, 0})==0) << std::endl <<
              "last_digit({1,2})" << '\t' << (last_digit({01, 2})==1) << std::endl <<
              "last_digit({3,4,5})" << '\t' << (last_digit({3, 4, 5})==1) << std::endl <<
              "last_digit({4,3,6})" << '\t' << (last_digit({4,3,6})==4) << std::endl <<
              "last_digit({7,6,21})"<< '\t' << (last_digit({7,6,21})==1) << std:: endl <<
              "last_digit({12,30,21})"<< '\t' << (last_digit({12,30,21})==6) << std::endl <<
              "last_digit({2,2,2,0})"<< '\t' << (last_digit({2,2,2,0})==4) << std:: endl <<
              "last_digit({937640,767456,981242})"<< '\t' << (last_digit({7,6,21})==0) << std::endl<<
              "last_digit({123232,694022,140249})"<< '\t' << (last_digit({7,6,21})==6) << std::endl<<
              "last_digit({499942,898102,846073})"<< '\t' << (last_digit({7,6,21})==6) << std::endl;
}