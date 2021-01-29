package main

import (
	"fmt"
	"strings"
	"strconv"
)

func is_valid_ip(ip string) bool {
	var nums = strings.Split(ip, ".")	//Split the IP into parts at .

	if len(nums) != 4 {	//Checks if there are not 4 parts, catches if the ip used the wrong seperator too
		return false
	}

	for _, i := range nums {	//Iterates through the list of nums, ignoring the index
		if len(i) > 1 && strings.HasPrefix(i, "0") {	//Checks if the first digit of a multi-digit num is 0
			return false
		} else if g, err := strconv.Atoi(i); g < 0 || g > 255 || !(err == nil) {	//Checks if the number is a number and if it's between 0 and 255
			return false
		}
	}

	return true	//returns true if all checks pass
}

func main() {
	fmt.Println(is_valid_ip("12.255.56.1"))
	fmt.Println(is_valid_ip(""))
	fmt.Println(is_valid_ip("abc.def.ghi.jkl"))
	fmt.Println(is_valid_ip("123.456.789.0"))
}
