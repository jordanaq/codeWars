package main

import (
	"fmt"
	"strings"
)

func GetCount(str string) (count int) {
	for _, letter := range str { //Gets each rune in the string
		if (strings.ContainsRune("aeiou", letter)) { //Checks if the rune is a vowel
			count++ //Increases count var
		}
	}

	return count
}

func main() {
	fmt.Println(GetCount("abracadabra") == 5)
}
