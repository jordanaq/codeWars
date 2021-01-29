#include <utility>
#include <vector>
#include <cmath>

class SumSquaredDivisors
{
public:
  static std::vector<std::pair<long long, long long>> listSquared(long long m, long long n) {
    std::vector<std::pair<long long, long long>> result;
      
    for (long long i = m, iSum = getSqDivisorSum(i); i < n; i++, iSum = getSqDivisorSum(i))
      if (floor(sqrt(iSum)) == sqrt(iSum)) result.push_back(std::make_pair(i, iSum));
    
    return result;
  };
  
  private:
    static long long getSqDivisorSum(long long x) {
      long long sum = 0;
      
      for (long long i = 1; i <= x / 2; i++)
        if (fmod(x, i) == 0) sum += i*i;
      
      return sum + x*x;
    };
};
