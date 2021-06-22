#include <iostream>

template<class T>
class MagicCompare {
    public:

};

int main() {
    using Integer = MagicCompare<int>;
    //std::vector<int> interval;
    /** output natural numbers i,
     *  with 0 < i < 5, 5 < i^2 < 17
     */
    for (Integer i = 0; i < 5; ++i) {
        if (5 < (i * i) < 17) {
            /* will output 3 and 4. */
            std::cout << i << std::endl;
        }
    }

    return 0;
}
