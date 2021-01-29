# include <string>
std::string disemvowel(std::string str) {
  std::string output =  "";

  for (const char& i : str) {
    bool vowell = false;
    for (const char& g : {'a', 'e', 'i', 'o', 'u'}) {
      if (std::tolower(i) == g) vowell = true;
    }
    if (!(vowell)) output += i;
  }

  return output;
}
