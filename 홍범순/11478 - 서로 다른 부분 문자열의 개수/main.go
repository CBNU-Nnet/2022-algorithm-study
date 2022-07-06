package main

import (
	"fmt"
)

func main() {
	var input string
	fmt.Scanf("%s", &input)

	data_array := make(map[string]bool)
	var substr string = ""

	for i := 0; i < len(input); i++ {
		for j := i; j < len(input); j++ {
			substr = input[i : j+1]
			data_array = add(data_array, substr)
		}
	}

	fmt.Println(len(data_array))
}

func add(s map[string]bool, v string) map[string]bool {
	s[v] = true
	return s
}
