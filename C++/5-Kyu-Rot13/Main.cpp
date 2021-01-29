#include <iostream>
#include <string>
using namespace std;

string rot13(string msg) {
	for (char& letter : msg) // Iterates through every index of msg
		if (isalpha(letter))
			letter = ((letter >= 'a') ? (((letter - 'a' + 13) % 26) + 'a') : (((letter - 'A' + 13) % 26 ) + 'A')); // Subtracts ascii of 'a' or 'A' to get pos of letter then adds 13 to it, modulus in case of last 12 letters then adds 'a' or 'A' back to get ascii of new char	

	return msg;
}

int main() {
	cout << rot13("test") << " " << "grfg\n";
	cout << rot13("Test") << " " << "Grfg\n";
	cout << rot13("AbCd") << " " << "NoPq\n";
}
