#include <tuple>
#include <list>
#include <string>
#include <iostream>


bool compareTuple(std::tuple<std::string, int> first, std::tuple<std::string, int> second) {
  if (std::get<1>(first) == std::get<1>(second))
    return std::get<0>(first) < std::get<0>(second);

  else
    return std::get<1>(first) < std::get<1>(second);
}


class WeightSort
{
private:
  std::list<std::tuple<std::string, int>> nums;


  void addNum(std::string& num) {
    int temp = 0;

    for (const char& i : num) {
      temp += i - '0';
    }

    nums.push_back(std::make_tuple(num, temp));
  }


  void addString(const std::string& strng) {
    std::string word = "";


    for (int i = 0; i < strng.length(); i++) {
      if (strng[i] == ' ') {
        addNum(word);
        word = "";
      }

      else if (i == strng.length() - 1) {
        word.push_back(strng[i]);
        addNum(word);
        word = "";
      }

      else
        word.push_back(strng[i]);
    }
  }

  void sortWeight() {
    nums.sort(compareTuple);
  }

  std::string toString() {
    std::string temp = "";
    for (std::tuple<std::string, int>& i : nums)
      temp.append(std::get<0>(i) + " ");

    temp.pop_back();
    return temp;
  }


public:
  static std::string orderWeight(const std::string& strng) {
    if (strng.empty())
      return "";

    WeightSort temp;

    temp.addString(strng);
    temp.sortWeight();
    return temp.toString();
  }

};


int main() {
  WeightSort arr;
  std::cout << arr.orderWeight("103 123 4444 99 2000") << std::endl;
  std::cout << arr.orderWeight("2000 10003 1234000 44444444 9999 11 11 22 123") << std::endl;
  std::cout << arr.orderWeight("") << std::endl;
  return 0;
}
