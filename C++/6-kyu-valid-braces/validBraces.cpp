#include <string>

bool valid_braces(std::string braces)
{
  std::string order = "";

  for (const char& i : braces) {
    switch (i) {
      case ')': if (!( '(' == order.back() )) return false; order.pop_back(); break;
      case ']': if (!( '[' == order.back() )) return false; order.pop_back(); break;
      case '}': if (!( '{' == order.back() )) return false; order.pop_back(); break;
      default: order += i;
    }
  }
  return true;
}
