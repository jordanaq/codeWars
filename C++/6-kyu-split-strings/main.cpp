#include <string>
#include <vector>

std::vector<std::string> solution(const std::string &s) {
  std::vector<std::string> result = {};   //Declares an empty vector to append to

  for(int i = 0; i < s.length(); i += 2) {
    (i == s.length() - 1) ? (result.push_back({s[i], '_'})) : (result.push_back(s.substr(i, 2)));   //pushes back a substring of s and adds _ if last index and odd length
  }

  return result;
}
