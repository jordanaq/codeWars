package main

import "fmt"

func MakeNegative(x int) (result int) {
	if x > 0 {
		return -x
	} else {
		return x
	}
}

func main() {
	fmt.Println(MakeNegative(5), MakeNegative(-1), MakeNegative(0))
}
