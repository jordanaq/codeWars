#include <iostream>
//#include <cmath>
//#include <string>


class PrimeDecomp
{
public:
    static std::string factors(int lst) {   //Returns a string including all prime factors of lst
      std::string factors = "";   //Creates an empty string to append new factors to

      for (int i = 2; lst > 1; i++) {   //Increments i until it's looped through every factor of lst
        if (lst % i == 0) {   //Skips i if it is not a factor
          int count = 0;    //keeps track of how many times i goes into lst

          while (lst % i == 0) {
            count++;
            lst /= i;   //Divides i into lst every time it can
          }

          if (count > 1)    //Adds proper format into factors
            (factors.append("(" + std::to_string(i) + "**" + std::to_string(count) + ")"));
          else
            (factors.append("(" + std::to_string(i) + ")"));
          }
      }

      return factors;
    }
};


int main() {
  std::cout << PrimeDecomp::factors(86240) << std::endl;

  return 0;
}
