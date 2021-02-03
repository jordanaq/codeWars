#include <iostream>
#include "Dec2Fact.cpp"

int main() {
    //  dec2FactString tests
    std::cout << "dec2FactString(2982) = " << Dec2Fact::dec2FactString(2982) << " and " <<
            ((Dec2Fact::dec2FactString(2982) == "4041000") ? "IS" : "ISN'T") << " 4041000." << std::endl;
    std::cout << "dec2FactString(463) = " << Dec2Fact::dec2FactString(463) << " and " <<
            ((Dec2Fact::dec2FactString(463) == "341010") ? "IS" : "ISN'T") << " 341010." << std::endl;

    //  factString2Dec tests
    std::cout << "factString2Dec(\"4041000\") = " << Dec2Fact::factString2Dec("4041000") << " and " <<
              ((Dec2Fact::factString2Dec("4041000") == 2982) ? "IS" : "ISN'T") << " 2982." << std::endl;
    std::cout << "factString2Dec(\"341010\") = " << Dec2Fact::factString2Dec("341010") << " and " <<
              ((Dec2Fact::factString2Dec("4041000") == 463) ? "IS" : "ISN'T") << " 463." << std::endl;

    return 0;
}
