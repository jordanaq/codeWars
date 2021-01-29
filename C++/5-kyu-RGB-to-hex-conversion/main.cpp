#include <string>
#include <cmath>

std::string intToHex(int);

class RGBToHex
{
  public:
    static std::string rgb(int r, int g, int b) {
      return intToHex(r) + intToHex(g) + intToHex(b);
    }
};


std::string intToHex(int n) {
  std::string hex = "  ";

  (n / 16 >= 10) ? (hex[0] = n / 16 + 55) : (hex[0] = n / 16 + 48);
  (n % 16 >= 10) ? (hex[1] = n % 16 + 55) : (hex[1] = n % 16 + 48);

  return hex;
}
