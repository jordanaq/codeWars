#include <iostream>
#include <unordered_set>
#include <vector>

using ull = unsigned long long;

std::unordered_set <int> products;
int sumVector(std::vector <int> &);

/*ull exp_sum(unsigned int n) {
  int count = 1;

  for (int i = 1; i <= n; i++) {
      std::vector<int> nums(i);

      for (nums[0] += n - i; nums[0] > 1; nums[0]--) {
        for (int g = 1; g <= nums[0]; g++)
      }
    }
  }

  return count;
}


int sumVector(std::vector <int> &arr) {
  int sum = 0;

  for (const auto& i : arr) {
    sum += i;
  }

  return sum;
}*/




int possibleSums(int num, int slots) {
  if (slots == 1) return 1;

  else {
    int count = 0;

    for (int i = 1; i < num + 1 - slots; i++) {
      count += possibleSums(num - i, slots - 1);
    }
  }
}

ull exp_sum(unsigned int n) {
  int count = 0;

  for (int i = 1; i <= n; i++) {
    count += possibleSums(n, i);
  }

  return count;
}


int main() {
  for (int i = 9; i > 0; i--)
    std::cout << i << " -- " << exp_sum(i) << std::endl;
}
