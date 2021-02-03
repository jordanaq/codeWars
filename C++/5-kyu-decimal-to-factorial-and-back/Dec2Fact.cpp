#include <string>

class Dec2Fact
{
public:
    static std::string dec2FactString(long long nb);
    static long long factString2Dec(const std::string &str);
};