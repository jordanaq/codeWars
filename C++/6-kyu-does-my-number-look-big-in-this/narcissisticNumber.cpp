#include <math.h>

bool narcissistic( int value ){
  std::string number = std::to_string(abs(value));
  int sum = 0;

  for (int i = 0; i < number.length(); sum += pow(number[i] - '0', number.length()), i++);
  return sum == value;
}
