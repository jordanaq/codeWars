#include <string>
#include <iostream>

std::string format_duration(int seconds) {
	if (seconds == 0) 
		return "now";

	std::string result = "";
	
	if (seconds > 31536000) {
		int years = seconds / 31536000;
		seconds %= 31536000;
		result += std::to_string(years) + " " + ((years > 1) ? ("years") : ("year"));
	}

	if (seconds > 86400) {
		int days = seconds / 86400;
		seconds %= 86400;

		if (!(result.empty()))
			result += ((seconds == 0) ? (" and ") : (", "));
		result += std::to_string(days) + " " + ((days > 1) ? ("days") : ("day"));
	}

	if (seconds > 3600) {
		int hours = seconds / 3600;
		seconds %= 3600;

		if (!(result.empty()))
			result += ((seconds == 0) ? (" and ") : (", "));
		result += std::to_string(hours) + " " + ((hours > 1) ? ("hours") : ("hour"));
	}

	if (seconds > 60) {
		int minutes = seconds / 60;
		seconds %= 60;

		if (!(result.empty()))
			result += ((seconds == 0) ? (" and ") : (", "));
		result += std::to_string(minutes) + " " + ((minutes > 1) ? ("minutes") : ("minute"));
	}

	if (seconds != 0)
		if (result.empty())
			result += std::to_string(seconds) + " " + ((seconds > 1) ? ("seconds") : ("second"));
		else
			result += " and " + std::to_string(seconds) + " " + ((seconds > 1) ? ("seconds") : ("second"));
	
	return result;
}

int main() {
	std::cout << format_duration(0) << std::endl;
	std::cout << format_duration(1) << std::endl;
	std::cout << format_duration(62) << std::endl;
	std::cout << format_duration(120) << std::endl;
	std::cout << format_duration(3662) << std::endl;
	std::cout << format_duration(32000000) << std::endl;
}
