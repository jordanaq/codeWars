#include <cmath>
#include <string>

class DigPow
{
  public:
    static int digPow(int n, int p) {
      std::string num = std::to_string(n);    //Changed the int into a string to easily isolate digits
      int sum = 0;


      for (int i = 0; i < num.length(); i++)
        sum += pow(num[i] - 48, p + i);   //added the result of each character to incrementing powers to sum

      return (sum % n == 0) ? (sum / n) : (-1);   //returned the quotient of sum and n if n is a factor and returned -1 if not
    };
};
