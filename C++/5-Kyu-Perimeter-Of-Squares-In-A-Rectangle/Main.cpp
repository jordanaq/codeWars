#include <iostream>


typedef unsigned long long ull;
class SumFct {
	public:
		static ull perimeter(int n) {
			ull first = 0;
			ull second = 1;
			ull sum = 0;

			for (int i = 0; i <= n; sum += first, i++) {
				ull temp = first + second;
				first = second;
				second = temp;
			}
			
			return sum * 4;
		}

};

int main() {
	std::cout << SumFct::perimeter(5) << "\t" << SumFct::perimeter(7) << "\t" << SumFct::perimeter(20) << "\t" << SumFct::perimeter(30) << std::endl;
}
